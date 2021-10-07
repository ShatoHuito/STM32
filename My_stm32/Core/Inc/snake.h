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
#include <main.h>

uint32_t key_flag_right;
uint32_t key_flag_left;
uint32_t game_over_flag;
uint32_t eat_flag;

uint8_t snake_vector[OLED_HEIGHT / 2][OLED_WIDTH / 2];
// R - right L - left U - up D - down (LOW CASE r l u d for TAIL!!)
// r - right for tail l - left u - up d - down
// 0 - up for head 3 - right 6 -down 9 - left
// T - target for snake on map (after eat target Z - left X - right C - up V - down)


void snake_init(ADC_HandleTypeDef hadc1); //основная функция
void tail_move(uint32_t x, uint32_t y);
void head_move(uint32_t x, uint32_t y);

#endif /* INC_SNAKE_H_ */
