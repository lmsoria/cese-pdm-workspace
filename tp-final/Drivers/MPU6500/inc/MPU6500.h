/*
 * MPU6500.h
 *
 *  Created on: Jul 12 2023
 *      Author: lsoria
 */

#pragma once

#include <stdint.h>

#define MPU_6500_DEFAULT_ADDRESS (0x68 << 1)
#define MPU_6500_WHO_AM_I_VALUE 0x70

#define MPU_6500_REG_SELF_TEST_X_GYRO   0x00
#define MPU_6500_REG_SELF_TEST_Y_GYRO   0x01
#define MPU_6500_REG_SELF_TEST_Z_GYRO   0x02
#define MPU_6500_REG_SELF_TEST_X_ACCEL  0x0D
#define MPU_6500_REG_SELF_TEST_Y_ACCEL  0x0E
#define MPU_6500_REG_SELF_TEST_Z_ACCEL  0x0F
#define MPU_6500_REG_XG_OFFSET_H        0x13
#define MPU_6500_REG_XG_OFFSET_L        0x14
#define MPU_6500_REG_YG_OFFSET_H        0x15
#define MPU_6500_REG_YG_OFFSET_L        0x16
#define MPU_6500_REG_ZG_OFFSET_H        0x17
#define MPU_6500_REG_ZG_OFFSET_L        0x18
#define MPU_6500_REG_SMPLRT_DIV         0x19
#define MPU_6500_REG_CONFIG             0x1A
#define MPU_6500_REG_GYRO_CONFIG        0x1B
#define MPU_6500_REG_ACCEL_CONFIG       0x1C
#define MPU_6500_REG_ACCEL_CONFIG_2     0x1D
#define MPU_6500_REG_LP_ACCEL_ODR       0x1E
#define MPU_6500_REG_WOM_THR            0x1F
#define MPU_6500_REG_FIFO_EN            0x23
#define MPU_6500_REG_I2C_MST_CTRL       0x24
#define MPU_6500_REG_I2C_SLV0_ADDR      0x25
#define MPU_6500_REG_I2C_SLV0_REG       0x26
#define MPU_6500_REG_I2C_SLV0_CTRL      0x27
#define MPU_6500_REG_I2C_SLV1_ADDR      0x28
#define MPU_6500_REG_I2C_SLV1_REG       0x29
#define MPU_6500_REG_I2C_SLV1_CTRL      0x2A
#define MPU_6500_REG_I2C_SLV2_ADDR      0x2B
#define MPU_6500_REG_I2C_SLV2_REG       0x2C
#define MPU_6500_REG_I2C_SLV2_CTRL      0x2D
#define MPU_6500_REG_I2C_SLV3_ADDR      0x2E
#define MPU_6500_REG_I2C_SLV3_REG       0x2F
#define MPU_6500_REG_I2C_SLV3_CTRL      0x30
#define MPU_6500_REG_I2C_SLV4_ADDR      0x31
#define MPU_6500_REG_I2C_SLV4_REG       0x32
#define MPU_6500_REG_I2C_SLV4_DO        0x33
#define MPU_6500_REG_I2C_SLV4_CTRL      0x34
#define MPU_6500_REG_I2C_SLV4_DI        0x35
#define MPU_6500_REG_I2C_MST_STATUS     0x36
#define MPU_6500_REG_INT_PIN_CFG        0x37
#define MPU_6500_REG_INT_ENABLE         0x38
#define MPU_6500_REG_INT_STATUS         0x3A
#define MPU_6500_REG_ACCEL_XOUT_H       0x3B
#define MPU_6500_REG_ACCEL_XOUT_L       0x3C
#define MPU_6500_REG_ACCEL_YOUT_H       0x3D
#define MPU_6500_REG_ACCEL_YOUT_L       0x3E
#define MPU_6500_REG_ACCEL_ZOUT_H       0x3F
#define MPU_6500_REG_ACCEL_ZOUT_L       0x40
#define MPU_6500_REG_TEMP_OUT_H         0x41
#define MPU_6500_REG_TEMP_OUT_L         0x42
#define MPU_6500_REG_GYRO_XOUT_H        0x43
#define MPU_6500_REG_GYRO_XOUT_L        0x44
#define MPU_6500_REG_GYRO_YOUT_H        0x45
#define MPU_6500_REG_GYRO_YOUT_L        0x46
#define MPU_6500_REG_GYRO_ZOUT_H        0x47
#define MPU_6500_REG_GYRO_ZOUT_L        0x48
#define MPU_6500_REG_EXT_SENS_DATA_00   0x49
#define MPU_6500_REG_EXT_SENS_DATA_01   0x4A
#define MPU_6500_REG_EXT_SENS_DATA_02   0x4B
#define MPU_6500_REG_EXT_SENS_DATA_03   0x4C
#define MPU_6500_REG_EXT_SENS_DATA_04   0x4D
#define MPU_6500_REG_EXT_SENS_DATA_05   0x4E
#define MPU_6500_REG_EXT_SENS_DATA_06   0x4F
#define MPU_6500_REG_EXT_SENS_DATA_07   0x50
#define MPU_6500_REG_EXT_SENS_DATA_08   0x51
#define MPU_6500_REG_EXT_SENS_DATA_09   0x52
#define MPU_6500_REG_EXT_SENS_DATA_10   0x53
#define MPU_6500_REG_EXT_SENS_DATA_11   0x54
#define MPU_6500_REG_EXT_SENS_DATA_12   0x55
#define MPU_6500_REG_EXT_SENS_DATA_13   0x56
#define MPU_6500_REG_EXT_SENS_DATA_14   0x57
#define MPU_6500_REG_EXT_SENS_DATA_15   0x58
#define MPU_6500_REG_EXT_SENS_DATA_16   0x59
#define MPU_6500_REG_EXT_SENS_DATA_17   0x5A
#define MPU_6500_REG_EXT_SENS_DATA_18   0x5B
#define MPU_6500_REG_EXT_SENS_DATA_19   0x5C
#define MPU_6500_REG_EXT_SENS_DATA_20   0x5D
#define MPU_6500_REG_EXT_SENS_DATA_21   0x5E
#define MPU_6500_REG_EXT_SENS_DATA_22   0x5F
#define MPU_6500_REG_EXT_SENS_DATA_23   0x60
#define MPU_6500_REG_I2C_SLV0_DO        0x63
#define MPU_6500_REG_I2C_SLV1_DO        0x64
#define MPU_6500_REG_I2C_SLV2_DO        0x65
#define MPU_6500_REG_I2C_SLV3_DO        0x66
#define MPU_6500_REG_I2C_MST_DELAY_CTRL 0x67
#define MPU_6500_REG_SIGNAL_PATH_RESET  0x68
#define MPU_6500_REG_ACCEL_INTEL_CTRL   0x69
#define MPU_6500_REG_USER_CTRL          0x6A
#define MPU_6500_REG_PWR_MGMT_1         0x6B
#define MPU_6500_REG_PWR_MGMT_2         0x6C
#define MPU_6500_REG_FIFO_COUNT_H       0x72
#define MPU_6500_REG_FIFO_COUNT_L       0x73
#define MPU_6500_REG_FIFO_R_W           0x74
#define MPU_6500_REG_WHO_AM_I           0x75
#define MPU_6500_REG_XA_OFFSET_H        0x77
#define MPU_6500_REG_XA_OFFSET_L        0x78
#define MPU_6500_REG_YA_OFFSET_H        0x7A
#define MPU_6500_REG_YA_OFFSET_L        0x7C
#define MPU_6500_REG_ZA_OFFSET_H        0x7C
#define MPU_6500_REG_ZA_OFFSET_L        0x7D


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
    FIFO_SAMPLE_RATE_1000HZ = 0x00,
    FIFO_SAMPLE_RATE_500HZ = 0x01,
    FIFO_SAMPLE_RATE_333HZ = 0x02,
    FIFO_SAMPLE_RATE_250HZ = 0x03,
    FIFO_SAMPLE_RATE_200HZ = 0x04,
    FIFO_SAMPLE_RATE_167HZ = 0x05,
    FIFO_SAMPLE_RATE_143HZ = 0x06,
    FIFO_SAMPLE_RATE_125HZ = 0x07,	
} FIFOSampleRate;

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

typedef struct {
    AccelFullScale accel_full_scale;
    GyroFullScale gyro_full_scale;
    FIFOSampleRate fifo_sample_rate;
    uint8_t gyro_fchoice;
    GyroDLPFMode gyro_dlpf_mode;
    uint8_t accel_fchoice;
    AccelDLPFMode accel_dlpf_mode;
} MPU6500_config_t;


void MPU6500_init(const MPU6500_config_t config);
