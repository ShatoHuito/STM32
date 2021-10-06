/*
 * snake.c
 *
 *  Created on: Aug 27, 2021
 *      Author: gbrittan
 */

#include "snake.h"

int snake_len = 8;
int init_flag = 0;

uint8_t y_pixel_bit_return(int y, int fl)
{
	int ost;
	ost = y % 4;

	if(ost == 0)
		return(fl == 0 ? 0x02 : 0x01);
	else if(ost == 1)
		return(fl == 0 ? 0x08 : 0x04);
	else if(ost == 2)
		return(fl == 0 ? 0x20 : 0x10);
	else if(ost == 3)
		return(fl == 0 ? 0x80 : 0x40);
	return 0;
}

void game_over(void)
{
	LCD_Clear();
	LCD_Goto(40, 2);
	OLED_string("GAME OVER");
	LCD_Goto(32, 4);
	OLED_string("PLEASE PUSH");
	LCD_Goto(32, 6);
	OLED_string("RESRT on STM");

}

void snake_screen_print()
{
	int y = 0;
	int x;

	while(y < OLED_HEIGHT / 8)
	{
		x = 0;
		while(x < OLED_WIDTH + 1)
			temp_screen[y][x++] = '\0';
		y++;
	}
	y = 0;
	while(y < OLED_HEIGHT / 2) // 32
	{
		x = 0;
		while(x < OLED_WIDTH / 2) // 64
		{
			if(snake_vector[y][x] == 'R' || snake_vector[y][x] == 'U' || snake_vector[y][x] == 'D' || snake_vector[y][x] == 'L'
				|| snake_vector[y][x] == 'r' || snake_vector[y][x] == 'u' || snake_vector[y][x] == 'd' || snake_vector[y][x] == 'l'	)
			{
				temp_screen[y / 4][x * 2 + 1] |= y_pixel_bit_return(y, 0);
				temp_screen[y / 4][x * 2 + 2] |= y_pixel_bit_return(y, 1);
			}
			else if(snake_vector[y][x])
			{
				temp_screen[y / 4][x * 2 + 1] |= y_pixel_bit_return(y, 0);
				temp_screen[y / 4][x * 2 + 2] |= y_pixel_bit_return(y, 1);
				temp_screen[y / 4][x * 2 + 1] |= y_pixel_bit_return(y, 1);
				temp_screen[y / 4][x * 2 + 2] |= y_pixel_bit_return(y, 0);
			}
			x++;
		}
		y++;
	}
	OLED_print_all_screen();
}

void snake_move()
{
	int y = 0;
	int x;
	int tail_fl = 0;
	int head_fl = 0;

	while(y < OLED_HEIGHT / 2) // 32
	{
		x = 0;
		while(x < OLED_WIDTH / 2) // 64
		{
			if(!tail_fl && (snake_vector[y][x] == 'r' || snake_vector[y][x] == 'd' ||
					snake_vector[y][x] == 'l' || snake_vector[y][x] == 'u'))
			{
				tail_fl = 1;
				tail_move(x, y);
			}
			else if(!head_fl && (snake_vector[y][x] == '0' || snake_vector[y][x] == '3' ||
					snake_vector[y][x] == '6' || snake_vector[y][x] == '9'))
			{
				if(key_flag_left)
				{
					if(snake_vector[y][x] == '3')
						snake_vector[y][x] = '0';
					else if(snake_vector[y][x] == '6')
						snake_vector[y][x] = '3';
					else if(snake_vector[y][x] == '9')
						snake_vector[y][x] = '6';
					else if(snake_vector[y][x] == '0')
						snake_vector[y][x] = '9';
					key_flag_left = 0;
				}
				else if(key_flag_right)
				{
					if(snake_vector[y][x] == '3')
						snake_vector[y][x] = '6';
					else if(snake_vector[y][x] == '6')
						snake_vector[y][x] = '9';
					else if(snake_vector[y][x] == '9')
						snake_vector[y][x] = '0';
					else if(snake_vector[y][x] == '0')
						snake_vector[y][x] = '3';
					key_flag_right = 0;
				}
				head_fl = 1;
				head_move(x, y);
			}
			if(tail_fl && head_fl)
				return;
			x++;
		}
		y++;
	}
}

void snake_init()
{
	srand(HAL_GetTick());
	int x = rand() % 64;
	int y = rand() % 32;
//	x = 25;
//	y = 4;
	int i = 0;
	while(i < snake_len)
	{
		snake_vector[y][x + i] = 'R';
		i++;
	}
	snake_vector[y][x] = 'r';
	snake_vector[y][x + i - 1] = '3';
	x = rand() % 64;
	y = rand() % 32;
	snake_vector[y][x] = 'T';
	snake_screen_print();
	while(1)
	{
		HAL_Delay(40);
		snake_move();
		snake_screen_print();
		if(game_over_flag)
		{
			game_over();
			return;
		}
	}
}


