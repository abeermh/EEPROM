/*
 * EEPROM_Interface.h
 *
 *  Created on: Nov 17, 2020
 *      Author: Abeer
 */

#ifndef HAL_E2PROM_EEPROM_INTERFACE_H_
#define HAL_E2PROM_EEPROM_INTERFACE_H_


void EEPROM_VidRead(u16 Copy_U16Address,u8* Copy_U8Data,u8 Copy_U8SelectedEEPROM);
void EEPROM_VidWrite(u16 Copy_U16Address,u8 Copy_U8Data,u8 Copy_U8SelectedEEPROM);

#define FIRST_EEPROM		0
#define SECOND_EEPROM		1
#define EEPROM_Freq			400000UL

#endif /* HAL_E2PROM_EEPROM_INTERFACE_H_ */
