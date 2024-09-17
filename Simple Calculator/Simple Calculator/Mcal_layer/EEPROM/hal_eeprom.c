/* 
 * File:   hal_eeprom.c
 * Author: Abdelrahim Bebo
 *
 * Created on July 4, 2024, 9:15 PM
 */

#include "hal_eeprom.h"

std_returntype Data_EEPROM_ReadByte(uint16 bAdd , uint8 *bData){
    std_returntype ret = E_NOT_OK;
     if(NULL == bData){
          ret = E_NOT_OK;
     }
     else{
         /* Update the Address Registers */
          EEADRH =(uint8)((bAdd >> 8)& 0x03);
          EEADR = (uint8)(bAdd & 0XFF);
         /* Select Access data EEPROM memory */
          EECON1bits.EEPGD = ACCESS_EEPROM_MEMORY;
          EECON1bits.CFGS = ACCESS_FLASH_EEPROM_MEMORY;
         /* Initiates a data EEPROM read cycle */
          EECON1bits.RD = INITIATE_DATA_EEPROM_READ;
          NOP();    /* NOPs may be required for latency at high frequencies */
          NOP();    /* NOPs may be required for latency at high frequencies */
         /* Return data */
          *bData = EEDATA;          
         ret = E_OK;
     }
    return ret;
}
std_returntype Data_EEPROM_WriteByte(uint16 bAdd , uint8 bData){
    std_returntype ret = E_OK;
    /* Read the Interrupt Status "Enabled or Disabled" */
    uint8 Glopal_Interrupt_Status = INTCONbits.GIE;
    /* Update the Address Registers */
    EEADRH =(uint8)((bAdd >> 8)& 0x03);
    EEADR = (uint8)(bAdd & 0XFF);
    /* Update the Data Register */
    EEDATA = bData;
    /* Select Access data EEPROM memory */
    EECON1bits.EEPGD = ACCESS_EEPROM_MEMORY;
    EECON1bits.CFGS = ACCESS_FLASH_EEPROM_MEMORY;
    /* Allows write cycles to Flash program/data EEPROM */
    EECON1bits.WREN = ALLOW_WRITE_CYCLE_FLASH_EEPROM ;
    /* Disable all interrupts "General Interrupt" */
    INTERRUPT_GlopalInterruptDisable();
    /* Write the required sequence : 0x55 -> 0xAA */
    EECON2 = 0x55;
    EECON2 = 0xAA;
    /* Initiates a data EEPROM erase/write cycle */
    EECON1bits.WR = INITIATE_DATA_EEPROM_WRITE_ERASE;
    /* Wait for write to complete */
     while(EECON1bits.WR) ;      
    /* Inhibits write cycles to Flash program/data EEPROM */
     EECON1bits.WREN = INHIBIT_WRITE_CYCLE_FLASH_EEPROM ;
    /* Restore the Interrupt Status "Enabled or Disabled" */
     INTCONbits.GIE = Glopal_Interrupt_Status;
    return ret;
}