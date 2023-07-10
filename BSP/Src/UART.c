/*
 * UART.c
 *
 *  Created on: Dec 6, 2022
 *      Author: vicky
 */
#include "UART.h"



extern uint8_t rx_Buffer;
char byte_Available = 0;
extern UART_HandleTypeDef huart1;


void UART1_Init(UART_HandleTypeDef *huart1)
{
	huart1->Instance = USART1;
	huart1->Init.BaudRate = 115200;
	huart1->Init.WordLength = UART_WORDLENGTH_8B;
	huart1->Init.StopBits = UART_STOPBITS_1;
	huart1->Init.Parity = UART_PARITY_NONE;
	huart1->Init.Mode = UART_MODE_TX_RX;
	huart1->Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1->Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(huart1) != HAL_OK)
	{
		Error_Handler();
	}

}
void UART2_Init(UART_HandleTypeDef *huart2)
{
	huart2->Instance = USART2;
	huart2->Init.BaudRate = 115200;
	huart2->Init.WordLength = UART_WORDLENGTH_8B;
	huart2->Init.StopBits = UART_STOPBITS_1;
	huart2->Init.Parity = UART_PARITY_NONE;
	huart2->Init.Mode = UART_MODE_TX_RX;
	huart2->Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2->Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(huart2) != HAL_OK)
	{
		Error_Handler();
	}

}

void UART3_Init(UART_HandleTypeDef *huart3)
{
	huart3->Instance = USART3;
	huart3->Init.BaudRate = 115200;
	huart3->Init.WordLength = UART_WORDLENGTH_8B;
	huart3->Init.StopBits = UART_STOPBITS_1;
	huart3->Init.Parity = UART_PARITY_NONE;
	huart3->Init.Mode = UART_MODE_TX_RX;
	huart3->Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart3->Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(huart3) != HAL_OK)
	{
		Error_Handler();
	}

}


void Print_Msg(char *format,...)
{
	char tx_Buffer[3000];
	/*Extract the the argument list using VA APIS */
	va_list args;
	va_start(args, format);
	vsprintf(tx_Buffer, format,args);
	//HAL_UART_Transmit_IT(&huart1,(uint8_t *)tx_Buffer, strlen(tx_Buffer));
	HAL_UART_Transmit(&huart1,(uint8_t *)tx_Buffer, strlen(tx_Buffer), HAL_MAX_DELAY);
	va_end(args);
}
inline void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	byte_Available = 1;
	HAL_UART_Receive_IT(&huart1, (uint8_t*)&rx_Buffer, 1);
}
inline void UART_Receive(UART_HandleTypeDef *huart, char *tmp_Rx_Buffer)
{
	HAL_UART_Receive(huart, (uint8_t*)tmp_Rx_Buffer, 1, 100);
}
inline void UART_Interrupt_Start(UART_HandleTypeDef *huart, char *tmp_Rx_Buffer)
{
	HAL_UART_Receive_IT(huart, (uint8_t*)tmp_Rx_Buffer, 1);
}
inline void UART_Get_Rx_Byte(char *tmp_Rx_Buffer, uint8_t size)
{

	*tmp_Rx_Buffer = rx_Buffer;
	byte_Available = 0;
}
inline int8_t UART_Rx_Byte_Available(void)
{
	return byte_Available;
}
inline uint16_t UART_Get_Tx_Byte_Count(void)
{
	return huart1.TxXferCount;
}

