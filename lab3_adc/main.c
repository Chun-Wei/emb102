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
#include <stdio.h>
#include "led.h"
#include "uart.h"
#include "command.h"
#include "MCP3201.h"

/**************************************************************************
 *   control defines
 **************************************************************************/
//---LED states-------------------------------------
sbit LED = P2 ^ 0; //define button at P2_0
#define LED_ON	0x0
#define LED_OFF	0x1
//---BUTTON states-------------------------------------
sbit BUTTON = P3 ^ 3; //define button at P3_3
#define BUTTON_IS_PUSHED	0x0
#define BUTTON_NON_PUSHED	0x1


void main(void){
	unsigned char temp = 0;
	unsigned char butCnt = 0;
	unsigned char tempStr[20];
	unsigned int preAdc,postAdc = 0;
	
	initialLed();
	initialCommand();
	initialAdc();
	EA = 1;	//enable all interrupt
	while(1){
		//---Button checks----------------------------------
		BUTTON = BUTTON_NON_PUSHED; //try button is pushed?
		if (BUTTON == BUTTON_IS_PUSHED) {
			if(butCnt==200){
				sentString("B\n");
				butCnt++;
			} else if(butCnt<200) {
				butCnt++;
			}
		} else {
			butCnt = 0;
		}//end of if(BUTTON == BUTTON_IS_PUSHED)
		
		//---Command process---------------------------------
		if(CmdIsFinish()){
			temp = getCommand();
			switch(temp){
				case CMD_D0:
					setLedBlink(LED_0);
					break;
				case CMD_D1:
					setLedBlink(LED_1);
					break;
				case CMD_D2:
					setLedBlink(LED_2);
					break;
				case CMD_D3:
					setLedBlink(LED_3);
					break;
				case CMD_D4:
					setLedBlink(LED_4);
					break;
				case CMD_D5:
					setLedBlink(LED_5);
					break;
				case CMD_D6:
					setLedBlink(LED_6);
					break;
				case CMD_D7:
					setLedBlink(LED_7);
					break;
				default:
					break;
			}
		}
		
		//---Adc process----------------------------------
		postAdc = getAdcData();
		//postAdc &= 0x00ff;
		if(preAdc!=postAdc){
			preAdc = postAdc;
			sprintf (tempStr,"ADC:%d\n",preAdc);
			sentString(tempStr);
		}
		
	}//end of main-loop
}//end of main
