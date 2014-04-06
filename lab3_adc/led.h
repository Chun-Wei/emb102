/**************************************************************************
*                       (C)2014 CCJR-LAB                  				  *
*               Department of Electronic Engineering,					  *
* National Kaohsiung First University of Science and Technology           *      
*-------------------------------------------------------------------------*
*     Embedded Systems Development Project  with Wifi control             *
**************************************************************************/
/**************************************************************************                               
*@file led.h                                                              *
*@author Chun-Wei                                                         *         
*@version 1.0,			                                                  *
**************************************************************************/
#ifndef _led_h
#define _led_h
#include "reg51.h"

//---LED Address define---
#define LED_NUM 8
#define LED_7 0x80
#define LED_6 0x40
#define LED_5 0x20
#define LED_4 0x10
#define LED_3 0x08
#define LED_2 0x04
#define LED_1 0x02
#define LED_0 0x01

/************************************************************************
*@brief Initial LED to all off
*@return initial state ,1 = success, else = fail
*@param void
*@since 1.0
************************************************************************/
unsigned char initialLed(void);

/************************************************************************
*@brief set LED state-register to On.         
*@return void
*@param (unsigned char)led      LED address.                                                  
*@since 1.0
*@example setLedOn(LED_1+LED_3+LED_5);   
************************************************************************/
void setLedOn(unsigned char led);

/***********************************************************************
*@brief set LED state-register to Off.         
*@return void
*@param (unsigned char)led      LED address.        
*@since 1.0
*@example setLedOff(LED_2+LED_4+LED_6);
***********************************************************************/
void setLedOff(unsigned char led);

/***********************************************************************
*@brief set LED state-register to Blink.         
*@return void
*@param (unsigned char)led      LED address.        
*@since 1.0
*@example setLedBlink(LED_2+LED_4+LED_6);
***********************************************************************/
void setLedBlink(unsigned char led);

/***********************************************************************
*@brief mapping LED state register to real LED           
*@return void
*@param void      
*@since 1.0
***********************************************************************/
void LedRefresh(void);

/***********************************************************************
*@brief get LED state-register value.         
*@return unsigned char LED state-register value
*@param void        
*@since 1.1
*@example unsigned char temp = getLedState();
***********************************************************************/
unsigned char getLedState(void);


#endif