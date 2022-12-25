/*
 * TIM.c
 *
 *  Created on: 15-Dec-2022
 *      Author: vicky
 */
#include "TIM.h"

TIM_HandleTypeDef htim6;

volatile uint32_t sysTick = 0;;

/*
 * Timer init function
 */
void Timer_Init(TIM_TypeDef *Timer)
{
	htim6.Instance = Timer;
	htim6.Init.Prescaler = 1;
	htim6.Init.Period = 20000-1;
	if(HAL_TIM_Base_Init(&htim6) != HAL_OK)
	{
		Error_Handler();
	}
}

inline void Timer_Start(void)
{
	HAL_TIM_Base_Start(&htim6);
}

inline void Timer_Start_IT(void)
{
	HAL_TIM_Base_Start_IT(&htim6);
}

inline void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM7) {
		HAL_IncTick();
	}
	if (htim->Instance == TIM6) {
		sysTick++;
	}

}
inline uint32_t SysTick_Get(void)
{
	return sysTick;
}
inline void SysTick_Set(uint8_t tmpSysTick)
{
	sysTick = (uint32_t)tmpSysTick;
}
