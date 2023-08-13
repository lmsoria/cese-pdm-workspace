#pragma once

#include <stdint.h>
#include "i2c_port.h"
#include "MPU6500_registers.h"

/// MPU6500 I2C driver.
/// It was written taking this document as reference:
/// https://invensense.tdk.com/wp-content/uploads/2020/06/PS-MPU-6500A-01-v1.3.pdf

/// MPU6500 I2C Slave address
#define MPU_6500_DEFAULT_ADDRESS (0x68 << 1)

/// Value thrown by the WHO_AM_I register. Used to verify the identity of the device.
#define MPU_6500_WHO_AM_I_VALUE 0x70

/// @brief Accelerometer Full Scale ranges
typedef enum {
	ACCEL_FS_2g = 0x00,  ///< +/- 2g. The sensitivity will be 16384 LSB/g
	ACCEL_FS_4g = 0x01,  ///< +/- 4g. The sensitivity will be 8192 LSB/g
	ACCEL_FS_8g = 0x02,  ///< +/- 8. The sensitivity will be 4096 LSB/g
	ACCEL_FS_16g = 0x03, ///< +/- 16g. The sensitivity will be 2048 LSB/g
} AccelFullScale;

/// @brief Gyroscope Full Scale ranges
typedef enum {
	GYRO_FS_250dps =  0x00, ///< +/- 250 dps. The sensitivity will be 131 LSB/(°/s)
	GYRO_FS_500dps = 0x01,  ///< +/- 500 dps. The sensitivity will be 65.5 LSB/(°/s)
	GYRO_FS_1000dps = 0x02, ///< +/- 1000 dps. The sensitivity will be 32.8 LSB/(°/s)
	GYRO_FS_2000dps = 0x03, ///< +/- 2000 dps. The sensitivity will be 16.4 LSB/(°/s)
} GyroFullScale;

/// @brief Gyroscope Digital Low-pass Filter Bandwidths
typedef enum {
    GYRO_DLPF_250HZ = 0x00,  ///< 250 Hz
    GYRO_DLPF_184HZ = 0x01,  ///< 184 Hz
    GYRO_DLPF_92HZ = 0x02,   ///< 92 Hz
    GYRO_DLPF_41HZ = 0x03,   ///< 41 Hz
    GYRO_DLPF_20HZ = 0x04,   ///< 20 Hz
    GYRO_DLPF_10HZ = 0x05,   ///< 10 Hz
    GYRO_DLPF_5HZ = 0x06,    ///< 5Hz
    GYRO_DLPF_3600HZ = 0x07, ///< 3600 Hz
} GyroDLPFMode;

/// @brief Accelerometer Digital Low-pass Filter Bandwiths
typedef enum {
    ACCEL_DLPF_460HZ = 0x00, ///< 460 Hz
    ACCEL_DLPF_184HZ = 0x01, ///< 184 Hz
    ACCEL_DLPF_92HZ = 0x02,  ///< 92 Hz
    ACCEL_DLPF_41HZ = 0x03,  ///< 41 Hz
    ACCEL_DLPF_20HZ = 0x04,  ///< 20 Hz
    ACCEL_DLPF_10HZ = 0x05,  ///< 10 Hz
    ACCEL_DLPF_5Hz = 0x06,   ///< 5 Hz
} AccelDLPFMode;

/// @brief Used to bypass the gyroscope filter. Refer to page 14 of the register map doc.
typedef enum {
    FCHOICE_0 = 0x00,
    FCHOICE_1 = 0x01,
    FCHOICE_2 = 0x02,
    FCHOICE_3 = 0x03,
} GyroFChoice;

/// @brief Which clock source will the device use.
typedef enum
{
    CLOCK_INTERNAL = 0x00,   ///< Internal 20MHz oscillator
    CLOCK_PLL = 0x03,        ///< Auto selects the best clock source - PLL if ready, Internal clock otherwise.
    CLOCK_KEEP_RESET = 0x07, ///< Stops the clock and keeps timing generator in reset.
} ClockSource;


/// @brief Struct containing the basic configuration of the device, in order to make it work.
typedef struct {
    AccelFullScale accel_full_scale; ///< Accelerometer full scale range
    AccelDLPFMode accel_dlpf_mode;   ///< Accelerometer DLPF settings
    GyroFullScale gyro_full_scale;   ///< Gyroscope full scale range
    GyroFChoice gyro_fchoice;        ///< Gyroscope FChoice
    GyroDLPFMode gyro_dlpf_mode;     ///< Gyroscope DLPF settings
    uint16_t sample_rate;            ///< Sample Rate in Hz. Must be between 4 and 1000 Hz
} MPU6500_config_t;

/// @brief List of error codes related with the device.
typedef enum {
    MPU6500_ERROR_OK = I2C_PORT_ERROR_TOTAL, ///< Sent when everything's OK
    MPU6500_ERROR_I2C,                       ///< Error on the I2C interface.
    MPU6500_ERROR_DEVICE,                    ///< Error on the device.
} MPU6500ErrorCode;

/// @brief Initializes the I2C interface and then the device.
/// @param config Settings to be used during configuration.
/// @return MPU6500_ERROR_OK on success.
MPU6500ErrorCode MPU6500_init(const MPU6500_config_t* config);

/// @brief Performs a reset operation on the device.
/// @return MPU6500_ERROR_OK on success.
MPU6500ErrorCode MPU6500_reset();

/// @brief Sets the clock source.
/// @param source
/// @return MPU6500_ERROR_OK on success.
MPU6500ErrorCode MPU6500_set_clock_source(const ClockSource source);

/// @brief Sets the gyroscope full scale value
/// @param gyro_full_scale
/// @return MPU6500_ERROR_OK on success.
MPU6500ErrorCode MPU6500_set_gyro_full_scale(GyroFullScale gyro_full_scale);

/// @brief Sets the accelerometer full scale value
/// @param accel_full_scale
/// @return MPU6500_ERROR_OK on success.
MPU6500ErrorCode MPU6500_set_accel_full_scale(AccelFullScale accel_full_scale);

/// @brief Sets the gyroscope filter's bandwith
/// @param filter_mode
/// @return MPU6500_ERROR_OK on success.
MPU6500ErrorCode MPU6500_set_gyro_digital_low_pass_filter(GyroDLPFMode filter_mode);

/// @brief Gets the gyroscope filters's bandwith
/// @param filter_mode the value will be written here
/// @return MPU6500_ERROR_OK on success.
MPU6500ErrorCode MPU6500_get_gyro_digital_low_pass_filter(GyroDLPFMode* filter_mode);

/// @brief Sets the accelerometer filter's bandwith
/// @param filter_mode
/// @return MPU6500_ERROR_OK on success.
MPU6500ErrorCode MPU6500_set_accel_digital_low_pass_filter(AccelDLPFMode filter_mode);

/// @brief Gets the accelerometer filters's bandwith
/// @param filter_mode the value will be written here
/// @return MPU6500_ERROR_OK on success.
MPU6500ErrorCode MPU6500_get_accel_digital_low_pass_filter(AccelDLPFMode* filter_mode);

/// @brief Sets the gyroscope FChoice mode
/// @param fchoice
/// @return MPU6500_ERROR_OK on success.
MPU6500ErrorCode MPU6500_set_gyro_fchoice(GyroFChoice fchoice);

/// @brief Gets the gyroscope FChoice mode
/// @param fchoice the value will be written here
/// @return MPU6500_ERROR_OK on success.
MPU6500ErrorCode MPU6500_get_gyro_fchoice(GyroFChoice* fchoice);

/// @brief Set the device' sample rate
/// @param sample_rate in Hz, must be between [4-1000].
/// @return MPU6500_ERROR_OK on success.
MPU6500ErrorCode MPU6500_set_sample_rate(uint16_t sample_rate);

/// @brief Reads the sensor's internal temperature.
/// Then, the temperature can be calculated as <temperature>/333.87[LSB/°C]
/// @param temperature the measurement will be stored here
/// @return MPU6500_ERROR_OK on success.
MPU6500ErrorCode MPU6500_read_temperature_raw(int16_t* temperature);

/// @brief Reads the sensor's acceleration
/// @param x acceleration of the X axis
/// @param y acceleration of the Y axis
/// @param z acceleration of the Z axis
/// @return MPU6500_ERROR_OK on success.
MPU6500ErrorCode MPU6500_read_acceleration_raw(int16_t* x, int16_t* y, int16_t* z);

/// @brief Reads the sensor's rotation
/// @param x rotation over the X axis (Roll)
/// @param y rotation over the Y axis (Pitch)
/// @param z rotation over the Z axis (Yaw)
/// @return MPU6500_ERROR_OK on success.
MPU6500ErrorCode MPU6500_read_rotation_raw(int16_t* x, int16_t* y, int16_t* z);