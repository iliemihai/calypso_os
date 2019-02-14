/*****************************************************************************
* | File      	:   ImageData.c
* | Author      :   Waveshare team
* | Function    :	
*----------------
* |	This version:   V1.0
* | Date        :   2018-10-23
* | Info        :
*
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#

******************************************************************************/

#include "ImageData.h"



const unsigned char gImage_2in7[5808]  = { 
/* 0X00,0X01,0XB0,0X00,0X08,0X01, */
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0X80,0X00,0X00,0X00,0X00,0X03,0XE1,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0X80,0X00,0X00,0X00,
0X00,0X03,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFE,0X1F,0X80,0X00,0X00,0X00,0X00,0X03,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0X80,0X00,0X00,0X00,0X00,0X03,0XE1,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0XFF,0XFF,0XFE,0X1F,0X80,0X00,
0X00,0X00,0X00,0X03,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,
0X1F,0XFF,0XFE,0X1F,0X83,0XFF,0XFF,0XFF,0XFF,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X0F,0XFF,0XFE,0X1F,0X83,0XFF,0XFF,0XFF,0XFF,0X83,
0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X0E,0X07,0XFF,0XFE,0X1F,
0X83,0XFF,0XFF,0XFF,0XFF,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XF8,0X3F,0X83,0XFF,0XFE,0X1F,0X83,0XFF,0XFF,0XFF,0XFF,0X83,0XE1,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X7F,0XE1,0XFF,0XFE,0X1F,0X83,0XFF,0XFF,0XFF,
0XFF,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0XFF,0XF1,0XFF,
0XFE,0X1F,0X83,0XFF,0XC0,0X00,0X01,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0X01,0XFF,0XF1,0XFF,0XFE,0X1F,0X83,0X00,0X00,0X00,0X01,0X83,0XE1,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X01,0XFF,0XF0,0XFF,0XFE,0X1F,0X83,0X00,
0X00,0X00,0X01,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X03,0XFF,
0XF0,0XFF,0XFE,0X1F,0X83,0X00,0X00,0X00,0X01,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XF0,0X7F,0XFF,0XF0,0XFF,0XFE,0X1F,0X83,0X00,0X00,0X00,0X01,0X83,
0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0XFF,0XFF,0XF0,0XFF,0XFE,0X1F,
0X83,0X01,0XFF,0XFF,0XFF,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC3,
0XFF,0XFF,0XF0,0XFF,0XFE,0X1F,0X83,0X00,0X3F,0XFF,0XFF,0X83,0XE1,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XC7,0XFF,0XFF,0XF0,0XFF,0XFE,0X1F,0X83,0X00,0X07,0XFF,
0XFF,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X87,0XFF,0XFF,0XF0,0XFF,
0XFE,0X1F,0X83,0XE0,0X00,0X7F,0XFF,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0X8F,0XFF,0XFF,0XF0,0XFF,0XFE,0X1F,0X83,0XFE,0X00,0X0F,0XFF,0X83,0XE1,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X8F,0XFF,0XFF,0XF0,0XFF,0XFE,0X1F,0X83,0XFF,
0XE0,0X03,0XFF,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X8F,0XFF,0XFF,
0XF0,0XFF,0XFE,0X1F,0X83,0XFF,0XFE,0X03,0XFF,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0X8F,0XFF,0XFF,0XF0,0XFF,0XFE,0X1F,0X83,0XFF,0XE0,0X03,0XFF,0X83,
0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X8F,0XFF,0XFF,0XF0,0XFF,0XFE,0X1F,
0X83,0XFE,0X00,0X03,0XFF,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X8F,
0XFF,0XFF,0XF0,0XFF,0XFE,0X1F,0X83,0XE0,0X00,0X1F,0XFF,0X83,0XE1,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0X87,0XFF,0XFF,0XF0,0XFF,0XFE,0X1F,0X83,0X00,0X01,0XFF,
0XFF,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X87,0XFF,0XFF,0XF0,0XFF,
0XFE,0X1F,0X83,0X00,0X1F,0XFF,0XFF,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XC3,0XFF,0XFF,0XF0,0XFF,0XFE,0X1F,0X83,0X00,0XFF,0XFF,0XFF,0X83,0XE1,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF9,0XC1,0XFF,0XFF,0XF0,0XFF,0XFE,0X1F,0X83,0X00,
0X00,0X00,0X1F,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0XE0,0XFF,0XFF,
0XF0,0XFF,0XFE,0X1F,0X83,0X00,0X00,0X00,0X01,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFC,0X70,0X1F,0XFF,0XF0,0XFF,0XFE,0X1F,0X83,0X00,0X00,0X00,0X01,0X83,
0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X38,0X1F,0XFF,0XF0,0XFF,0XFE,0X1F,
0X83,0X00,0X00,0X00,0X01,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X3E,
0X1F,0XFF,0XF0,0XFF,0XFE,0X1F,0X83,0XFF,0XC0,0X00,0X01,0X83,0XE1,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XBE,0X1F,0XFF,0XF0,0XFF,0XFE,0X1F,0X83,0XFF,0XFF,0XFF,
0XFF,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X3F,0XBE,0X1F,0XFF,0XF0,0XFF,
0XFE,0X1F,0X83,0XFF,0XFF,0XFF,0XFF,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X0F,0X1E,0X1F,0XFF,0XF0,0XFF,0XFE,0X1F,0X83,0XFF,0XFF,0XFF,0XE1,0X83,0XE1,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X82,0X0E,0X1F,0XFF,0XF0,0XFF,0XFE,0X1F,0X83,0XFF,
0XFF,0XFF,0X01,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X1E,0X1F,0XFF,
0XF0,0XFF,0XFE,0X1F,0X83,0XFF,0XFF,0XF0,0X01,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFC,0X3F,0X0F,0XFF,0XF0,0XFF,0XFE,0X1F,0X83,0XFF,0XFF,0X80,0X01,0X83,
0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X3F,0X07,0XFF,0XF0,0XFF,0XFE,0X1F,
0X83,0XFF,0XF8,0X00,0X01,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X7F,
0X81,0XFF,0XF0,0XFF,0XFE,0X1F,0X83,0XFF,0XC0,0X00,0X01,0X83,0XE1,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XF8,0X7F,0XC0,0X0F,0XF0,0XFF,0XFE,0X1F,0X83,0XFC,0X00,0X00,
0X07,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X7F,0XE0,0X1F,0XF0,0XFF,
0XFE,0X1F,0X83,0XE0,0X00,0X00,0X7F,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,
0X00,0X7F,0XFC,0X1F,0XF0,0XFF,0XFE,0X1F,0X83,0X00,0X00,0X00,0X7F,0X83,0XE1,0XFF,
0XFF,0XFE,0X3F,0XFF,0XFF,0XFF,0XFC,0X7F,0XFE,0X1F,0XF0,0XFF,0XFE,0X1F,0X83,0X00,
0X00,0X70,0X7F,0X83,0XE1,0XFF,0XFF,0XFC,0X1F,0XFF,0XFF,0XFF,0XFC,0X3F,0XFE,0X1F,
0XF0,0XFF,0XFE,0X1F,0X83,0X00,0X07,0XF0,0X7F,0X83,0XE1,0XFF,0XFF,0XFC,0X1F,0XFF,
0XFF,0XFF,0XFC,0X1F,0XFF,0X1F,0XF1,0XFF,0XFE,0X1F,0X83,0X00,0X7F,0XF0,0X7F,0X83,
0XE1,0XFF,0XFF,0XFE,0X3F,0XFF,0XFF,0XFF,0XF8,0X0F,0XFF,0X0F,0XE1,0XFF,0XFE,0X1F,
0X83,0X07,0XFF,0XF0,0X7F,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X01,
0X0F,0X83,0XC1,0XFF,0XFE,0X1F,0X83,0X00,0X7F,0XF0,0X7F,0X83,0XE1,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XC3,0X80,0X07,0X80,0X03,0XFF,0XFE,0X1F,0X83,0X00,0X0F,0XF0,
0X7F,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X8F,0XC0,0X03,0XC0,0X07,0XFF,
0XFE,0X1F,0X83,0X00,0X00,0XF0,0X7F,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X9F,0XC0,0X19,0XF0,0X1F,0XFF,0XFE,0X1F,0X83,0X80,0X00,0X10,0X7F,0X83,0XE1,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X9E,0X7C,0XFC,0X7F,0XFF,0XFE,0X1F,0X83,0XF0,
0X00,0X00,0X7F,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X9F,0X7C,0X7F,
0XFF,0XFF,0XFE,0X1F,0X83,0XFE,0X00,0X00,0X3F,0X83,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0X3F,0X7E,0X7F,0XFF,0XFF,0XFE,0X1F,0X83,0XFF,0XE0,0X00,0X03,0X83,
0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X3F,0X7F,0X3F,0XFF,0XFF,0XFE,0X1F,
0X83,0XFF,0XFC,0X00,0X01,0X83,0XE1,0XFF,0X00,0X00,0X1F,0XFF,0XFF,0XFF,0XFE,0X7F,
0X3F,0XBF,0XFF,0XFF,0XFE,0X1F,0X83,0XFF,0XFF,0XC0,0X01,0X83,0XE1,0XFF,0X00,0X00,
0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0X3F,0XFF,0XFF,0XFF,0XFE,0X1F,0X83,0XFF,0XFF,0XF8,
0X01,0X83,0XE1,0XFF,0XF8,0XFC,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0X3F,0XFF,0XFF,0XFF,
0XFE,0X1F,0X83,0XFF,0XFF,0XFF,0X01,0X83,0XE1,0XFF,0XF9,0XFE,0X3F,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0X83,0XFF,0XFF,0XFF,0XF1,0X83,0XE1,0XFF,
0XF9,0XFF,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0X83,0XFF,
0XFF,0XFF,0XFF,0X83,0XE1,0XFF,0XF9,0XFF,0X9F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFE,0X1F,0X83,0XFF,0XFF,0XFF,0XFF,0X83,0XE1,0XFF,0XF9,0XFF,0X9F,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0X83,0XFF,0XFF,0XFF,0XFF,0X83,
0XE1,0XFF,0XFC,0XFF,0X9F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,
0X83,0XFF,0XFF,0XFF,0XFF,0X83,0XE1,0XFF,0XFC,0X7F,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0X80,0X00,0X00,0X00,0X00,0X03,0XE1,0XFF,0XFE,0X00,
0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0X80,0X00,0X00,0X00,
0X00,0X03,0XE1,0XFF,0XFF,0X00,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFE,0X1F,0X80,0X00,0X00,0X00,0X00,0X03,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0X80,0X00,0X00,0X00,0X00,0X03,0XE1,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0X80,0X00,
0X00,0X00,0X00,0X03,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XE1,0XFF,0XFF,0X07,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFE,0X07,0XBF,0XFF,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFC,0X67,
0X9F,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XE1,0XFF,0XF8,0XE7,0X9F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XF9,0XE7,0X9F,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,
0XF9,0XE7,0X9F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XF9,0XE7,0X9F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XF9,0XE7,0X1F,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XE1,0XFF,0XFC,0XE7,0X3F,0XFF,0XFF,0XF8,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFC,0X00,0X3F,0XFF,0XFF,0XF0,0X01,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFE,0X00,
0X7F,0XFF,0XFF,0XC1,0XE0,0X3F,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XE1,0XFF,0XFF,0X81,0XFF,0XFF,0XFF,0X0F,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,
0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X3F,
0XFF,0X07,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFC,0X38,0X63,0X83,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0X80,0X1F,0XFF,0XFF,0XF8,0X70,0X31,0XC1,0XFF,0XFF,
0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0X80,0X00,0X1F,0XFF,
0XF0,0X60,0X30,0XC1,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFC,0X00,0X03,0XFF,0XFF,
0XE1,0XFF,0XFF,0XFC,0X1F,0XFF,0XE0,0X60,0X30,0X40,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,
0XFF,0XC0,0X00,0X00,0X7F,0XFF,0XE1,0XFF,0XFF,0XFE,0X1F,0XFF,0XE0,0X60,0X30,0X60,
0X00,0X00,0X00,0X01,0XFE,0X1F,0XFF,0X00,0X00,0X00,0X1F,0XFF,0XE1,0XFF,0XFF,0XF0,
0X7F,0XFF,0XC0,0X70,0X30,0X60,0X00,0X00,0X00,0X01,0XFE,0X1F,0XFE,0X00,0X00,0X00,
0X07,0XFF,0XE1,0XFF,0XFF,0X83,0XFF,0XFF,0XC0,0X30,0X70,0X60,0X00,0X00,0X00,0X01,
0XFE,0X1F,0XFC,0X00,0X00,0X00,0X03,0XFF,0XE1,0XFF,0XFE,0X1F,0XFF,0XFF,0X80,0X3F,
0XE0,0X60,0X00,0X00,0X00,0X01,0XFE,0X1F,0XF8,0X00,0X3F,0XFC,0X01,0XFF,0XE1,0XFF,
0XFE,0X0F,0XFF,0XFF,0X80,0X1F,0XC0,0X00,0X00,0X00,0X00,0X01,0XFE,0X1F,0XF0,0X18,
0X1F,0XFF,0X80,0XFF,0XE1,0XFF,0XFF,0XC1,0XFF,0XFF,0X80,0X03,0X00,0X00,0X00,0X00,
0X00,0X01,0XFE,0X1F,0XE0,0X7C,0X0F,0XFF,0XE0,0XFF,0XE1,0XFF,0XFF,0XF8,0X3F,0XFF,
0X80,0X00,0X00,0X00,0X1F,0XFF,0XF0,0X01,0XFE,0X1F,0XE0,0XFE,0X07,0XFF,0XF0,0X7F,
0XE1,0XFF,0XFF,0XFF,0X1F,0XFF,0X80,0X00,0X00,0X00,0X1F,0XFF,0XE0,0X01,0XFE,0X1F,
0XE1,0XFF,0X07,0XFF,0XF8,0X7F,0XE1,0XFF,0XE0,0X00,0X1F,0XFF,0X80,0X00,0X00,0X00,
0X1F,0XFF,0XC0,0X01,0XFE,0X1F,0XC1,0XFF,0X03,0XFF,0XF8,0X7F,0XE1,0XFF,0X80,0X00,
0X1F,0XFF,0X80,0X07,0XFC,0X00,0X1F,0XFF,0X80,0X01,0XFE,0X1F,0XC3,0XFF,0X81,0XFF,
0XFC,0X3F,0XE1,0XFF,0X83,0XFF,0XFF,0XFF,0X80,0X1F,0XFF,0X00,0X1F,0XFF,0X00,0X01,
0XFE,0X1F,0XC3,0XFF,0XC0,0XFF,0XFC,0X3F,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X3C,
0X67,0X80,0X1F,0XFE,0X00,0X81,0XFE,0X1F,0XC3,0XFF,0XE0,0XFF,0XFC,0X3F,0XE1,0XFF,
0XFF,0XFF,0XFF,0XFF,0X80,0X30,0X21,0XC0,0X1F,0XFC,0X01,0X81,0XFE,0X1F,0XC3,0XFF,
0XE0,0X7F,0XFC,0X3F,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X60,0X30,0XC0,0X3F,0XF8,
0X03,0X81,0XFE,0X1F,0XC3,0XFF,0XF0,0X3F,0XFC,0X3F,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,
0XC0,0X60,0X30,0XC0,0X7F,0XF0,0X0F,0X81,0XFE,0X1F,0XE1,0XFF,0XF8,0X3F,0XF8,0X3F,
0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X60,0X30,0X60,0X7F,0XE0,0X1F,0X81,0XFE,0X1F,
0XE1,0XFF,0XFC,0X1F,0XF8,0X7F,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X60,0X30,0X60,
0XFF,0XC0,0X3F,0X81,0XFE,0X1F,0XE0,0XFF,0XFC,0X0F,0XF0,0X7F,0XE1,0XFF,0XFF,0XFF,
0XFF,0XFF,0XE0,0X30,0X70,0X60,0XFF,0X80,0X7F,0X81,0XFE,0X1F,0XF0,0X7F,0XFE,0X07,
0XC0,0X7F,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X38,0XE0,0X61,0XFE,0X00,0XFF,0X81,
0XFE,0X1F,0XF0,0X1F,0XFF,0X07,0X80,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XF8,0X1F,
0XE0,0X61,0XFC,0X01,0XFF,0X81,0XFE,0X1F,0XF8,0X03,0XFF,0X00,0X01,0XFF,0XE1,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFC,0X0F,0X80,0X00,0XF8,0X03,0XFF,0X81,0XFE,0X1F,0XFC,0X00,
0X00,0X00,0X01,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X00,0X00,0X00,0X70,0X07,
0XFF,0X81,0XFE,0X1F,0XFE,0X00,0X00,0X00,0X07,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0X00,0X00,0X00,0X20,0X0F,0XFF,0X81,0XFE,0X1F,0XFF,0X80,0X00,0X00,0X0F,0XFF,
0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X00,0X60,0X00,0X1F,0XFF,0X81,0XFE,0X1F,
0XFF,0XE0,0X00,0X00,0X3F,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X01,0XF0,
0X00,0X3F,0XFF,0X81,0XFE,0X1F,0XFF,0XFC,0X00,0X03,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0X81,0XFF,0XF8,0X00,0XFF,0XFF,0X81,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X81,0XFF,0XFC,0X01,0XFF,0XFF,0X81,
0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X81,
0XFF,0XFE,0X01,0XFF,0XFF,0X81,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0X81,0XFF,0XFE,0X01,0XFF,0XFF,0X81,0XFE,0X1F,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XC0,0XFF,0XFF,0XFF,0X81,0XFF,0XFF,0X00,0XFF,
0XFF,0X81,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0X9F,0X80,0X3F,0XFF,
0XFF,0X81,0XFF,0XFF,0X80,0X7F,0XFF,0X81,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XE1,0XFF,0X9F,0X9E,0X3F,0XFF,0XFF,0X81,0XFF,0XFF,0XC0,0X3F,0XFF,0X81,0XFE,0X1F,
0XFF,0XFC,0X00,0X03,0XFF,0XFF,0XE1,0XFF,0X9F,0X3F,0X1F,0XFF,0XFF,0X81,0XFF,0XFF,
0XE0,0X1F,0XFF,0X81,0XFE,0X1F,0XFF,0XC0,0X00,0X00,0X7F,0XFF,0XE1,0XFF,0X9F,0X3F,
0X9F,0XFF,0XFF,0X81,0XFF,0XFF,0XF0,0X0F,0XFF,0X81,0XFE,0X1F,0XFF,0X00,0X00,0X00,
0X1F,0XFF,0XE1,0XFF,0X9F,0X3F,0X9F,0XFF,0XFF,0X81,0XFF,0XFF,0XF8,0X0F,0XFF,0X81,
0XFE,0X1F,0XFE,0X00,0X00,0X00,0X07,0XFF,0XE1,0XFF,0XCF,0X3F,0X9F,0XFF,0XFF,0X81,
0XFF,0XFF,0XFC,0X07,0XFF,0X81,0XFE,0X1F,0XFC,0X00,0X00,0X00,0X03,0XFF,0XE1,0XFF,
0XCF,0X3F,0X9F,0XFF,0XFF,0X81,0XFF,0XFF,0XFE,0X03,0XFF,0X81,0XFE,0X1F,0XF8,0X00,
0X3F,0XFC,0X01,0XFF,0XE1,0XFF,0XE3,0X9F,0X3F,0XFF,0XFF,0X81,0XFF,0XFF,0XFE,0X03,
0XFF,0X81,0XFE,0X1F,0XF0,0X18,0X1F,0XFF,0X80,0XFF,0XE1,0XFF,0XF0,0X00,0X3F,0XFF,
0XFF,0X81,0XFF,0XFF,0XFC,0X03,0XFF,0X81,0XFE,0X1F,0XE0,0X7C,0X0F,0XFF,0XE0,0XFF,
0XE1,0XFF,0XF8,0X00,0X7F,0XFF,0XFF,0X81,0XFF,0XFF,0XF8,0X07,0XFF,0X81,0XFE,0X1F,
0XE0,0XFE,0X07,0XFF,0XF0,0X7F,0XE1,0XFF,0XFF,0X03,0XFF,0XFF,0XFF,0X81,0XFF,0XFF,
0XF0,0X0F,0XFF,0X81,0XFE,0X1F,0XE1,0XFF,0X07,0XFF,0XF8,0X7F,0XE1,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0X81,0XFF,0XFF,0XE0,0X1F,0XFF,0X81,0XFE,0X1F,0XC1,0XFF,0X03,0XFF,
0XF8,0X7F,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X81,0XFF,0XFF,0XC0,0X3F,0XFF,0X81,
0XFE,0X1F,0XC3,0XFF,0X81,0XFF,0XFC,0X3F,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X81,
0XFF,0XFF,0XC0,0X7F,0XFF,0X81,0XFE,0X1F,0XC3,0XFF,0XC0,0XFF,0XFC,0X3F,0XE1,0XFF,
0XFF,0XFF,0X9F,0XFF,0XFF,0X81,0XFF,0XFF,0X80,0XFF,0XFF,0X81,0XFE,0X1F,0XC3,0XFF,
0XE0,0XFF,0XFC,0X3F,0XE1,0XFF,0XFF,0XFF,0X9F,0XFF,0XFF,0X81,0XFF,0XFF,0X01,0XFF,
0XFF,0X81,0XFE,0X1F,0XC3,0XFF,0XE0,0X7F,0XFC,0X3F,0XE1,0XFF,0XFF,0XFF,0X9F,0XFF,
0XFF,0X81,0XFF,0XFE,0X01,0XFF,0XFF,0X81,0XFE,0X1F,0XC3,0XFF,0XF0,0X3F,0XFC,0X3F,
0XE1,0XFF,0XFF,0XFF,0X9F,0XFF,0XFF,0X81,0XFF,0XFC,0X01,0XFF,0XFF,0X81,0XFE,0X1F,
0XE1,0XFF,0XF8,0X3F,0XF8,0X3F,0XE1,0XFF,0X80,0X00,0X1F,0XFF,0XFF,0X81,0XFF,0XF8,
0X00,0XFF,0XFF,0X81,0XFE,0X1F,0XE1,0XFF,0XFC,0X1F,0XF8,0X7F,0XE1,0XFF,0X80,0X00,
0X1F,0XFF,0XFF,0X81,0XFF,0XF0,0X00,0X7F,0XFF,0X81,0XFE,0X1F,0XE0,0XFF,0XFC,0X0F,
0XF0,0X7F,0XE1,0XFF,0X80,0X00,0X1F,0XFF,0XFF,0X81,0XFF,0XE0,0X00,0X3F,0XFF,0X81,
0XFE,0X1F,0XF0,0X7F,0XFE,0X07,0XC0,0X7F,0XE1,0XFF,0XDF,0XFF,0X9F,0XFF,0XFF,0X81,
0XFF,0XE0,0X00,0X1F,0XFF,0X81,0XFE,0X1F,0XF0,0X1F,0XFF,0X07,0X80,0XFF,0XE1,0XFF,
0XCF,0XFF,0X9F,0XFF,0XFF,0X81,0XFF,0XC0,0X70,0X0F,0XFF,0X81,0XFE,0X1F,0XF8,0X03,
0XFF,0X00,0X01,0XFF,0XE1,0XFF,0XE7,0XFF,0X9F,0XFF,0XFF,0X81,0XFF,0X80,0XF8,0X07,
0XFF,0X81,0XFE,0X1F,0XFC,0X00,0X00,0X00,0X01,0XFF,0XE1,0XFF,0XE7,0XFF,0X9F,0XFF,
0XFF,0X81,0XFF,0X01,0XFC,0X01,0XFF,0X81,0XFE,0X1F,0XFE,0X00,0X00,0X00,0X07,0XFF,
0XE1,0XFF,0XF7,0XFF,0X9F,0XFF,0XFF,0X81,0XFE,0X01,0XFE,0X00,0XFF,0X81,0XFE,0X1F,
0XFF,0X80,0X00,0X00,0X0F,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X81,0XFC,0X03,
0XFF,0X00,0X7F,0X81,0XFE,0X1F,0XFF,0XE0,0X00,0X00,0X3F,0XFF,0XE1,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0X81,0XF8,0X07,0XFF,0X80,0X3F,0X81,0XFE,0X1F,0XFF,0XFC,0X00,0X03,
0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X81,0XF0,0X0F,0XFF,0XC0,0X1F,0X81,
0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X81,
0XE0,0X1F,0XFF,0XE0,0X0F,0X81,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0X81,0XE0,0X3F,0XFF,0XF0,0X07,0X81,0XFE,0X1F,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X81,0XC0,0X7F,0XFF,0XFC,
0X03,0X81,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0X81,0X80,0XFF,0XFF,0XFE,0X01,0X81,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X81,0X00,0XFF,0XFF,0XFF,0X00,0X81,0XFE,0X1F,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X01,0XFF,
0XFF,0XFF,0X80,0X01,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0X80,0X03,0XFF,0XFF,0XFF,0XC0,0X01,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X07,0XFF,0XFF,0XFF,0XE0,0X01,
0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,
0X0F,0XFF,0XFF,0XFF,0XF0,0X01,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X0F,0XFF,0XFF,0XFF,0XF0,0X01,0XFE,0X1F,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X00,0X00,0X00,0X00,
0X00,0X01,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0X80,0X00,0X00,0X00,0X00,0X00,0X01,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X00,0X00,0X00,0X00,0X00,0X01,0XFE,0X1F,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X00,0X00,
0X00,0X00,0X00,0X01,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0X80,0X00,0X00,0X00,0X00,0X00,0X01,0XFE,0X1F,0XFF,0XFC,0X7F,0XFF,
0XF1,0XFF,0XE1,0XFF,0XF9,0XFF,0XE7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFE,0X1F,0XFF,0XF0,0X1F,0XFF,0XC0,0X7F,0XE1,0XFF,0XF9,0XFF,0XC3,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XF0,0X1F,0XFF,0XC0,0X7F,0XE1,0XFF,
0XF8,0X0F,0X81,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XE0,
0X0F,0XFF,0X80,0X3F,0XE1,0XFF,0XF8,0X07,0X99,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFE,0X1F,0XFF,0XE0,0X0F,0XFF,0X80,0X3F,0XE1,0XFF,0XF8,0XE7,0X9C,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XE0,0X0F,0XFF,0X80,0X3F,
0XE1,0XFF,0XF9,0XF3,0X9C,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,
0XFF,0XF0,0X1F,0XFF,0XC0,0X7F,0XE1,0XFF,0XF9,0XF3,0X9C,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XF0,0X1F,0XFF,0XC0,0X7F,0XE1,0XFF,0XF9,0XF3,
0X9C,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFC,0X7F,0XFF,
0XF1,0XFF,0XE1,0XFF,0XF9,0XF3,0X9C,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFC,0XE7,0X9C,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,
0XFC,0X00,0X09,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFE,0X08,0X01,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFC,0X61,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,
0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XF8,0X00,0X1F,0XFF,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,
0XF8,0X00,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFE,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0X3F,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XE1,0XFF,0XFF,0XFF,0X9F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0X9F,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,
0X9F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFC,0X00,0X03,
0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0X9F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFE,0X1F,0XFF,0XC0,0X00,0X00,0X7F,0XFF,0XE1,0XFF,0XFF,0XFC,0X1F,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0X00,0X00,0X00,0X1F,0XFF,0XE1,0XFF,
0XF8,0X00,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFE,0X00,
0X00,0X00,0X07,0XFF,0XE1,0XFF,0XF8,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFE,0X1F,0XFC,0X00,0X00,0X00,0X03,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X01,0XFE,0X1F,0XF8,0X00,0X3F,0XFC,0X01,0XFF,
0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X00,0X00,0X00,0X01,0XFE,0X1F,
0XF0,0X18,0X1F,0XFF,0X80,0XFF,0XE1,0XFF,0XFF,0XFF,0XDF,0XFF,0XFF,0XFF,0XFE,0X00,
0X00,0X00,0X00,0X01,0XFE,0X1F,0XE0,0X7C,0X0F,0XFF,0XE0,0XFF,0XE1,0XFF,0XFF,0XFE,
0X1F,0XFF,0XFF,0XFF,0XF8,0X00,0X00,0X00,0X00,0X01,0XFE,0X1F,0XE0,0XFE,0X07,0XFF,
0XF0,0X7F,0XE1,0XFF,0XFF,0XF0,0X1F,0XFF,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0X01,
0XFE,0X1F,0XE1,0XFF,0X07,0XFF,0XF8,0X7F,0XE1,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,
0XC0,0X00,0X00,0X80,0X00,0X01,0XFE,0X1F,0XC1,0XFF,0X03,0XFF,0XF8,0X7F,0XE1,0XFF,
0XFC,0X01,0XFF,0XFF,0XFF,0XFF,0X80,0X00,0X03,0XE0,0X00,0X01,0XFE,0X1F,0XC3,0XFF,
0X81,0XFF,0XFC,0X3F,0XE1,0XFF,0XE0,0X39,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X0F,0XF8,
0X00,0X01,0XFE,0X1F,0XC3,0XFF,0XC0,0XFF,0XFC,0X3F,0XE1,0XFF,0X81,0XF9,0XFF,0XFF,
0XFF,0XFE,0X00,0X00,0X3F,0XFE,0X00,0X01,0XFE,0X1F,0XC3,0XFF,0XE0,0XFF,0XFC,0X3F,
0XE1,0XFF,0X8F,0XF9,0XFF,0XFF,0XFF,0XFC,0X00,0X00,0XFF,0XFF,0XE0,0X01,0XFE,0X1F,
0XC3,0XFF,0XE0,0X7F,0XFC,0X3F,0XE1,0XFF,0X87,0XF9,0XFF,0XFF,0XFF,0XF8,0X00,0X03,
0XFC,0X0F,0XF0,0X01,0XFE,0X1F,0XC3,0XFF,0XF0,0X3F,0XFC,0X3F,0XE1,0XFF,0X80,0XF9,
0XFF,0XFF,0XFF,0XF0,0X00,0X0F,0XF0,0X03,0XF0,0X01,0XFE,0X1F,0XE1,0XFF,0XF8,0X3F,
0XF8,0X3F,0XE1,0XFF,0XF0,0X19,0XFF,0XFF,0XFF,0XF0,0X00,0X1F,0XF0,0X00,0XF8,0X01,
0XFE,0X1F,0XE1,0XFF,0XFC,0X1F,0XF8,0X7F,0XE1,0XFF,0XFE,0X01,0XFF,0XFF,0XFF,0XE0,
0X00,0X1F,0XF0,0X00,0XFC,0X01,0XFE,0X1F,0XE0,0XFF,0XFC,0X0F,0XF0,0X7F,0XE1,0XFF,
0XFF,0XC0,0X3F,0XFF,0XFF,0XE0,0X00,0X0F,0XF8,0X00,0X00,0X01,0XFE,0X1F,0XF0,0X7F,
0XFE,0X07,0XC0,0X7F,0XE1,0XFF,0XFF,0XF8,0X1F,0XFF,0XFF,0XC0,0X00,0X03,0XFE,0X00,
0X00,0X01,0XFE,0X1F,0XF0,0X1F,0XFF,0X07,0X80,0XFF,0XE1,0XFF,0XFF,0XFF,0X9F,0XFF,
0XFF,0XC0,0X00,0X00,0XFF,0X80,0X00,0X01,0XFE,0X1F,0XF8,0X03,0XFF,0X00,0X01,0XFF,
0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X00,0X00,0X3F,0XE0,0X00,0X01,0XFE,0X1F,
0XFC,0X00,0X00,0X00,0X01,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X00,0X00,
0X07,0XFC,0X00,0X01,0XFE,0X1F,0XFE,0X00,0X00,0X00,0X07,0XFF,0XE1,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0X80,0X00,0X00,0X03,0XFC,0X00,0X01,0XFE,0X1F,0XFF,0X80,0X00,0X00,
0X0F,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X1F,0XC0,0X03,0XFC,0X00,0X01,
0XFE,0X1F,0XFF,0XE0,0X00,0X00,0X3F,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,
0X0F,0XC0,0X03,0XFC,0X00,0X01,0XFE,0X1F,0XFF,0XFC,0X00,0X03,0XFF,0XFF,0XE1,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X07,0XF8,0X1F,0XF0,0X00,0X01,0XFE,0X1F,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X03,0XFE,0X3F,0X00,
0X00,0X01,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0X00,0X01,0XFF,0XFE,0X00,0X00,0X01,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X1F,0XFE,0X00,0X00,0X01,0XFE,0X1F,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X03,
0XFE,0X00,0X00,0X01,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0X00,0X00,0X00,0XFF,0X80,0X00,0X01,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X3F,0XE0,0X00,0X01,
0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XF0,0X7F,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,
0X00,0X00,0X1F,0XFC,0X00,0X01,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XF0,0X7F,0XE1,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X1F,0XFC,0X00,0X01,0XFE,0X1F,0XFF,0XFF,
0XFF,0XFF,0XF0,0X7F,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X1F,0XFC,
0X00,0X01,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XF0,0X7F,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0X00,0X00,0X00,0XFF,0XE0,0X00,0X01,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XF0,0X7F,
0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X07,0XFF,0X00,0X00,0X01,0XFE,0X1F,
0XFF,0XFF,0XFF,0XFF,0XF0,0X7F,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X1F,
0XFC,0X00,0X00,0X01,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XF0,0X7F,0XE1,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0X00,0X00,0X1F,0XF0,0X00,0X00,0X03,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,
0XF0,0X7F,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X1F,0XF0,0X00,0X00,0X03,
0XFE,0X1F,0XE0,0X00,0X00,0X00,0X00,0X7F,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,
0X00,0X0F,0XF0,0X00,0X00,0X03,0XFE,0X1F,0XE0,0X00,0X00,0X00,0X00,0X7F,0XE1,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X01,0XFE,0X00,0X00,0X07,0XFE,0X1F,0XE0,0X00,
0X00,0X00,0X00,0X7F,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X3F,0XC0,
0X00,0X07,0XFE,0X1F,0XE0,0X00,0X00,0X00,0X00,0X7F,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0X00,0X00,0X00,0X3F,0XF8,0X00,0X0F,0XFE,0X1F,0XE0,0X00,0X00,0X00,0X00,0X7F,
0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X3F,0XFC,0X00,0X0F,0XFE,0X1F,
0XE0,0X00,0X00,0X00,0X00,0X7F,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,
0X7F,0XFC,0X00,0X1F,0XFE,0X1F,0XF0,0XFF,0XFF,0XFF,0XF0,0X7F,0XE1,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0X00,0X00,0X03,0XFF,0XF8,0X00,0X3F,0XFE,0X1F,0XF8,0X7F,0XFF,0XFF,
0XF0,0X7F,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X0F,0XFF,0XC0,0X00,0X3F,
0XFE,0X1F,0XF8,0X3F,0XFF,0XFF,0XF0,0X7F,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,
0X00,0X1F,0XFE,0X00,0X00,0X7F,0XFE,0X1F,0XFC,0X3F,0XFF,0XFF,0XF0,0X7F,0XE1,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X1F,0XF0,0X00,0X00,0XFF,0XFE,0X1F,0XFC,0X1F,
0XFF,0XFF,0XF0,0X7F,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X1F,0X80,0X00,
0X01,0XFF,0XFE,0X1F,0XFE,0X0F,0XFF,0XFF,0XF0,0X7F,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0X00,0X00,0X1C,0X00,0X00,0X03,0XFF,0XFE,0X1F,0XFE,0X0F,0XFF,0XFF,0XF0,0X7F,
0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X07,0XFF,0XFE,0X1F,
0XFF,0X07,0XFF,0XFF,0XF0,0X7F,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,
0X00,0X00,0X1F,0XFF,0XFE,0X1F,0XFF,0X83,0XFF,0XFF,0XF0,0X7F,0XE1,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X3F,0XFF,0XFE,0X1F,0XFF,0X87,0XFF,0XFF,
0XF0,0X7F,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0XFF,0XFF,
0XFE,0X1F,0XFF,0XDF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,
0X00,0X00,0X00,0X03,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X00,0X00,0X00,0X1F,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XFF,0XFF,0XFF,
};
