
/*
 * context_switch.s
 *
 * Created: 3/31/2018 11:44:15 AM
 *  Author: sene
 */

.syntax unified

.global SysTick_Handler
.global Pend_SV_Handler
.global sched_context_switch
.global up_get_irq_number

.extern sched_get_next_task
.extern sched_preempt_task

.section .text

/* We are using floating point stacking so here is the order of the registers saved:
 *   _____
 *      | FPCSR | <---- Stack grows downwards so here are big address - 
 *      | S15   |       before stacking
 *      | S14   |
 *      | S13   |
 *      | S12   |
 *      | S11   |
 *      | S10   |
 *      | S9    |
 *      | S8    |
 *      | S7    |
 *      | S6    |
 *      | S5    |
 *      | S4    |
 *      | S3    |
 *      | S2    |
 *      | S1    |
 *      | S0    |
 *	| xPSR |  
*	|  PC  |      
 *	|  LR  |
 *	| R12  |
 *	|  R3  |
 *	|  R2  |
 *	|  R1  |
 *	|  R0  |
 *   ______	 <---- Stack ptr after stacking
 *
 *  100 bytes stored by the interrupt controller to save context.
 */

/* We also need to store :
 *
 * This will be placed below the R0 from the ISR stacking
 *
 * R4
 * R5
 * R6
 * R7
 * R8
 * R9
 * R10
 * R11
 */


.align 4
.thumb_func

SysTick_Handler:
	stmdb sp!, {lr}					    // Store the link register on the stack
	bl sched_get_current_task			    // Get current TCB address in R0
	ldmia sp!, {lr}					    // Restore the link register from the stack

	cmp r0, #0					    // Verify NULL pointer TCB
	beq SysTick_Handler_ret			            // Handle NULL pointer to return from handler
	ldr r1, [r0, #4]				    // Load the state of the task
	cmp r1, 2                   			// Is this task waiting for sem ?
	beq sched_do_switch         			//
	cmp r1, 3                   			// Is this task shutting down ?
	beq sched_do_switch         			//

	cmp r1, 1					// Is this task currently running ?
	bne SysTick_Handle_context_switch

	/* Task is running so switch it to (not running) READY */

	mov r1, #0
	str r1, [r0, #4]

	/* Save the R4-R11 registers on the stack (we are on the running TCB stack) */

	push {R4-R11}

	/* Save the SP in the TCB */

	mov r1, sp
	str r1, [r0, #16]

	/* Get the next task ptr in R0 */

	stmdb sp!, {lr}					    // Store the link register on the stack
	bl sched_get_next_task				    // Get the next TCB address in R0
	ldmia sp!, {lr}					    // Restore the link register from the stack

	cmp r0, #0					    // Verify NULL pointer TCB
	beq SysTick_Handler_ret			            // Handle NULL pointer to return from handler

SysTick_Handle_context_switch:
	mov r1, #1
	str r1, [r0, #4]				// Switch task state to running
	mov r5, r0			                // Save task TCB ptr in r5
	add r5, #16			                // Get the address of the sp from TCB struct in r5

	/* The SP of the new task should have already some stacking values */

	ldr r0, [r5]					// Set SP to point to the task SP
	mov sp, r0					//
	pop {R4-R11}                			// Pop R4-R11

SysTick_Handler_ret:
	bx lr						// Return from handler

sched_context_switch:
  /* Stack all the registers */
  push {r0}
  mrs r0, xpsr
  push {r0}
  ldr r0, =ret_from_cs
  push {r0}
  push {lr}
  push {r12}
  push {r3}
  push {r2}
  push {r1}
  ldr r0, [sp, #28]
  push {r0}
  cpsie i

repeat:
  b repeat
ret_from_cs:
  pop {r0}
  bx lr

sched_do_switch:
  ldr r0, [sp, #28]    /* Load the XPSR in r0 - PC is at offset 60 from SP */
  str r0, [sp, #64]
  add sp, #36

  /* Stack extra registers */
  push {R4-R11}

  /* Save the SP in the TCB structure */

  stmdb sp!, {lr}
  bl sched_preempt_task
  ldmia sp!, {lr}

  cmp r0, #0
  beq sched_context_switch_ret

  /* Save the SP in the TCB */

  mov r1, sp
  str r1, [r0, #16]

	stmdb sp!, {lr}					    // Store the link register on the stack
	bl sched_get_current_task		// Get the next TCB address in R0
	ldmia sp!, {lr}					    // Restore the link register from the stack

  cmp r0, #0
  beq sched_context_switch_ret

	mov r1, #1
	str r1, [r0, #4]				// Switch task state to running
	mov r5, r0						  // Save task TCB ptr in r5
	add r5, #16						  // Get the address of the sp from TCB struct in r5

  /* The SP of the new task should have already some stacking values */

	ldr r0, [r5]							  // Set SP to point to the task SP
	mov sp, r0								  //
  pop {R4-R11}                // Pop R4-R11

sched_context_switch_ret:
  bx lr

//  pop {r0}
//  pop {r1}
//  pop {r2}
//  pop {r3}
//  pop {r12}
//  pop {lr}
//
//  /* Save the value of the R0 at SP + 0xC */
//
//  str r0, [sp, #0x8]
//  ldr r0, [sp, #0x4]  /* OLD XPSR */
//  msr xpsr, r0        /* Restore XPSR */
//  add sp, #0x4        /* SP points at XPSR on the stack */
//  ldr r0, [sp, #0x4]  /* Restore R0 */
//  cpsie i
//  ldr pc, [sp, #-0x4]
//

up_get_irq_number:
  mrs r0, ipsr
  bx lr

Pend_SV_Handler:
  nop
  nop
  nop

  b sched_do_switch
  bx lr
