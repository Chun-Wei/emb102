/**************************************************************************
*               Department of Electronic Engineering,					  *
* National Kaohsiung First University of Science and Technology           *      
*-------------------------------------------------------------------------*
*     Embedded Systems Development Project  with Wifi control             *
**************************************************************************/
/**************************************************************************                               
*@file main.c                                                             *
*@author Chun-Wei                                                         *         
*@version 1.0,			                                                  *
**************************************************************************/
/**************************************************************************
 *   include libs
 **************************************************************************/
#include <reg51.h>
#include "led.h"
#include "uart.h"
#include "MCP3201.h"

void delay_ms(unsigned int ms);

void isr_RXD_1 (void) {
    setSbuf_1(getSbuf_1());
}

void main(void){
	unsigned char led = 0;
	unsigned char temp = 0;
	unsigned int adc = 0;
	
	initialLed();
	initialUart_1(9600);
	initialAdc();
	drv_uart_1_ri_handler = isr_RXD_1;
	EA = 1;	//enable all interrupt
	while(1){
		adc = getAdcDataHi8();
		setLedOff(0xff);
		setLedOn(0x00ff&adc);
		adc = getAdcData();
		
		temp = adc>>8;
		setSbuf_1(temp);
		delay_ms(2);
		temp = 0x00ff&adc;
		setSbuf_1(temp);
		delay_ms(500);
	}//end of main-loop
}//end of main

void delay_ms(unsigned int ms){
    unsigned int i,j;
    for(i=0;i<ms;i++){
        for(j=0;j<120;j++);
    }
}