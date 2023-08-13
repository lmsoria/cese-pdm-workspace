#pragma once

#include <stdint.h>

#define HEADER_MAGIC_WORD 0xaa
#define FOOTER_MAGIC_WORD 0x55

#pragma pack(push, 1)

/// @brief struct used as prefix for any transmitted message
typedef struct
{
    uint8_t magic_word; ///< Fixed-value character that will be used for recognizing
                        ///  the beginning of a frame during a transaction.
} ProtocolHeader;

/// @brief struct used as suffix for any transmitted message
typedef struct
{
    uint8_t magic_word; ///< Fixed-value character that will be used for recognizing
                        ///  the end of a frame during a transaction.
} ProtocolFooter;

/// @brief wrapper containing all the IMU measurements.
typedef struct
{
    int16_t accel_x;
    int16_t accel_y;
    int16_t accel_z;
    int16_t gyro_x;
    int16_t gyro_y;
    int16_t gyro_z;
} IMUMeasurement;

/// @brief Message sent through UART
typedef struct
{
    ProtocolHeader header;
    IMUMeasurement measurement;
    ProtocolFooter footer;
} IMUMeasurementReadyCommand;

#pragma pack(pop)
