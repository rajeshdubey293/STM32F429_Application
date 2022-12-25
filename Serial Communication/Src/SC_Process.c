/*
 * SC_Process.c
 *
 *  Created on: 16-Dec-2022
 *      Author: vicky
 */
#include "SC_Process.h"

char sc_Rx_Buffer;

char LED1_ON_FLAG = 0;
char LED2_ON_FLAG = 0;
uint8_t i = 0;

SC_Decode_Main_Menu sc_Option = MAIN_MENU_UNKNOWN;
SC_Decode_Debug sc_Debug_Option = DEBUG_MENU_UNKNOWN;
SC_User_Decode sc_User_State = USER_UNKNOWN;

char user_Name_Array[10] = {0};
char user_Pass_Array[10] = {0};

char *user_Name = "admin";
char *user_Pass = "password";

char *sw_Version = "V1.0 Beta\r\n";

void SC_Process(void)
{
	if(Authenticated_User() != USER_AUTHENICATED)
	{
		return;
	}
	if(UART_Rx_Byte_Available())
	{
		UART_Get_Rx_Byte(&sc_Rx_Buffer, 1);
		if(sc_Option == MAIN_MENU)
		{
			sc_Option = sc_Rx_Buffer;
		}
		switch(sc_Option)
		{
		case DEBUG_MODE:
			Debug_Menu_Decode(sc_Rx_Buffer);
			if(sc_Debug_Option == DEBUG_MENU_UNKNOWN)
			{
				Show_Main_Menu();
				sc_Option = MAIN_MENU;
			}
			break;
		case BOOTLOADER_MODE:
			break;
		case EXIT:
			sc_Option = MAIN_MENU_UNKNOWN;
			sc_User_State = USER_UNKNOWN;
			Print_Msg("Exited \r\n");
			break;
		case MAIN_MENU_UNKNOWN:
			Show_Main_Menu();
			sc_Option = MAIN_MENU;
			break;
		default:
			Print_Msg("Invalid Options\r\n");
			Show_Main_Menu();
			sc_Option = MAIN_MENU;
		}
	}
}

void Show_Debug_Menu(void)
{
	Print_Msg("******* STM32F4 Debug Menu *******\r\n\n");
	Print_Msg("\t1. System Information \r\n");
	Print_Msg("\t2. Turn On Red LED \r\n");
	Print_Msg("\t3. Turn OFF Red LED \r\n");
	Print_Msg("\t4. Turn ON Green LED \r\n");
	Print_Msg("\t5. Turn OFF Green LED \r\n");
	Print_Msg("\t6. Software Version \r\n");
	Print_Msg("\t7. Change User Password \r\n");
	Print_Msg("\t8. Reserved for Future Use \r\n");
	Print_Msg("\t9. Back To Main Menu\r\n\n");
	//Print_Msg("*********************************************\r\n\n");
	Print_Msg("**********************************\r\n\n");
}
void Show_Main_Menu(void)
{
	Print_Msg("******* STM32F4 Main Menu *******\r\n\n");
	Print_Msg("\t1. Enter Debug Mode \r\n");
	Print_Msg("\t2. Upgrade Application \r\n");
	Print_Msg("\tx. Exit \r\n\n");
	Print_Msg("*********************************\r\n\n");

}
void Debug_Menu_Decode(char debug_Option)
{
	if(sc_Debug_Option == DEBUG_MENU)
	{
		sc_Debug_Option = debug_Option;
	}
	switch(sc_Debug_Option)
	{
	case SYS_INFO:
		Print_Msg("STM32F429 Discovery Board \r\n");
		sc_Debug_Option = DEBUG_MENU;
		break;

	case LED1_ON:
		LED1_ON_FLAG = 1;
		Print_Msg("Green LED is ON\r\n");
		sc_Debug_Option = DEBUG_MENU;
		break;

	case LED1_OFF:
		LED1_ON_FLAG = 1;
		Print_Msg("Green LED is OFF\r\n");
		sc_Debug_Option = DEBUG_MENU;
		break;

	case LED2_ON:
		LED2_ON_FLAG = 1;
		Print_Msg("Red LED is ON\r\n");
		sc_Debug_Option = DEBUG_MENU;
		break;

	case LED2_OFF:
		LED2_ON_FLAG = 1;
		Print_Msg("Red LED is OFF\r\n");
		sc_Debug_Option = DEBUG_MENU;
		break;

	case SOFTWARE_VERSION:
		Print_Msg("%s", sw_Version);
		sc_Debug_Option = DEBUG_MENU;
		break;

	case CHANGE_PASS:
		break;

	case RET_MAIN_MENU:
		sc_Debug_Option = DEBUG_MENU_UNKNOWN;
		break;

	case DEBUG_MENU_UNKNOWN:
		Show_Debug_Menu();
		sc_Debug_Option = DEBUG_MENU;
		break;

	default:
		Print_Msg("Invalid Debug Option \r\n");
		Show_Debug_Menu();
		sc_Debug_Option = DEBUG_MENU;
		break;
	}
}
SC_User_Decode Authenticated_User(void)
{
	if(UART_Rx_Byte_Available())
	{

		switch(sc_User_State)
		{
		case USER_NAME:
			UART_Get_Rx_Byte(&sc_Rx_Buffer, 1);
			if( (sc_Rx_Buffer != '\r') && (sc_Rx_Buffer != '\n'))
			{
				Print_Msg("%c", sc_Rx_Buffer);
				user_Name_Array[i++] = sc_Rx_Buffer;
			}
			else
			{
				user_Name_Array[i] = '\0';
				sc_User_State = USER_PASS;
				i = 0;
				Print_Msg("\r\nUser Password: ");
			}
			break;
		case USER_PASS:
			UART_Get_Rx_Byte(&sc_Rx_Buffer, 1);
			if( (sc_Rx_Buffer != '\r') && (sc_Rx_Buffer != '\n'))
			{
				user_Pass_Array[i++] = sc_Rx_Buffer;
				sc_Rx_Buffer = '*';
				Print_Msg("%c", sc_Rx_Buffer);
			}
			else
			{
				user_Pass_Array[i] = '\0';
				if ( (strcmp(user_Name, user_Name_Array) == 0)
						&& (strcmp(user_Pass, user_Pass_Array) == 0) )
				{
					sc_User_State = USER_AUTHENICATED;
					Print_Msg("\r\nUser Authenticated\r\n");
				}
				else
				{
					Print_Msg("\r\nWrong User Name and Password\r\n");
					sc_User_State = USER_UNKNOWN;
				}
			}
			break;
		case USER_AUTHENICATED:
			sc_User_State = USER_AUTHENICATED;
			break;
		case USER_UNKNOWN:
			UART_Get_Rx_Byte(&sc_Rx_Buffer, 1);
			Print_Msg("User Name: ");
			sc_User_State = USER_NAME;
			i = 0;
			break;
		default:
			sc_User_State = USER_UNKNOWN;
			break;
		}
	}

	return sc_User_State;
}
