#pragma once
#include <stdint.h>

void i2c_port_init(uint8_t slave_address);

/// @brief Read a single bit from a register.
/// @param register_address 
/// @param bit_number 
/// @param data 
void i2c_port_read_bit(uint8_t register_address, uint8_t bit_number, uint8_t* data);

/// @brief Read a range of bits from a single register.
/// @param register_address 
/// @param bit_start 
/// @param length 
/// @param data 
void i2c_port_read_bits(uint8_t register_address, uint8_t bit_start, uint8_t length, uint8_t* data);

/// @brief Read a single register.
/// @param register_address 
/// @param data 
void i2c_port_read_byte(uint8_t register_address, uint8_t* data);

/// @brief Read data from consecutive registers.
/// @param register_address 
/// @param length 
/// @param data 
void i2c_port_read_bytes(uint8_t register_address, uint8_t length, uint8_t* data);

/// @brief Write a single bit from a register
/// @param register_address 
/// @param bit_number 
/// @param data 
void i2c_port_write_bit(uint8_t register_address, uint8_t bit_number, uint8_t data);

/// @brief Write a range of bits to a register
/// @param register_address 
/// @param bit_start 
/// @param length 
/// @param data 
void i2c_port_write_bits(uint8_t register_address, uint8_t bit_start, uint8_t length, uint8_t data);

/// @brief Write a value to a single register.
/// @param register_address 
/// @param data 
void i2c_port_write_byte(uint8_t register_address, uint8_t data);

/// @brief Write a data sequence to consecutive registers.
/// @param register_address 
/// @param length 
/// @param data 
void i2c_port_write_bytes(uint8_t register_address, uint8_t length, uint8_t* data);