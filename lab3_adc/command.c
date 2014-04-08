/**************************************************************************               
*               Department of Electronic Engineering,
* National Kaohsiung First University of Science and Technology                 
*-------------------------------------------------------------------------
*                       STC5A60S2-uart functions
*                            Imprement
**************************************************************************/
/**************************************************************************                               
*@file command.c                                                            
*@author Chun-Wei                                                                  
*@version 1.0,                        
**************************************************************************/
#include "command.h"
#include "uart.h"
#include <string.h>
#include <reg51.h>

/**************************************************************************
*   SFR Registers
**************************************************************************/
code char* Commands[] = {"D0","D1","D2", "D3", "D4", "D5", "D6", "D7","ERROR"};

/**************************************************************************
*   Interrupt Function
**************************************************************************/
unsigned char RxIsFinish = 0;
unsigned char RxCnt = 0;
char cmdBuf[COMMAND_BUF_SIZE];
void commandRx_INTR(void){
	if(!RxIsFinish){
		cmdBuf[RxCnt] = getSbuf_1();
		if((cmdBuf[RxCnt]=='\n')||(cmdBuf[RxCnt]=='\0')){
			RxIsFinish = 1;
		}
		if(RxCnt < COMMAND_BUF_SIZE - 1){
			RxCnt++;
		}
	}
}//end of void commandRx_INTR(void)

unsigned char TxIsBusy = 0;
void commandTx_INTR(void){
	TxIsBusy = 0;
}//end of void commandRx_INTR(void)
/**************************************************************************
*   Functions
**************************************************************************/
void initialCommand (void){
	initialUart_1(9600);
	TxIsBusy = 0;
	drv_uart_1_ti_handler = commandTx_INTR;
	drv_uart_1_ri_handler = commandRx_INTR;
}

void sentChar(char dat){
	while(TxIsBusy);
	setSbuf_1(dat);
	TxIsBusy = 1;
}

void sentString(char* str){
	while((*str != '\0')&&(*str != '\n')){
		sentChar(*str);
		str++;
	}
	sentChar('\n');
}

void getString(cmd* buf){
	unsigned char i=0;
	for(i=0;i<COMMAND_BUF_SIZE;i++){
		buf->cmd[i] = cmdBuf[i];
	}
	RxCnt = 0;
	RxIsFinish = 0;
}

unsigned char CmdIsFinish(void){
	return RxIsFinish;
}

unsigned char getCommand(void){
	int i = 0;
	for (i = 0;(i < CMD_NUM)&&strncmp(cmdBuf,Commands[i],strlen(Commands[i]));i++);
	RxCnt = 0;
	RxIsFinish = 0;
   return i;
}

