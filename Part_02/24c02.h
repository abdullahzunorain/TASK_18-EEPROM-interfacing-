#ifndef __24C02_H
#define __24C02_H

#define DEVICE_ADDRESS_24C02_EEPROM 0xA0


void write_byte_to_24c02_eeprom (unsigned int , unsigned char );
unsigned char read_byte_from_24c02_eeprom (unsigned int );
//void write_page_to_24c02_eeprom (unsigned int , unsigned char*, unsigned char );
//unsigned char read_bytes_from_24c02_eeprom(unsigned int ,unsigned char*,unsigned int);



#endif