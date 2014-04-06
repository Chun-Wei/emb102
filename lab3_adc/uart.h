/**************************************************************************
*               Department of Electronic Engineering,					  *
* National Kaohsiung First University of Science and Technology           *      
*-------------------------------------------------------------------------*
*     Embedded Systems Development Project  with Wifi control             *
**************************************************************************/
/**************************************************************************                               
*@file uart.h                                                             *
*@author Chun-Wei                                                         *         
*@version 1.0,			                                                  *
**************************************************************************/
#ifndef _uart_h_
#define _uart_h_
/**************************************************************************
*   Parameter
**************************************************************************/
#define OSCILLATOR 11059200
/**************************************************************************
*   Macro
**************************************************************************/
#define getSbuf_1()   SBUF
#define setSbuf_1(x)   SBUF = x


void initialUart_1 (unsigned long baudRate);

extern void (*drv_uart_1_ti_handler) ( void );
extern void (*drv_uart_1_ri_handler) ( void );
#endif
