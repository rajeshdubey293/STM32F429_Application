/*
 * I2C.h
 *
 *  Created on: Dec 6, 2022
 *      Author: vicky
 */

#ifndef INC_I2C_H_
#define INC_I2C_H_

#include "../../TaskSchedular/Inc/main.h"

void I2C1_Init(I2C_HandleTypeDef *hi2c1);
void I2C2_Init(I2C_HandleTypeDef *hi2c2);
void I2C3_Init(I2C_HandleTypeDef *hi2c3);

void I2C_Mem_Write(I2C_HandleTypeDef *hi2c,uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData,
		uint16_t Size);
void I2C_Mem_Read(I2C_HandleTypeDef *hi2c,uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData,
		uint16_t Size);

void I2C_Write(I2C_HandleTypeDef *hi2c,uint16_t DevAddress, uint8_t *pData, uint16_t Size);
void I2C_Read(I2C_HandleTypeDef *hi2c,uint16_t DevAddress, uint8_t *pData, uint16_t Size);
#endif /* INC_I2C_H_ */
