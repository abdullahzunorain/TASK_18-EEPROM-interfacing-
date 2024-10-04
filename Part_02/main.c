
/*
task_18__part_03:
Implement a counter of one second (8 bit) and save the value of the counter in EEPROM 
after each second. Show the count on seven segment displays. On startup, load the value 
of the counter from EEPROM. Reset the board and see if the counter value remains 
preserved between resets. An unwritten memory location in EEPROM has a value of 0xFF 
or 255 which you can use to check if it is a new board or if the value is legitimate
*/


#include <reg51.h>
#include "LCD.h"
#include "24C02.h"
#include "I2C.h"



void main()
{


unsigned int counter=0;
unsigned int readvalue=0;



	lcd_init();
	
	INITI2C();
	lcd_set_cursor(0,0);
	lcd_string("COUNTER EEPROM:");

while(1)
{
	write_byte_to_24c02_eeprom(0x0001, counter);
	
	readvalue=read_byte_from_24c02_eeprom(0x0001);
	delay(1000);
//		readvalue = (float *) malloc(readvalue1);

	lcd_set_cursor(1,0);
	if(readvalue<10)
	{
		lcd_char('0');
		lcd_char('0');

		lcd_char(readvalue +'0');

	}
	else if (readvalue<100)
	{
		lcd_char('0');
		lcd_char(readvalue / 10 +'0');
		lcd_char(readvalue % 10 +'0');
	}
	else if(readvalue<=255)
	{
		lcd_char(readvalue / 100 +'0');
		lcd_char((readvalue /10)%10 +'0');
		lcd_char(readvalue % 10 +'0');
	
	}
	else
	{
		
		counter=0;
		readvalue=0;
	}
	delay(100);
	counter++;
	
	if(readvalue>255)
	{
		counter=0;
		readvalue=0;
		break;
	}
}

}







