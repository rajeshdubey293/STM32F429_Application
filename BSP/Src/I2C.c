/*
 * I2C.c
 *
 *  Created on: Dec 6, 2022
 *      Author: vicky
 */

#include "I2C.h"

void I2C1_Init(I2C_HandleTypeDef *hi2c1)
{
	hi2c1->Instance = I2C1;
	hi2c1->Init.ClockSpeed = 400000;
	hi2c1->Init.DutyCycle = I2C_DUTYCYCLE_2;
	hi2c1->Init.OwnAddress1 = 0;
	hi2c1->Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c1->Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c1->Init.OwnAddress2 = 0;
	hi2c1->Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c1->Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	if (HAL_I2C_Init(hi2c1) != HAL_OK)
	{
		Error_Handler();
	}

	/** Configure Analogue filter
	 */
	if (HAL_I2CEx_ConfigAnalogFilter(hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
	{
		Error_Handler();
	}

	/** Configure Digital filter
	 */
	if (HAL_I2CEx_ConfigDigitalFilter(hi2c1, 0) != HAL_OK)
	{
		Error_Handler();
	}

}
void I2C2_Init(I2C_HandleTypeDef *hi2c2)
{
	hi2c2->Instance = I2C2;
	hi2c2->Init.ClockSpeed = 100000;
	hi2c2->Init.DutyCycle = I2C_DUTYCYCLE_2;
	hi2c2->Init.OwnAddress1 = 0;
	hi2c2->Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c2->Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c2->Init.OwnAddress2 = 0;
	hi2c2->Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c2->Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	if (HAL_I2C_Init(hi2c2) != HAL_OK)
	{
		Error_Handler();
	}

	/** Configure Analogue filter
	 */
	if (HAL_I2CEx_ConfigAnalogFilter(hi2c2, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
	{
		Error_Handler();
	}

	/** Configure Digital filter
	 */
	if (HAL_I2CEx_ConfigDigitalFilter(hi2c2, 0) != HAL_OK)
	{
		Error_Handler();
	}

}
void I2C3_Init(I2C_HandleTypeDef *hi2c3)
{
	hi2c3->Instance = I2C3;
	hi2c3->Init.ClockSpeed = 100000;
	hi2c3->Init.DutyCycle = I2C_DUTYCYCLE_2;
	hi2c3->Init.OwnAddress1 = 0;
	hi2c3->Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c3->Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c3->Init.OwnAddress2 = 0;
	hi2c3->Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c3->Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	if (HAL_I2C_Init(hi2c3) != HAL_OK)
	{
		Error_Handler();
	}

	/** Configure Analogue filter
	 */
	if (HAL_I2CEx_ConfigAnalogFilter(hi2c3, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
	{
		Error_Handler();
	}

	/** Configure Digital filter
	 */
	if (HAL_I2CEx_ConfigDigitalFilter(hi2c3, 0) != HAL_OK)
	{
		Error_Handler();
	}

}
inline void I2C_Mem_Write(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData,
		uint16_t Size)
{
	HAL_I2C_Mem_Write(hi2c, DevAddress, MemAddress, MemAddSize, pData, Size, 100);
}
inline void I2C_Mem_Read(I2C_HandleTypeDef *hi2c,uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData,
		uint16_t Size)
{
	HAL_I2C_Mem_Read(hi2c, DevAddress, MemAddress, MemAddSize, pData, Size, 100);
}
inline void I2C_Write(I2C_HandleTypeDef *hi2c,uint16_t DevAddress, uint8_t *pData, uint16_t Size)
{
	HAL_I2C_Master_Transmit(hi2c, DevAddress, pData, Size, 100);
}
inline void I2C_Read(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size)
{
	HAL_I2C_Master_Receive(hi2c, DevAddress, pData, Size, 100);
}
