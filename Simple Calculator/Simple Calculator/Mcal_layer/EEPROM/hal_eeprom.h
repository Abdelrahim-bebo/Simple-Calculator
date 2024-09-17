/* 
 * File:   hal_eeprom.h
 * Author: Abdelrahim Bebo
 *
 * Created on July 4, 2024, 9:15 PM
 */

#ifndef HAL_EEPROM_H
#define	HAL_EEPROM_H
/*Section : MACRO DECLARATIONS*/
#define ACCESS_FLASH_MEMORY  1
#define ACCESS_EEPROM_MEMORY 0
#define ACCESS_CONFIGURATION_MEMORY 1
#define ACCESS_FLASH_EEPROM_MEMORY  0
#define ALLOW_WRITE_CYCLE_FLASH_EEPROM   1
#define INHIBIT_WRITE_CYCLE_FLASH_EEPROM 0
#define INITIATE_DATA_EEPROM_WRITE_ERASE  1
#define DATA_EEPROM_WRITE_ERASE_COMPLETED 0
#define INITIATE_DATA_EEPROM_READ         1
/*Section : INCLUDES*/
#include "../../Mcal_layer/mcal_std_types.h"
#include "../../Mcal_layer/interrupt/mcal_internal_interrupt.h"
#include "pic18f4620.h"


/*Section : MACRO FUNCTIONS DECLARATIONS*/


/*Section : DATATYPES DECLARATIONS*/


/*Section : FUNCTIONS DECLARATIONS*/
std_returntype Data_EEPROM_ReadByte(uint16 bAdd , uint8 *bData);
std_returntype Data_EEPROM_WriteByte(uint16 bAdd , uint8 bData);

#endif	/* HAL_EEPROM_H */

