/* Copyright (c) 2015 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */

#include "nrf_drv_gpiote.h"
#include "nrf_drv_common.h"
#include "nrf_drv_config.h"
#include "app_util_platform.h"
#include "nrf_assert.h"

#define FORBIDDEN_HANDLER_ADDRESS ((nrf_drv_gpiote_evt_handler_t)UINT32_MAX)
#define PIN_NOT_USED              (-1)
#define PIN_USED                  (-2)
#define NO_CHANNELS               (-1)
#define SENSE_FIELD_POS           (6)
#define SENSE_FIELD_MASK          (0xC0)

//lint -save -e661
typedef struct
{
    nrf_drv_state_t              state;
    nrf_drv_gpiote_evt_handler_t handlers[NUMBER_OF_GPIO_TE+GPIOTE_CONFIG_NUM_OF_LOW_POWER_EVENTS];
    int8_t                       pin_assignments[NUMBER_OF_PINS];
    int8_t                       handlers_to_pins[GPIOTE_CONFIG_NUM_OF_LOW_POWER_EVENTS];
} gpiote_control_block_t;

static volatile gpiote_control_block_t g_gpio_control_block = {0};

__STATIC_INLINE bool pin_in_use(uint32_t pin)
{
    return (g_gpio_control_block.pin_assignments[pin] != PIN_NOT_USED) ? true : false;
}

__STATIC_INLINE bool pin_in_use_as_non_task_out(uint32_t pin)
{
    return (g_gpio_control_block.pin_assignments[pin] == PIN_USED) ? true : false;
}

__STATIC_INLINE bool pin_in_use_by_te(uint32_t pin)
{
    return (g_gpio_control_block.pin_assignments[pin] >= 0 && g_gpio_control_block.pin_assignments[pin] < NUMBER_OF_GPIO_TE) ? true : false;
}

__STATIC_INLINE bool pin_in_use_by_port(uint32_t pin)
{
    return (g_gpio_control_block.pin_assignments[pin] >= NUMBER_OF_GPIO_TE) ? true : false;
}

__STATIC_INLINE bool pin_in_use_by_gpiote(uint32_t pin)
{
    return (g_gpio_control_block.pin_assignments[pin] >= 0) ? true : false;
}

__STATIC_INLINE void pin_in_use_by_te_set(uint32_t pin,
                                          uint32_t channel_id,
                                          nrf_drv_gpiote_evt_handler_t handler,
                                          bool is_channel)
{
    g_gpio_control_block.pin_assignments[pin] = channel_id;
    g_gpio_control_block.handlers[channel_id] = handler;
    if (!is_channel)
    {
        g_gpio_control_block.handlers_to_pins[channel_id-NUMBER_OF_GPIO_TE] = (int8_t)pin;
    }
}

__STATIC_INLINE void pin_in_use_set(uint32_t pin)
{
    g_gpio_control_block.pin_assignments[pin] = PIN_USED;
}

__STATIC_INLINE void pin_in_use_clear(uint32_t pin)
{
    g_gpio_control_block.pin_assignments[pin] = PIN_NOT_USED;
}

__STATIC_INLINE int8_t channel_port_get(uint32_t pin)
{
    return g_gpio_control_block.pin_assignments[pin];
}

__STATIC_INLINE uint8_t pin_from_port_get(uint32_t port_channel)
{
    return g_gpio_control_block.handlers_to_pins[port_channel];
}

__STATIC_INLINE nrf_drv_gpiote_evt_handler_t channel_handler_get(uint32_t channel)
{
    return g_gpio_control_block.handlers[channel];
}

static int8_t channel_port_alloc(uint32_t pin,nrf_drv_gpiote_evt_handler_t handler, bool channel)
{
    int8_t channel_id = NO_CHANNELS;
    uint32_t i;

    uint32_t start_idx = channel ? 0 : NUMBER_OF_GPIO_TE;
    uint32_t end_idx = channel ? NUMBER_OF_GPIO_TE : (NUMBER_OF_GPIO_TE+GPIOTE_CONFIG_NUM_OF_LOW_POWER_EVENTS);
    //critical section

    for (i = start_idx; i < end_idx; i++)
    {
        if (g_gpio_control_block.handlers[i] == FORBIDDEN_HANDLER_ADDRESS)
        {
            pin_in_use_by_te_set(pin, i, handler, channel);
            channel_id = i;
            break;
        }
    }
    //critical section
    return channel_id;
}

static void channel_free(uint8_t channel_id)
{
    g_gpio_control_block.handlers[channel_id] = FORBIDDEN_HANDLER_ADDRESS;
    if (channel_id >= NUMBER_OF_GPIO_TE)
    {
        g_gpio_control_block.handlers_to_pins[channel_id-NUMBER_OF_GPIO_TE] = (int8_t)-1;
    }
}

ret_code_t nrf_drv_gpiote_init(void)
{
    if (g_gpio_control_block.state != NRF_DRV_STATE_UNINITIALIZED)
    {
        return NRF_ERROR_INVALID_STATE;
    }

    uint8_t i;
    for (i = 0; i < NUMBER_OF_PINS; i++)
    {
        pin_in_use_clear(i);
    }
    for (i = 0; i < (NUMBER_OF_GPIO_TE+GPIOTE_CONFIG_NUM_OF_LOW_POWER_EVENTS); i++)
    {
        channel_free(i);
    }

    nrf_drv_common_irq_enable(GPIOTE_IRQn, GPIOTE_CONFIG_IRQ_PRIORITY);
    nrf_gpiote_int_enable(GPIOTE_INTENSET_PORT_Msk);
    g_gpio_control_block.state = NRF_DRV_STATE_INITIALIZED;

    return NRF_SUCCESS;
}

bool nrf_drv_gpiote_is_init(void)
{
    return (g_gpio_control_block.state != NRF_DRV_STATE_UNINITIALIZED) ? true : false;
}

void nrf_drv_gpiote_uninit(void)
{
    ASSERT(g_gpio_control_block.state!=NRF_DRV_STATE_UNINITIALIZED);

    uint32_t i;
    for (i = 0; i < NUMBER_OF_PINS; i++)
    {
        if (pin_in_use_as_non_task_out(i))
        {
            nrf_drv_gpiote_out_uninit(i);
        }
        else if( pin_in_use_by_gpiote(i))
        {
            /* Disable gpiote_in is having the same effect on out pin as gpiote_out_uninit on
             * so it can be called on all pins used by GPIOTE.
             */
            nrf_drv_gpiote_in_uninit(i);
        }
    }
    g_gpio_control_block.state = NRF_DRV_STATE_UNINITIALIZED;
}

ret_code_t nrf_drv_gpiote_out_init(nrf_drv_gpiote_pin_t pin, nrf_drv_gpiote_out_config_t * p_config)
{
    ASSERT(pin < NUMBER_OF_PINS);
    ASSERT(g_gpio_control_block.state == NRF_DRV_STATE_INITIALIZED);
    ASSERT(p_config);

    ret_code_t result = NRF_SUCCESS;

    if (pin_in_use(pin))
    {
        result = NRF_ERROR_INVALID_STATE;
    }
    else
    {
        if (p_config->task_pin)
        {
            int8_t channel = channel_port_alloc(pin, NULL, true);

            if (channel != NO_CHANNELS)
            {
                nrf_gpiote_task_configure(channel, pin, p_config->action, p_config->init_state);
            }
            else
            {
                result = NRF_ERROR_NO_MEM;
            }
        }
        else
        {
            pin_in_use_set(pin);
        }

        if (result == NRF_SUCCESS)
        {
            nrf_gpio_cfg_output(pin);

            if (p_config->init_state == NRF_GPIOTE_INITIAL_VALUE_HIGH)
            {
                nrf_gpio_pin_set(pin);
            }
            else
            {
                nrf_gpio_pin_clear(pin);
            }
        }
    }

    return result;
}

void nrf_drv_gpiote_out_uninit(nrf_drv_gpiote_pin_t pin)
{
    ASSERT(pin < NUMBER_OF_PINS);
    ASSERT(pin_in_use(pin));

    if (pin_in_use_by_te(pin))
    {
        channel_free((uint8_t)g_gpio_control_block.pin_assignments[pin]);
    }
    pin_in_use_clear(pin);

    nrf_gpio_cfg_default(pin);
}

void nrf_drv_gpiote_out_set(nrf_drv_gpiote_pin_t pin)
{
    ASSERT(pin < NUMBER_OF_PINS);
    ASSERT(pin_in_use(pin));
    ASSERT(!pin_in_use_by_te(pin))

    nrf_gpio_pin_set(pin);
}

void nrf_drv_gpiote_out_clear(nrf_drv_gpiote_pin_t pin)
{
    ASSERT(pin < NUMBER_OF_PINS);
    ASSERT(pin_in_use(pin));
    ASSERT(!pin_in_use_by_te(pin))

    nrf_gpio_pin_clear(pin);
}

void nrf_drv_gpiote_out_toggle(nrf_drv_gpiote_pin_t pin)
{
    ASSERT(pin < NUMBER_OF_PINS);
    ASSERT(pin_in_use(pin));
    ASSERT(!pin_in_use_by_te(pin))

    nrf_gpio_pin_toggle(pin);
}

void nrf_drv_gpiote_out_task_enable(nrf_drv_gpiote_pin_t pin)
{
    ASSERT(pin < NUMBER_OF_PINS);
    ASSERT(pin_in_use(pin));
    ASSERT(pin_in_use_by_te(pin))

    nrf_gpiote_task_enable(g_gpio_control_block.pin_assignments[pin]);
}

void nrf_drv_gpiote_out_task_disable(nrf_drv_gpiote_pin_t pin)
{
    ASSERT(pin < NUMBER_OF_PINS);
    ASSERT(pin_in_use(pin));
    ASSERT(pin_in_use_by_te(pin))

    nrf_gpiote_task_disable(g_gpio_control_block.pin_assignments[pin]);
}

uint32_t nrf_drv_gpiote_out_task_addr_get(nrf_drv_gpiote_pin_t pin)
{
    ASSERT(pin < NUMBER_OF_PINS);
    ASSERT(pin_in_use_by_te(pin));

    nrf_gpiote_tasks_t task = (nrf_gpiote_tasks_t)((uint32_t)NRF_GPIOTE_TASKS_OUT_0+(4*channel_port_get(pin)));
    return nrf_gpiote_task_addr_get(task);
}

void nrf_drv_gpiote_out_task_force(nrf_drv_gpiote_pin_t pin, uint8_t state)
{
    ASSERT(pin < NUMBER_OF_PINS);
    ASSERT(pin_in_use(pin));
    ASSERT(pin_in_use_by_te(pin));
    
    nrf_gpiote_outinit_t init_val = state ? NRF_GPIOTE_INITIAL_VALUE_HIGH : NRF_GPIOTE_INITIAL_VALUE_LOW;
    nrf_gpiote_task_force(g_gpio_control_block.pin_assignments[pin], init_val);
}

void nrf_drv_gpiote_out_task_trigger(nrf_drv_gpiote_pin_t pin)
{
    ASSERT(pin < NUMBER_OF_PINS);
    ASSERT(pin_in_use(pin));
    ASSERT(pin_in_use_by_te(pin));
    
    nrf_gpiote_tasks_t task = (nrf_gpiote_tasks_t)((uint32_t)NRF_GPIOTE_TASKS_OUT_0+(4*channel_port_get(pin)));
    nrf_gpiote_task_set(task);
}

ret_code_t nrf_drv_gpiote_in_init(nrf_drv_gpiote_pin_t pin,
                                  nrf_drv_gpiote_in_config_t * p_config,
                                  nrf_drv_gpiote_evt_handler_t evt_handler)
{
    ASSERT(pin < NUMBER_OF_PINS);
    ret_code_t result = NRF_SUCCESS;
    /* Only one GPIOTE channel can be assigned to one physical pin. */
    if (pin_in_use_by_gpiote(pin))
    {
        result = NRF_ERROR_INVALID_STATE;
    }
    else
    {
        int8_t channel = channel_port_alloc(pin, evt_handler, p_config->hi_accuracy);
        if (channel != NO_CHANNELS)
        {
            if (p_config->is_watcher)
            {
                nrf_gpio_cfg_watcher(pin);
            }
            else
            {
                nrf_gpio_cfg_input(pin,p_config->pull);
            }

            if (p_config->hi_accuracy)
            {
                nrf_gpiote_event_configure(channel, pin,p_config->sense);
            }
            else
            {
                g_gpio_control_block.handlers_to_pins[channel-NUMBER_OF_GPIO_TE] |= (p_config->sense)<< SENSE_FIELD_POS;
            }
        }
        else
        {
            result = NRF_ERROR_NO_MEM;
        }
    }
    return result;
}

void nrf_drv_gpiote_in_event_enable(nrf_drv_gpiote_pin_t pin, bool int_enable)
{
    ASSERT(pin < NUMBER_OF_PINS);
    ASSERT(pin_in_use_by_gpiote(pin));
    if (pin_in_use_by_port(pin))
    {
        uint8_t pin_and_sense = pin_from_port_get(channel_port_get(pin)-NUMBER_OF_GPIO_TE);
        nrf_gpiote_polarity_t polarity = (nrf_gpiote_polarity_t)(pin_and_sense >> SENSE_FIELD_POS);
        nrf_gpio_pin_sense_t sense;
        if (polarity == NRF_GPIOTE_POLARITY_TOGGLE)
        {
            /* read current pin state and set for next sense to oposit */
            sense = (nrf_gpio_pins_read() & (1 << pin)) ?
                    NRF_GPIO_PIN_SENSE_LOW : NRF_GPIO_PIN_SENSE_HIGH;
        }
        else
        {
            sense = (polarity == NRF_GPIOTE_POLARITY_LOTOHI) ?
                    NRF_GPIO_PIN_SENSE_HIGH : NRF_GPIO_PIN_SENSE_LOW;
        }
        nrf_gpio_cfg_sense_set(pin,sense);
    }
    else if(pin_in_use_by_te(pin))
    {
        int32_t channel = (int32_t)channel_port_get(pin);
        nrf_gpiote_events_t event = (nrf_gpiote_events_t)((uint32_t)NRF_GPIOTE_EVENTS_IN_0+4*channel);
        nrf_gpiote_event_enable(channel);

        nrf_gpiote_event_clear(event);
        if (int_enable)
        {
            nrf_gpiote_int_enable(1 << channel);
        }
    }
}

void nrf_drv_gpiote_in_event_disable(nrf_drv_gpiote_pin_t pin)
{
    ASSERT(pin < NUMBER_OF_PINS);
    ASSERT(pin_in_use_by_gpiote(pin));
    if (pin_in_use_by_port(pin))
    {
        nrf_gpio_input_disconnect(pin);
    }
    else if(pin_in_use_by_te(pin))
    {
        int32_t channel = (int32_t)channel_port_get(pin);
        nrf_gpiote_event_disable(channel);
        nrf_gpiote_int_disable(1 << channel);
    }
}

void nrf_drv_gpiote_in_uninit(nrf_drv_gpiote_pin_t pin)
{
    ASSERT(pin < NUMBER_OF_PINS);
    ASSERT(pin_in_use_by_gpiote(pin));
    nrf_drv_gpiote_in_event_disable(pin);
    if(pin_in_use_by_te(pin))
    {
        nrf_gpiote_te_default(channel_port_get(pin));
    }
    nrf_gpio_cfg_default(pin);
    channel_free((uint8_t)channel_port_get(pin));
    pin_in_use_clear(pin);
}

bool nrf_drv_gpiote_in_is_set(nrf_drv_gpiote_pin_t pin)
{
    ASSERT(pin < NUMBER_OF_PINS);
    return nrf_gpio_pin_read(pin) ? true : false;
}

uint32_t nrf_drv_gpiote_in_event_addr_get(nrf_drv_gpiote_pin_t pin)
{
    ASSERT(pin < NUMBER_OF_PINS);
    ASSERT(pin_in_use_by_te(pin));

    nrf_gpiote_events_t event = (nrf_gpiote_events_t)((uint32_t)NRF_GPIOTE_EVENTS_IN_0+(4*channel_port_get(pin)));
    return nrf_gpiote_event_addr_get(event);
}

void GPIOTE_IRQHandler(void)
{
    uint32_t status = 0;
    uint32_t input = 0;


    /* collect status of all GPIOTE pin events. Processing is done once all are collected and cleared.*/
    uint32_t i;
    nrf_gpiote_events_t event = NRF_GPIOTE_EVENTS_IN_0;
    uint32_t mask = (uint32_t)NRF_GPIOTE_INT_IN0_MASK;
    for (i = 0; i < NUMBER_OF_GPIO_TE; i++)
    {
        if (nrf_gpiote_event_is_set(event) && nrf_gpiote_int_is_enabled(1 << i))
        {
            nrf_gpiote_event_clear(event);
            status |= mask;
        }
        mask <<= 1;
        event = (nrf_gpiote_events_t)((uint32_t)event + 4);
    }

    /* collect PORT status event, if event is set read pins state. Processing is postponed to the
     * end of interrupt. */
    if (nrf_gpiote_event_is_set(NRF_GPIOTE_EVENTS_PORT))
    {
        nrf_gpiote_event_clear(NRF_GPIOTE_EVENTS_PORT);
        status |= (uint32_t)NRF_GPIOTE_INT_PORT_MASK;
        input = nrf_gpio_pins_read();
    }

    /* Process pin events. */
    if (status & NRF_GPIOTE_INT_IN_MASK)
    {
        mask = 1;
        for (i = 0; i < NUMBER_OF_GPIO_TE; i++)
        {
            if (mask & status)
            {
                nrf_drv_gpiote_pin_t pin = nrf_gpiote_event_pin_get(i);
                nrf_gpiote_polarity_t polarity = nrf_gpiote_event_polarity_get(i);
                nrf_drv_gpiote_evt_handler_t handler = channel_handler_get(i);
                handler(pin,polarity);
            }
            mask <<= 1;
        }
    }

    if (status & (uint32_t)NRF_GPIOTE_INT_PORT_MASK)
    {
        /* Process port event. */
        for (i = 0; i < GPIOTE_CONFIG_NUM_OF_LOW_POWER_EVENTS; i++)
        {
            uint8_t pin_and_sense = pin_from_port_get(i);
            nrf_drv_gpiote_pin_t pin = (pin_and_sense & ~SENSE_FIELD_MASK);
            nrf_gpiote_polarity_t polarity =
                    (nrf_gpiote_polarity_t)((pin_and_sense & SENSE_FIELD_MASK) >> SENSE_FIELD_POS);
            mask = 1 << pin;
            if (pin_in_use_by_port(pin))
            {
                nrf_drv_gpiote_evt_handler_t handler = channel_handler_get(channel_port_get(pin));
                if (handler)
                {
                    nrf_gpio_pin_sense_t sense = nrf_gpio_pin_sense_get(pin);
                    if (((mask & input) && (sense==NRF_GPIO_PIN_SENSE_HIGH)) ||
                       (!(mask & input) && (sense==NRF_GPIO_PIN_SENSE_LOW))  )
                    {
                        if (polarity == NRF_GPIOTE_POLARITY_TOGGLE)
                        {
                            nrf_gpio_pin_sense_t next_sense = (sense == NRF_GPIO_PIN_SENSE_HIGH) ?
                                    NRF_GPIO_PIN_SENSE_LOW : NRF_GPIO_PIN_SENSE_HIGH;
                            nrf_gpio_cfg_sense_set(pin, next_sense);
                        }
                        handler(pin, polarity);
                    }
                }
            }
        }
    }
}
//lint -restore
