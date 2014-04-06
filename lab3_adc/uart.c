/**************************************************************************               
*               Department of Electronic Engineering,
* National Kaohsiung First University of Science and Technology                 
*-------------------------------------------------------------------------
*                       STC5A60S2-uart functions
*                            Imprement
**************************************************************************/
/**************************************************************************                               
*@file uart.c                                                            
*@author Chun-Wei                                                                  
*@version 1.0,                        
**************************************************************************/
#include "uart.h"
#include <reg51.h>

/**************************************************************************
*   SFR Registers
**************************************************************************/
//--- SCON register ---
#define MODE_0 0x00
#define MODE_1 0x40
#define MODE_2 0x80
#define MODE_3 0xC8
#define ReciveEN 0x10

//--- TCON register ---
#define T1_GATE 0x80
#define T1_CT 0x40
#define T1_MODE0 0x00
#define T1_MODE1 0x10
#define T1_MODE2 0x20
#define T1_MODE3 0x30

//--- interrupt register ---
#define UART_INTR_EN 0x10

/**************************************************************************
*   Interrupt Function
**************************************************************************/
void UART_1_INTR(void) interrupt 4{
    EA = 0;				//disable all interrupt
    //---if TI do user's TI intr function---
	if ( TI ){
        TI = 0;
        if ( 0 != drv_uart_1_ti_handler )	//if TI funcion is not NULL
            (*drv_uart_1_ti_handler)();
    }//end of if ( TI )
    //---if RI do user's RI intr function---
    if ( RI ){
        RI = 0;
        if ( 0 != drv_uart_1_ri_handler )	//if RI funcion is not NULL
            (*drv_uart_1_ri_handler)();   
    }//end of if (RI)
 
    EA = 1;				//ensable all interrupt
}//end of void UART_INTR(void) interrupt 4

void initialUart_1 (unsigned long baudRate){
    SCON |= MODE_1 + ReciveEN; //set serial port work at mode-1 and enable receive function
	TI = 0; //clear transfer flag
	RI = 0; //clear receiver flag
	//---uart1 use Timer1--------
	TMOD |= T1_MODE2; //set timer 1 work at mode-1
	TH1 = 256 - (OSCILLATOR / 384) / baudRate; //set timer 1's duty cycles
	TR1 = 1; //timer 1 enable    
    IE|=UART_INTR_EN;	//enable uart1 interrupt
}

void (*drv_uart_1_ti_handler) ( void ) = 0;
void (*drv_uart_1_ri_handler) ( void ) = 0;
