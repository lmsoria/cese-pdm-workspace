#pragma once

#include <stdint.h>

typedef enum
{
    SERVO_STATE_CHANGED = 0,
    IMU_STREAMING_CHANGED = 1,
    IMU_MEASUREMENT_READY,
} CommandOPCode;

typedef enum
{
    SRC_BOARD = 0x10,
    SRC_PC = 0x20,
} SourceID;

const uint8_t SRC_MASK = 0xF0;

typedef enum
{
    DEST_BOARD = 0x01,
    DEST_PC = 0x02,
} DestinationID;

const uint8_t DEST_MASK = 0x0F;


#pragma pack(push, 1)

typedef struct
{
    uint8_t magic_word;
} ProtocolHeader;

typedef struct
{
    ProtocolHeader header;
    uint8_t data[];
} Message;

typedef struct
{
    int16_t accel_x;
    int16_t accel_y;
    int16_t accel_z;
    int16_t gyro_x;
    int16_t gyro_y;
    int16_t gyro_z;
} IMUMeasurement;

typedef struct
{
    ProtocolHeader header;
    IMUMeasurement measurement;
    ProtocolHeader footer;
} IMUMeasurementReadyCommand;

#pragma pack(pop)
