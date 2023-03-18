/*
 * Flash.h
 *
 *  Created on: 19-Mar-2023
 *      Author: vicky
 */

#ifndef INC_FLASH_H_
#define INC_FLASH_H_

#include "../../TaskSchedular/Inc/main.h"


#define UPGRADE_APPLICATION_CHECK_ADDR 0x0803FFFC


uint8_t Execute_Flash_Erase(uint8_t sector_Number , uint8_t number_Of_Sector);
uint8_t Execute_Mem_Write(uint8_t *pBuffer, uint32_t mem_Address, uint32_t len);


#endif /* INC_FLASH_H_ */
