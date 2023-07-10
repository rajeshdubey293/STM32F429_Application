/*
 * Flash.c
 *
 *  Created on: 19-Mar-2023
 *      Author: vicky
 */


#include "Flash.h"
static uint32_t GetSector(uint32_t Address);
static uint32_t GetSectorSize(uint32_t Sector);

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

uint8_t Execute_Flash_Erase(uint32_t address , uint8_t number_Of_Sector)
{
	uint32_t FirstSector = 0, sector_Error = 0;
	FLASH_EraseInitTypeDef flash_Erase_Handle;
	HAL_StatusTypeDef status_Flash;

	/* Get the 1st sector to erase */
	FirstSector = GetSector(address);

	flash_Erase_Handle.TypeErase = FLASH_TYPEERASE_SECTORS;
	flash_Erase_Handle.Sector = FirstSector; // this is the initial sector
	flash_Erase_Handle.NbSectors = number_Of_Sector;
	flash_Erase_Handle.Banks = FLASH_BANK_2;
	flash_Erase_Handle.VoltageRange = FLASH_VOLTAGE_RANGE_3;  // our mcu will work on this voltage range

	/*Get access to touch the flash registers */
	HAL_FLASH_Unlock();
	status_Flash = HAL_FLASHEx_Erase(&flash_Erase_Handle, &sector_Error);
	HAL_FLASH_Lock();

	return status_Flash;
}
/**
 * @brief  Gets the sector of a given address
 * @param  None
 * @retval The sector of a given address
 */
static uint32_t GetSector(uint32_t Address)
{
	uint32_t sector = 0;

	if((Address < ADDR_FLASH_SECTOR_1) && (Address >= ADDR_FLASH_SECTOR_0))
	{
		sector = FLASH_SECTOR_0;
	}
	else if((Address < ADDR_FLASH_SECTOR_2) && (Address >= ADDR_FLASH_SECTOR_1))
	{
		sector = FLASH_SECTOR_1;
	}
	else if((Address < ADDR_FLASH_SECTOR_3) && (Address >= ADDR_FLASH_SECTOR_2))
	{
		sector = FLASH_SECTOR_2;
	}
	else if((Address < ADDR_FLASH_SECTOR_4) && (Address >= ADDR_FLASH_SECTOR_3))
	{
		sector = FLASH_SECTOR_3;
	}
	else if((Address < ADDR_FLASH_SECTOR_5) && (Address >= ADDR_FLASH_SECTOR_4))
	{
		sector = FLASH_SECTOR_4;
	}
	else if((Address < ADDR_FLASH_SECTOR_6) && (Address >= ADDR_FLASH_SECTOR_5))
	{
		sector = FLASH_SECTOR_5;
	}
	else if((Address < ADDR_FLASH_SECTOR_7) && (Address >= ADDR_FLASH_SECTOR_6))
	{
		sector = FLASH_SECTOR_6;
	}
	else if((Address < ADDR_FLASH_SECTOR_8) && (Address >= ADDR_FLASH_SECTOR_7))
	{
		sector = FLASH_SECTOR_7;
	}
	else if((Address < ADDR_FLASH_SECTOR_9) && (Address >= ADDR_FLASH_SECTOR_8))
	{
		sector = FLASH_SECTOR_8;
	}
	else if((Address < ADDR_FLASH_SECTOR_10) && (Address >= ADDR_FLASH_SECTOR_9))
	{
		sector = FLASH_SECTOR_9;
	}
	else if((Address < ADDR_FLASH_SECTOR_11) && (Address >= ADDR_FLASH_SECTOR_10))
	{
		sector = FLASH_SECTOR_10;
	}
	else if((Address < ADDR_FLASH_SECTOR_12) && (Address >= ADDR_FLASH_SECTOR_11))
	{
		sector = FLASH_SECTOR_11;
	}
	else if((Address < ADDR_FLASH_SECTOR_13) && (Address >= ADDR_FLASH_SECTOR_12))
	{
		sector = FLASH_SECTOR_12;
	}
	else if((Address < ADDR_FLASH_SECTOR_14) && (Address >= ADDR_FLASH_SECTOR_13))
	{
		sector = FLASH_SECTOR_13;
	}
	else if((Address < ADDR_FLASH_SECTOR_15) && (Address >= ADDR_FLASH_SECTOR_14))
	{
		sector = FLASH_SECTOR_14;
	}
	else if((Address < ADDR_FLASH_SECTOR_16) && (Address >= ADDR_FLASH_SECTOR_15))
	{
		sector = FLASH_SECTOR_15;
	}
	else if((Address < ADDR_FLASH_SECTOR_17) && (Address >= ADDR_FLASH_SECTOR_16))
	{
		sector = FLASH_SECTOR_16;
	}
	else if((Address < ADDR_FLASH_SECTOR_18) && (Address >= ADDR_FLASH_SECTOR_17))
	{
		sector = FLASH_SECTOR_17;
	}
	else if((Address < ADDR_FLASH_SECTOR_19) && (Address >= ADDR_FLASH_SECTOR_18))
	{
		sector = FLASH_SECTOR_18;
	}
	else if((Address < ADDR_FLASH_SECTOR_20) && (Address >= ADDR_FLASH_SECTOR_19))
	{
		sector = FLASH_SECTOR_19;
	}
	else if((Address < ADDR_FLASH_SECTOR_21) && (Address >= ADDR_FLASH_SECTOR_20))
	{
		sector = FLASH_SECTOR_20;
	}
	else if((Address < ADDR_FLASH_SECTOR_22) && (Address >= ADDR_FLASH_SECTOR_21))
	{
		sector = FLASH_SECTOR_21;
	}
	else if((Address < ADDR_FLASH_SECTOR_23) && (Address >= ADDR_FLASH_SECTOR_22))
	{
		sector = FLASH_SECTOR_22;
	}
	else/*(Address < FLASH_END_ADDR) && (Address >= ADDR_FLASH_SECTOR_23))*/
	{
		sector = FLASH_SECTOR_23;
	}

	return sector;
}
