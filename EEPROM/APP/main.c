/*
 * main.c

 *
 *  Created on: Nov 17, 2020
 *      Author: Abeer
 */

#include "../lib/STD_Types.h"
#include "../lib/BIT_MATH.h"
#include "../lib/AVR32_REG.h"
#include "../HAL/E2PROM/EEPROM_Interface.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/I2C/I2C_Interface.h"
int main(){
 	u8  test;
 	I2C_InitMaster(EEPROM_Freq,PRE_16,0x01);
 	DIO_VidSetPortDirection(0,255);

	while(1){

		EEPROM_VidWrite(500,'c',FIRST_EEPROM);
		EEPROM_VidRead(500,&test,FIRST_EEPROM);
		DIO_VidSetPortValue(PortA,test);
 	}
	return 0;
}

