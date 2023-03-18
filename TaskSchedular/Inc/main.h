/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/*   BSP Includes */
#include "GPIO.h"
#include "TIM.h"
#include "SPI.h"
#include "CAN.h"
#include "I2C.h"
#include "UART.h"
#include "Flash.h"

/* Application Includes */

#include "../../SerialCommunication/Inc/SC_Process.h"
#include "FreeRTOS.h"
#include "task.h"
#include "MPU6050.h"


/*   Driver Function */

void Error_Handler(void);
void SystemClock_Config(void);

/*  RTOS Related Function Declaration */

void RTOS_Application(void);
void Non_RTOS_Application(void);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
