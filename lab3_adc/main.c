/**************************************************************************
*                       (C)2014 CCJR-LAB                  				  *
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


void main(void){
	unsigned char led = 0;
	initialLed();

	while(1){
		if(led > 0){
			led <<= 1;
		} else {
			led = LED_0;
		}
		setLedBlink(led);
	}//end of main-loop
}//end of main