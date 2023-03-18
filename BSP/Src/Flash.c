/*
 * Flash.c
 *
 *  Created on: 19-Mar-2023
 *      Author: vicky
 */


#include "Flash.h"

uint8_t Execute_Mem_Write(uint8_t *pBuffer, uint32_t mem_Address, uint32_t len)
{
	uint8_t status_Flash = HAL_OK;

	//We have to unlock flash module to get control of registers
	HAL_FLASH_Unlock();

	for(uint32_t i = 0 ; i < len ; i++)
	{
		//Here we program the flash byte by byte
		status_Flash = HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE,mem_Address+i,pBuffer[i] );
	}
	HAL_FLASH_Lock();

	return status_Flash;
}

uint8_t Execute_Flash_Erase(uint8_t sector_Number , uint8_t number_Of_Sector)
{
	//we have totally 12 sectors in STM32F407VG mcu .. sector[0 to 11]
	//number_of_sector has to be in the range of 0 to 11
	// if sector_number = 0xff , that means mass erase !
	//Code needs to modified if your MCU supports more flash sectors
	FLASH_EraseInitTypeDef flash_Erase_Handle;
	uint32_t sector_Error;
	HAL_StatusTypeDef status_Flash;


	if( number_Of_Sector > 12 )
		return 1;

	if( (sector_Number == 0xff ) || (sector_Number <= 11) )
	{
		if(sector_Number == (uint8_t) 0xff)
		{
			flash_Erase_Handle.TypeErase = FLASH_TYPEERASE_MASSERASE;
		}else
		{
			/*Here we are just calculating how many sectors needs to erased */
			uint8_t remanining_Sector = 12 - sector_Number;
			if( number_Of_Sector > remanining_Sector)
			{
				number_Of_Sector = remanining_Sector;
			}
			flash_Erase_Handle.TypeErase = FLASH_TYPEERASE_SECTORS;
			flash_Erase_Handle.Sector = sector_Number; // this is the initial sector
			flash_Erase_Handle.NbSectors = number_Of_Sector;
		}
		flash_Erase_Handle.Banks = FLASH_BANK_1;

		/*Get access to touch the flash registers */
		HAL_FLASH_Unlock();
		flash_Erase_Handle.VoltageRange = FLASH_VOLTAGE_RANGE_3;  // our mcu will work on this voltage range
		status_Flash = (uint8_t) HAL_FLASHEx_Erase(&flash_Erase_Handle, &sector_Error);
		HAL_FLASH_Lock();

		return status_Flash;
	}


	return 1;
}
