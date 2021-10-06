/*
 * snake.h
 *
 *  Created on: Aug 27, 2021
 *      Author: gbrittan
 */

#ifndef INC_SNAKE_H_
#define INC_SNAKE_H_

#include "ssd1306_i2c.h"
#include <stdlib.h>
#include <time.h>

int key_flag_right;
int key_flag_left;
int game_over_flag;


char snake_vector[OLED_HEIGHT / 2][OLED_WIDTH / 2];
// R - right L - left U - up D - down (LOW CASE r l u d for TAIL!!)
// r - right for tail l - left u - up d - down
// 0 - up for head 3 - right 6 -down 9 - left
// T - target for snake on map (after eat target Z - left X - right C - up V - down)


void snake_init(void); //основная функция
void tail_move(int x, int y);
void head_move(int x, int y);

#endif /* INC_SNAKE_H_ */
