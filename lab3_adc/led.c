/**************************************************************************
*               Department of Electronic Engineering,					  *
* National Kaohsiung First University of Science and Technology           *      
*-------------------------------------------------------------------------*
*     Embedded Systems Development Project  with Wifi control             *
**************************************************************************/
/**************************************************************************                               
*@file led.c                                                              *
*@author Chun-Wei                                                         *         
*@version 1.0,			                                                  *
**************************************************************************/
#include "led.h"
/*------------------- The real LED address ------------------------------*/
sbit P2_7 = P2 ^ 7;
sbit P2_6 = P2 ^ 6;
sbit P2_5 = P2 ^ 5;
sbit P2_4 = P2 ^ 4;
sbit P2_3 = P2 ^ 3;
sbit P2_2 = P2 ^ 2;
sbit P2_1 = P2 ^ 1;
sbit P2_0 = P2 ^ 0;

#define HAL_LED_7 P2_7
#define HAL_LED_6 P2_6
#define HAL_LED_5 P2_5
#define HAL_LED_4 P2_4
#define HAL_LED_3 P2_3
#define HAL_LED_2 P2_2
#define HAL_LED_1 P2_1
#define HAL_LED_0 P2_0

/*--------------------------- Macros ------------------------------------*/
#define GET_LED(LED,STATE) ((LED)&~(STATE))?1:0				//check LED state is On/Off.
#define SET_LED(LED) HAL_##LED = GET_LED(##LED,LED_State)	//set real LED address to On/Off

/*---------------------- LED Parameters ---------------------------------*/
#define LED_ON 0
#define LED_OFF 1
#define LED_QUANTITY 8

unsigned char  xdata LED_State = 0;	//LED state-register

/*------------------------------------------------------------------------
*intial LED to all-off
------------------------------------------------------------------------*/
unsigned char initialLed(void){
	setLedOff(LED_0+LED_1+LED_2+LED_3+LED_4+LED_5+LED_6+LED_7);	//set all bit to zero
	LedRefresh();	//refresh state to real address
	return 1;	//return success
}//end of unsigned char initialLed(void)

/*------------------------------------------------------------------------
*set LED state-register to On.
------------------------------------------------------------------------*/
void setLedOn(unsigned char led){
    LED_State |= led;       //set LED trun on
	LedRefresh();
}//end of void setLedOn(unsigned char led)

/*------------------------------------------------------------------------
*set LED state-register to Off.
------------------------------------------------------------------------*/
void setLedOff(unsigned char led){
    LED_State &= ~led;      //set LED trun off
	LedRefresh();
}//end of void setLedOn(unsigned char led)

/*------------------------------------------------------------------------
*set LED state-register to Blink.
------------------------------------------------------------------------*/
void setLedBlink(unsigned char led){
    LED_State ^= led;      //set LED trun off
	LedRefresh();
}//end of void setLedBlink(unsigned char led)

/*------------------------------------------------------------------------
*Mapping LED state-register to Real LED address.
------------------------------------------------------------------------*/
void LedRefresh(void){
    SET_LED(LED_0);
    SET_LED(LED_1);
    SET_LED(LED_2);
    SET_LED(LED_3);
    SET_LED(LED_4);
    SET_LED(LED_5);
    SET_LED(LED_6);
    SET_LED(LED_7);
}//end of void setLedRefresh(void)

/*------------------------------------------------------------------------
*Mapping LED state-register to Real LED address.
------------------------------------------------------------------------*/
unsigned char getLedState(void){
    return LED_State;
}//end of unsigned char getLedState(void)
