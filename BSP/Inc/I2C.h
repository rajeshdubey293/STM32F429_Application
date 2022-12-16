/*
 * I2C.h
 *
 *  Created on: Dec 6, 2022
 *      Author: vicky
 */

#ifndef INC_I2C_H_
#define INC_I2C_H_

#include "main.h"

void I2C_Init(void);


void I2C_Read(uint16_t DevAddress, uint8_t *pData, uint16_t Size);
void I2C_Mem_Write(uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData,
		uint16_t Size);
void I2C_Mem_Read(uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData,
		uint16_t Size);

void I2C_Write(uint16_t DevAddress, uint8_t *pData, uint16_t Size);
void I2C_Read(uint16_t DevAddress, uint8_t *pData, uint16_t Size);
#endif /* INC_I2C_H_ */
