#include <reg51.h>
#include "LCD.h"
#include "I2C.h"
#include "24C02.h"


void write_byte_to_24c02_eeprom (unsigned int address,unsigned char databyte)
{
	I2C_START();
	while(I2C_WRITE_BYTE(DEVICE_ADDRESS_24C02_EEPROM + 0)==1)
	{
		I2C_START();
	}
	I2C_WRITE_BYTE(address>>8);
	I2C_WRITE_BYTE((unsigned char)address);
	I2C_WRITE_BYTE(databyte);
	I2C_STOP();
}
unsigned char read_byte_from_24c02_eeprom (unsigned int address)
{
	unsigned char Byte=0;
	I2C_START();
	while(I2C_WRITE_BYTE(DEVICE_ADDRESS_24C02_EEPROM +0)==1)
	{
		I2C_START();
	}
	I2C_WRITE_BYTE(address>>8);
	I2C_WRITE_BYTE((unsigned char)address);
	I2C_RESTART();
	
	I2C_WRITE_BYTE(DEVICE_ADDRESS_24C02_EEPROM+1);
	
	Byte=I2C_READ_BYTE();
		
	I2C_NACK();
	SET_SDA_LOW;
	delay1(5);
	SET_SDA_HIGH;
	delay1(5);
	return Byte;
}

//void write_page_to_24c02_eeprom (unsigned int address , unsigned char* pData, unsigned char noofbytes )
//{
//	unsigned char i;
//	I2C_START();
//  while(I2C_WRITE_BYTE(DEVICE_ADDRESS_24C02_EEPROM +0)==1)
//	{
//		I2C_START();
//	}
//	I2C_WRITE_BYTE(address>>8);
//	I2C_WRITE_BYTE((unsigned char)address);
//	
//	for(i=0; i<noofbytes; i++)
//	{
//		I2C_WRITE_BYTE(pData[i]);
//		I2C_STOP();
//	}
//	
//}

//unsigned char read_bytes_from_24c02_eeprom(unsigned int address ,unsigned char*pData,unsigned int noofdata)
//{
//	unsigned char i;
//	I2C_START();
//	while(I2C_WRITE_BYTE(DEVICE_ADDRESS_24C02_EEPROM +0)==1)
//	{
//		I2C_START();
//	}
//	I2C_WRITE_BYTE(address>>8);
//	I2C_WRITE_BYTE((unsigned char)address);
//	
//	I2C_RESTART();
//	I2C_WRITE_BYTE(DEVICE_ADDRESS_24C02_EEPROM +1);
//	
//	pData[0]=I2C_READ_BYTE();
//	
//	for(i=0; i<noofdata; i++)
//	{
//		I2C_ACK();
//		pData[i]=I2C_READ_BYTE();
//	}
//	I2C_NACK();
//	SET_SDA_LOW;
//	delay1(5);
//	SET_SDA_HIGH;
//	delay1(5);
//}













