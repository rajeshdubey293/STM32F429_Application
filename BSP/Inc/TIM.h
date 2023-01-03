/*
 * TIM.h
 *
 *  Created on: 15-Dec-2022
 *      Author: vicky
 */

#ifndef INC_TIM_H_
#define INC_TIM_H_

#include "../../TaskSchedular/Inc/main.h"


void TIMER6_Init(TIM_HandleTypeDef *htim6);

void TIMER_Start(TIM_HandleTypeDef *htim);
void TIMER_Start_IT(TIM_HandleTypeDef *htim);

void SysTick_Set(uint8_t tmpSysTick);
uint32_t SysTick_Get(void);


#endif /* INC_TIM_H_ */
