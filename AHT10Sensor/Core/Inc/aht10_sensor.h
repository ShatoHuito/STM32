/*
 * aht10_sensor.h
 *
 *  Created on: Oct 11, 2021
 *      Author: ilnur
 */

#ifndef INC_AHT10_SENSOR_H_
#define INC_AHT10_SENSOR_H_

#include "stm32f1xx.h"

#define AHT10_Adress 0x38 << 1

uint32_t AHT10_Temperature; // last number - 0.1
uint32_t AHT10_Humidity; // последнее значение - дясотое

void aht10_get_value(I2C_HandleTypeDef hi2c1);


#endif /* INC_AHT10_SENSOR_H_ */
