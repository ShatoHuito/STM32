#include "snake.h"


void tail_move(int x, int y)
{
	int tmp_x = x;
	int tmp_y = y;
	if(snake_vector[y][x] == 'r')
	{
		x = ((x + 1) < OLED_WIDTH / 2) ? x : -1;
		if(snake_vector[y][x + 1] == 'Z' || snake_vector[y][x + 1] == 'X' || snake_vector[y][x + 1] == 'C' || snake_vector[y][x + 1] == 'V')
			snake_vector[y][x] = 'r';
		else
			snake_vector[y][x] = '\0';
		if(snake_vector[y][x + 1] == 'R')		snake_vector[y][x + 1] = 'r';
		else if(snake_vector[y][x + 1] == 'D')	snake_vector[y][x + 1] = 'd';
		else if(snake_vector[y][x + 1] == 'U')	snake_vector[y][x + 1] = 'u';
		else if(snake_vector[y][x + 1] == 'Z')	snake_vector[y][x + 1] = 'L';
		else if(snake_vector[y][x + 1] == 'X')	snake_vector[y][x + 1] = 'R';
		else if(snake_vector[y][x + 1] == 'C')	snake_vector[y][x + 1] = 'U';
		else if(snake_vector[y][x + 1] == 'V')	snake_vector[y][x + 1] = 'D';
	}
	else if(snake_vector[y][x] == 'l')
	{
		x = (x > 0) ? x : (OLED_WIDTH / 2);
		if(snake_vector[y][x + 1] == 'Z' || snake_vector[y][x + 1] == 'X' || snake_vector[y][x + 1] == 'C' || snake_vector[y][x + 1] == 'V')
			snake_vector[y][x] = 'r';
		else
			snake_vector[y][x] = '\0';
		if(snake_vector[y][x - 1] == 'L')		snake_vector[y][x - 1] = 'l';
		else if(snake_vector[y][x - 1] == 'D')	snake_vector[y][x - 1] = 'd';
		else if(snake_vector[y][x - 1] == 'U')	snake_vector[y][x - 1] = 'u';
	}
	else if(snake_vector[y][x] == 'd')
	{
		snake_vector[y][x] = '\0';
		y = ((y + 1) < OLED_HEIGHT / 2) ? y : -1;
		if(snake_vector[y + 1][x] == 'D')		snake_vector[y + 1][x] = 'd';
		else if(snake_vector[y + 1][x] == 'R')	snake_vector[y + 1][x] = 'r';
		else if(snake_vector[y + 1][x] == 'L')	snake_vector[y + 1][x] = 'l';
	}
	else if(snake_vector[y][x] == 'u')
	{
		snake_vector[y][x] = '\0';
		y = (y > 0) ? y : (OLED_HEIGHT / 2);
		if(snake_vector[y - 1][x] == 'U')		snake_vector[y - 1][x] = 'u';
		else if(snake_vector[y - 1][x] == 'R')	snake_vector[y - 1][x] = 'r';
		else if(snake_vector[y - 1][x] == 'L')	snake_vector[y - 1][x] = 'l';
	}
}

void head_move(int x, int y)
{
	if(snake_vector[y][x] == '3')
	{
		snake_vector[y][x] = 'R';
		x = ((x + 1) < OLED_WIDTH / 2) ? x : -1;
		if(snake_vector[y][x + 1] == 'T')
			snake_vector[y][x] = 'X';
		else if(snake_vector[y][x + 1])
			game_over_flag = 1;
		snake_vector[y][x + 1] = '3';
	}
	else if(snake_vector[y][x] == '6')
	{
		snake_vector[y][x] = 'D';
		y = ((y + 1) < OLED_HEIGHT / 2) ? y : -1;
		if(snake_vector[y + 1][x] == 'T')
			snake_vector[y][x] = 'V';
		else if(snake_vector[y + 1][x])
			game_over_flag = 1;
		snake_vector[y + 1][x] = '6';
	}
	else if(snake_vector[y][x] == '9')
	{
		snake_vector[y][x] = 'L';
		x = (x > 0) ? x : (OLED_WIDTH / 2);
		if(snake_vector[y][x - 1] == 'T')
			snake_vector[y][x] = 'Z';
		else if(snake_vector[y][x - 1])
			game_over_flag = 1;
		snake_vector[y][x - 1] = '9';
	}
	else if(snake_vector[y][x] == '0')
	{
		snake_vector[y][x] = 'U';
		y = (y > 0) ? y : (OLED_HEIGHT / 2);
		if(snake_vector[y - 1][x] == 'T')
			snake_vector[y][x] = 'C';
		else if(snake_vector[y - 1][x])
			game_over_flag = 1;
		snake_vector[y - 1][x] = '0';
	}
}




