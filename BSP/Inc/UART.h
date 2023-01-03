/*
 * UART.h
 *
 *  Created on: Dec 6, 2022
 *      Author: vicky
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "../../TaskSchedular/Inc/main.h"

void UART1_Init(UART_HandleTypeDef *huart1);
void UART2_Init(UART_HandleTypeDef *huart2);
void UART3_Init(UART_HandleTypeDef *huart3);


void Print_Msg(char *format,...);

void UART_Interrupt_Start(UART_HandleTypeDef *huart, char *tmp_Rx_Buffer);
void UART_Receive(UART_HandleTypeDef *huart, char *tmp_Rx_Buffer);

void UART_Get_Rx_Byte(char *tmp_Rx_Buffer, uint8_t size);
int8_t UART_Rx_Byte_Available(void);

#endif /* INC_UART_H_ */
