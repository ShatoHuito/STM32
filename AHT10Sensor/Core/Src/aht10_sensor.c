#include "aht10_sensor.h"

uint8_t AHT10_RX_Data[6];
uint32_t AHT10_ADC_Raw;

uint8_t AHT10_TmpHum_Cmd = 0xAC;


void aht10_get_value(I2C_HandleTypeDef hi2c1)
{
	HAL_I2C_Master_Transmit(&hi2c1, AHT10_Adress, &AHT10_TmpHum_Cmd, 1, 100);
	HAL_Delay(100); // Delay must be > 75 ms
	HAL_I2C_Master_Receive(&hi2c1, AHT10_Adress, (uint8_t*)AHT10_RX_Data, 6, 100);

	//convert

	AHT10_ADC_Raw = (((uint32_t)AHT10_RX_Data[3] & 15) << 16) | ((uint32_t)AHT10_RX_Data[4] << 8) | AHT10_RX_Data[5];
	AHT10_Temperature = (AHT10_ADC_Raw * 200 * 10 / 1048576 ) - 500;
	AHT10_ADC_Raw = ((uint32_t)AHT10_RX_Data[1] << 12) | ((uint32_t)AHT10_RX_Data[2] << 4) | (AHT10_RX_Data[3] >> 4);
	AHT10_Humidity = (AHT10_ADC_Raw*100 * 10 / 1048576);
}
