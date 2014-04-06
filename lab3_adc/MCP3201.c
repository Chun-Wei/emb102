/**************************************************************************               
*               Department of Electronic Engineering,
* National Kaohsiung First University of Science and Technology                 
*-------------------------------------------------------------------------
**************************************************************************/
/**************************************************************************                               
*@file MCP3201.c                                                            
*@author Chun-Wei                                                                  
*@version 1.0, 14/04/04                               
**************************************************************************/
#include "MCP3201.h"
sbit    CS    =   P3^7;   //chip select pin at P3.6
sbit    DIN    =   P3^6;   //Data in pin at P3.6
sbit    SCLK    =   P3^5;   //serial clock pin at P3.6


unsigned char initialAdc(void){
	//---SPI mode-0 setting------
	CS = 1;
    DIN = 1;
    SCLK = 0;
	return 1;
}

unsigned char getAdcDataHi8(void){
    unsigned char i;
    unsigned char temp = 0;
	CS = 0;
    for(i=0;i<11;i++){
        temp <<=1;
		SCLK = 1;
        if(DIN){
            temp += 1;
        }   
		SCLK = 0;
    }//end of for-i
	CS = 1;
    return temp;
}//end of unsigned char getSpiDataHi8(void)


unsigned int getAdcData(void){
	unsigned char i;
    unsigned int temp = 0;
	CS = 0;
    for(i=0;i<15;i++){
        temp <<=1;
		SCLK = 1;
        if(DIN){
            temp += 1;
        }   
		SCLK = 0;
    }//end of for-i
	CS = 1;
    return 0x0fff & temp;
}//end of unsigned int getSpiData(void)

