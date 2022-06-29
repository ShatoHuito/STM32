/*
 * test.c
 *
 *  Created on: Aug 27, 2021
 *      Author: Adelya
 */
#include "ssd1306_i2c.h"

void test_all(void)
{
	int x = 0;
	int y = 0;

	while(y < 8)
	{
		x = 0;
		LCD_Goto(x, y);
		while(x++ < 128)
			sendData(0x03);
		y++;
	}
}

void drop_str(void) // падающая строка
{
	  uint8_t x = 0x01;
	  uint8_t y = 0x01;
	  LCD_Goto(0, 0);
	  int i = 0;
	  int flag = 0;

	  LCD_Goto(0, 0);
	  i = 0;
	  if(!flag)
	  {
		  while(i++ < 128)
			  sendData(x);
		  if(x ^ 0x80)
			  x <<= 1;
		  else
			  flag++;
	  }
	  else
	  {
		  i = 0;
		  while(i++ < 128)
			  sendData(x | y);
		  y <<= 1;
		  if(x == (x | y))
		  {
			  x = x | (y >> 1);
			  y = 0x01;
		  }
	  }
}
