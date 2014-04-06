/**************************************************************************
*               Department of Electronic Engineering,					  *
* National Kaohsiung First University of Science and Technology           *      
*-------------------------------------------------------------------------*
*     Embedded Systems Development Project  with Wifi control             *
**************************************************************************/
/**************************************************************************                               
*@file command.h                                                          *
*@author Chun-Wei                                                         *         
*@version 1.0,			                                                  *
**************************************************************************/
#ifndef _command_h_
#define _command_h_
/**************************************************************************
*   Parameter
**************************************************************************/
#define COMMAND_BUF_SIZE 20
#define CMD_NUM	8
#define CMD_D7	7
#define CMD_D6	6
#define CMD_D5	5
#define CMD_D4	4
#define CMD_D3	3
#define CMD_D2	2
#define CMD_D1	1
#define CMD_D0	0

typedef struct CMD {
	char cmd[COMMAND_BUF_SIZE];
} cmd;

void initialCommand (void);
void sentChar(char dat);
void sentString(char* str);
void getString(cmd* buf);
unsigned char getCommand(void);
unsigned char CmdIsFinish(void);

#endif
