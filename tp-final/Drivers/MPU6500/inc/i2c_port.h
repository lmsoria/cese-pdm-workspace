#pragma once
#include <stdint.h>

/// @brief Enum used for retrieving the status of the I2C operations.
/// @TODO: Add more error codes.
typedef enum
{
    I2C_PORT_OK = 0x00,   ///< This should be sent on success.
    I2C_PORT_ERROR,       ///< Send this if anything happens.
    I2C_PORT_ERROR_TOTAL, ///< Keep this value always at the bottom, it'll be used as reference for MPU6500 driver error codification.
} I2CPortError;

/// @brief Initialize an I2C device that'll communicate with a single slave
/// @param slave_address This address will be used by the rest of the API.
/// @return I2C_PORT_OK on success
I2CPortError i2c_port_init(const uint8_t slave_address);

/// @brief Read a single bit from a register, ie:
/// ----------------------------------------------------------------
/// | bit 7 | bit 6 | bit 5 | bit 4 | bit 3 | bit 2 | bit 1 | bit 0 |
/// ----------------------------------------------------------------
///                     ^
///                 bit_number = data
/// ----------------------------------------------------------------
/// @param register_address
/// @param bit_number
/// @param data
/// @return I2C_PORT_OK on success
I2CPortError i2c_port_read_bit(const uint8_t register_address, const uint8_t bit_number, uint8_t* const data);

/// @brief Read a range of bits from a single register, ie:
/// ----------------------------------------------------------------
/// | bit 7 | bit 6 | bit 5 | bit 4 | bit 3 | bit 2 | bit 1 | bit 0 |
/// ----------------------------------------------------------------
///                     ^_______________________^
///               bit_start = data            length
/// ----------------------------------------------------------------
/// @param register_address
/// @param bit_start this must be the MSbit of `data`
/// @param length
/// @param data
/// @return I2C_PORT_OK on success
I2CPortError i2c_port_read_bits(const uint8_t register_address, const uint8_t bit_start, const uint8_t length, uint8_t* const data);

/// @brief Read a single register.
/// @param register_address
/// @param data
/// @return I2C_PORT_OK on success
I2CPortError i2c_port_read_byte(const uint8_t register_address, uint8_t* const data);

/// @brief Read data from consecutive registers.
/// @param register_address
/// @param length
/// @param data
/// @return I2C_PORT_OK on success
I2CPortError i2c_port_read_bytes(const uint8_t register_address, const uint8_t length, uint8_t* const data);

/// @brief Write a single bit from a register, ie:
/// ----------------------------------------------------------------
/// | bit 7 | bit 6 | bit 5 | bit 4 | bit 3 | bit 2 | bit 1 | bit 0 |
/// ----------------------------------------------------------------
///                     ^
///                 bit_number = data
/// ----------------------------------------------------------------
/// @param register_address
/// @param bit_number
/// @param data
/// @return I2C_PORT_OK on success
I2CPortError i2c_port_write_bit(const uint8_t register_address, const uint8_t bit_number, const uint8_t data);

/// @brief Write a range of bits to a register, ie
/// ----------------------------------------------------------------
/// | bit 7 | bit 6 | bit 5 | bit 4 | bit 3 | bit 2 | bit 1 | bit 0 |
/// ----------------------------------------------------------------
///                     ^_______________________^
///               bit_start = data            length
/// ----------------------------------------------------------------
/// @param register_address
/// @param bit_start this must be the MSbit of `data`
/// @param length
/// @param data
/// @return I2C_PORT_OK on success
I2CPortError i2c_port_write_bits(const uint8_t register_address, const uint8_t bit_start, const uint8_t length, const uint8_t data);

/// @brief Write a value to a single register.
/// @param register_address
/// @param data
/// @return I2C_PORT_OK on success
I2CPortError i2c_port_write_byte(const uint8_t register_address, uint8_t data);

/// @brief Write a data sequence to consecutive registers.
/// @param register_address
/// @param length
/// @param data
/// @return I2C_PORT_OK on success
I2CPortError i2c_port_write_bytes(const uint8_t register_address, const uint8_t length, uint8_t* const data);
