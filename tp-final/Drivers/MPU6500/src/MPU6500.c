#include "MPU6500.h"

#include "stm32f4xx_hal_i2c.h"

extern I2C_HandleTypeDef hi2c1;

void MPU6500_init(const MPU6500_config_t* config)
{
	uint8_t acc_resolution = config->accel_full_scale;
	uint8_t gyro_resolution = config->gyro_full_scale;

	HAL_I2C_Mem_Write(&hi2c1, (MPU_6500_DEFAULT_ADDRESS << 1) | 0x01 , WHO_AM_I, 1, &who_am_i, sizeof(who_am_i), HAL_MAX_DELAY);
}
