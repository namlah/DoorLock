s/*
 * doorlock.c
 *
 *  Created on: Oct 14, 2018
 *      Author: sohier
 */

#include "doorlock.h"


#define motor  PD0|PD1
#define eeprom PD3|PD4
#define buzzer PD5|PD6


void WritePassToEEPROM(uint16 pass) //Writes the given 4 digit password to eeprom
{

	EEPROM_writeByte(0000,(pass%100));
	EEPROM_writeByte(0001,(pass/100));
}

uint16 ReadPassFromEEPROM() //Reads and Returns the 4 digit password from eeprom
{

	return (EEPROM_readByte(0001)*100  +	EEPROM_readByte(0000));
}
