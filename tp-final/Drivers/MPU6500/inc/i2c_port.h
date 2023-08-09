#pragma once

void i2c_port_init(uint8_t slave_address);


void i2c_port_write_bit(uint8_t register_address, uint8_t bit_number, uint8_t data);
/*! Write a range of bits to a register */
void i2c_port_write_bits(uint8_t register_address, uint8_t bit_start, uint8_t length, uint8_t data);
/*! Write a value to a register */
void i2c_port_write_byte(uint8_t register_address, uint8_t data);
/*! Write a sequence to data to a sequence of registers */
void i2c_port_write_bytes(uint8_t register_address, uint8_t length, uint8_t* data);

void i2c_port_read_byte(uint8_t register_address, uint8_t* data);
