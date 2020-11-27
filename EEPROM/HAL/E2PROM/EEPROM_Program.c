/*
 * EEPROM_Program.c
 *
 *  Created on: Nov 17, 2020
 *      Author: Abeer Mohamed Hassan
 */
#include "../../lib/STD_Types.h"
#include "../../lib/BIT_MATH.h"
#include "../../lib/AVR32_REG.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/I2C/I2C_Interface.h"
#include "EEPROM_Private.h"
//					EEPROM AT24C08


void EEPROM_VidWrite(u16 Copy_U16Address,u8 Copy_U8Data,u8 Copy_U8SelectedEEPROM){
	u8 Local_U8Address;
	if(Copy_U8SelectedEEPROM==FIRST_EEPROM){
		Local_U8Address=EEPROM_ADDRESS;}
	else if(Copy_U8SelectedEEPROM==SECOND_EEPROM){
		Local_U8Address=EEPROM_ADDRESS|(1<<2);
	}

	I2C_Start();
 	I2C_SendAddress((((Copy_U16Address>>8)&SEL_2BITS)|Local_U8Address ),WRITE);
 	I2C_U8MasterSend((u8)Copy_U16Address);
 	I2C_U8MasterSend(Copy_U8Data);
	I2C_VidStop();
}

void EEPROM_VidRead(u16 Copy_U16Address,u8* Copy_U8Data,u8 Copy_U8SelectedEEPROM){
	u8 Local_U8Address;
	if(Copy_U8SelectedEEPROM==FIRST_EEPROM){
		Local_U8Address=EEPROM_ADDRESS;}
	else if(Copy_U8SelectedEEPROM==SECOND_EEPROM){
		Local_U8Address=EEPROM_ADDRESS|(1<<2);
	}
	I2C_Start();
 	I2C_SendAddress((((Copy_U16Address>>8)&SEL_2BITS)|Local_U8Address),WRITE);
 	I2C_U8MasterSend((u8)Copy_U16Address);
 	I2C_RepeatedStart();
 	I2C_SendAddress((((Copy_U16Address>>8)&SEL_2BITS)|Local_U8Address),READ);
 	I2C_U8MasterReceive(Copy_U8Data);
	I2C_VidStop();
}
