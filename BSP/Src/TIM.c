/*
 * TIM.c
 *
 *  Created on: 15-Dec-2022
 *      Author: vicky
 */
#include "TIM.h"



volatile uint32_t sysTick = 0;;

/*
 * Timer init function
 */
void TIMER6_Init(TIM_HandleTypeDef *htim6)
{
	htim6->Instance = TIM6;
	htim6->Init.Prescaler = 1;
	htim6->Init.Period = 20000-1;
	if(HAL_TIM_Base_Init(htim6) != HAL_OK)
	{
		Error_Handler();
	}
}

inline void TIMER_Start(TIM_HandleTypeDef *htim)
{
	HAL_TIM_Base_Start(htim);
}

inline void TIMER_Start_IT(TIM_HandleTypeDef *htim)
{
	HAL_TIM_Base_Start_IT(htim);
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
