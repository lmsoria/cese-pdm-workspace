#pragma once

#include <stdint.h>
#include "i2c_port.h"
#include "MPU6500_registers.h"

#define MPU_6500_DEFAULT_ADDRESS (0x68 << 1)
#define MPU_6500_WHO_AM_I_VALUE 0x70

typedef enum {
	ACCEL_FS_2g = 0x00,
	ACCEL_FS_4g = 0x01,
	ACCEL_FS_8g = 0x02,
	ACCEL_FS_16g = 0x03,
} AccelFullScale;

typedef enum {
	GYRO_FS_250dps =  0x00,
	GYRO_FS_500dps = 0x01,
	GYRO_FS_1000dps = 0x02,
	GYRO_FS_2000dps = 0x03,
} GyroFullScale;

typedef enum {
    GYRO_DLPF_250HZ = 0x00,
    GYRO_DLPF_184HZ = 0x01,
    GYRO_DLPF_92HZ = 0x02,
    GYRO_DLPF_41HZ = 0x03,
    GYRO_DLPF_20HZ = 0x04,
    GYRO_DLPF_10HZ = 0x05,
    GYRO_DLPF_5HZ = 0x06,
    GYRO_DLPF_3600HZ = 0x07,
} GyroDLPFMode;

typedef enum {
    ACCEL_DLPF_460HZ = 0x00,
    ACCEL_DLPF_184HZ = 0x01,
    ACCEL_DLPF_92HZ = 0x02,
    ACCEL_DLPF_41HZ = 0x03,
    ACCEL_DLPF_20HZ = 0x04,
    ACCEL_DLPF_10HZ = 0x05,
    ACCEL_DLPF_5Hz = 0x06,
} AccelDLPFMode;

typedef enum {
    FCHOICE_0 = 0x00,
    FCHOICE_1 = 0x01,
    FCHOICE_2 = 0x02,
    FCHOICE_3 = 0x03,
} GyroFChoice;

typedef enum
{
    CLOCK_INTERNAL = 0x00,   ///< Internal 20MHz oscillator
    CLOCK_PLL = 0x03,        ///< Auto selects the best clock source - PLL if ready, Internal clock otherwise.
    CLOCK_KEEP_RESET = 0x07, ///< Stops the clock and keeps timing generator in reset.
} ClockSource;

typedef struct {
    AccelFullScale accel_full_scale;
    GyroFullScale gyro_full_scale;
    GyroFChoice gyro_fchoice;
    GyroDLPFMode gyro_dlpf_mode;
    AccelDLPFMode accel_dlpf_mode;
    uint16_t sample_rate;
} MPU6500_config_t;

typedef enum {
    MPU6500_ERROR_OK = I2C_PORT_ERROR_TOTAL,
    MPU6500_ERROR_I2C,
    MPU6500_ERROR_DEVICE,
} MPU6500ErrorCode;


MPU6500ErrorCode MPU6500_init(const MPU6500_config_t* config);

MPU6500ErrorCode MPU6500_reset();

MPU6500ErrorCode MPU6500_set_clock_source(const ClockSource source);

MPU6500ErrorCode MPU6500_set_gyro_full_scale(GyroFullScale gyro_full_scale);

MPU6500ErrorCode MPU6500_set_accel_full_scale(AccelFullScale accel_full_scale);

MPU6500ErrorCode MPU6500_set_gyro_digital_low_pass_filter(GyroDLPFMode filter_mode);
MPU6500ErrorCode MPU6500_get_gyro_digital_low_pass_filter(GyroDLPFMode* filter_mode);

MPU6500ErrorCode MPU6500_set_accel_digital_low_pass_filter(AccelDLPFMode filter_mode);
MPU6500ErrorCode MPU6500_get_accel_digital_low_pass_filter(AccelDLPFMode* filter_mode);

MPU6500ErrorCode MPU6500_set_gyro_fchoice(GyroFChoice fchoice);
MPU6500ErrorCode MPU6500_get_gyro_fchoice(GyroFChoice* fchoice);

MPU6500ErrorCode MPU6500_set_sample_rate(uint16_t sample_rate);

MPU6500ErrorCode MPU6500_read_temperature_raw(int16_t* temperature);

MPU6500ErrorCode MPU6500_read_acceleration_raw(int16_t* x, int16_t* y, int16_t* z);

MPU6500ErrorCode MPU6500_read_rotation_raw(int16_t* x, int16_t* y, int16_t* z);
