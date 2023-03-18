/*
 * SC_Process.h
 *
 *  Created on: 16-Dec-2022
 *      Author: vicky
 */

#ifndef INC_SC_PROCESS_H_
#define INC_SC_PROCESS_H_

#include "../../TaskSchedular/Inc/main.h"



typedef enum {
	DEBUG_MODE = '1',
	BOOTLOADER_MODE,
	EXIT = 'x',
	MAIN_MENU_UNKNOWN,
	MAIN_MENU = '\r',

}SC_Decode_Main_Menu;

typedef enum
{
	SYS_INFO = '1',
	LED1_ON,
	LED1_OFF,
	LED2_ON,
	LED2_OFF,
	SOFTWARE_VERSION,
	CHANGE_PASS,
	MPU6050,
	RET_MAIN_MENU = '9',
	DEBUG_MENU_UNKNOWN,
	DEBUG_MENU
}SC_Decode_Debug;

typedef enum
{
	USER_NAME = '1',
	USER_PASS,
	USER_AUTHENICATE,
	USER_AUTHENICATED,
	USER_UNKNOWN
}SC_User_Decode;

typedef enum
{
	DISPLAY_MPU_DATA = '1',
	FALSE

}SC_Process_Debug_Code;

void SC_Process(void);
void Debug_Menu_Decode(char debug_Option);
void Show_Main_Menu(void);
void SC_Check_Debug_Code(void);
SC_User_Decode Authenticated_User(void);
void Boot_Into_Bootloader();



#endif /* INC_SC_PROCESS_H_ */
