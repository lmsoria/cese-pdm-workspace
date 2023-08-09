#include "i2c.h"

#include "i2c_port.h"

static I2C_HandleTypeDef i2c_handler;
static uint8_t port_slave_address = 0;

void i2c_port_init(uint8_t slave_address)
{
    MX_I2C1_Init(&i2c_handler);
    port_slave_address = slave_address;

    uint8_t who_am_i = 0;
//    i2c_port_read_byte(0x75, &who_am_i);

//    HAL_I2C_Mem_Read(&i2c_handler, MPU_6500_DEFAULT_ADDRESS | 0x01 , MPU_6500_REG_WHO_AM_I, 1, &who_am_i, sizeof(who_am_i), HAL_MAX_DELAY);
    i2c_port_write_bits(0, 4, 3, 0b110);
}


void i2c_port_write_bit(uint8_t register_address, uint8_t bit_number, uint8_t data)
{
    uint8_t register_value = 0x00;

    // First retrieve existing value
    HAL_I2C_Mem_Read(&i2c_handler, port_slave_address, register_address, 1, &register_value, 1, HAL_MAX_DELAY);

    // This sets the `bit_number` position to `data`
    register_value = (register_value & ~(1UL << bit_number)) | (data << bit_number);

    HAL_I2C_Mem_Write(&i2c_handler, port_slave_address, register_address, 1, &register_value, 1, HAL_MAX_DELAY);
}
///*! Write a range of bits to a register */
void i2c_port_write_bits(uint8_t register_address, uint8_t bit_start, uint8_t length, uint8_t data)
{
    uint8_t register_value = 0x00;

    // First retrieve existing value
    HAL_I2C_Mem_Read(&i2c_handler, port_slave_address, register_address, 1, &register_value, 1, HAL_MAX_DELAY);

    uint8_t lsb_position = bit_start - length + 1;  // Calculate LSB position
    uint8_t mask = ((1 << length) - 1) << lsb_position;
    register_value = (register_value & ~mask) | ((data << lsb_position) & mask);

    HAL_I2C_Mem_Write(&i2c_handler, port_slave_address, register_address, 1, &register_value, 1, HAL_MAX_DELAY);

}
///*! Write a value to a register */
void i2c_port_write_byte(uint8_t register_address, uint8_t data)
{
    HAL_I2C_Mem_Write(&i2c_handler, port_slave_address, register_address, 1, &data, 1, HAL_MAX_DELAY);
}
///*! Write a sequence to data to a sequence of registers */
void i2c_port_write_bytes(uint8_t register_address, uint8_t length, uint8_t* data)
{
    HAL_I2C_Mem_Write(&i2c_handler, port_slave_address, register_address, length, data, length, HAL_MAX_DELAY);
}


void i2c_port_read_byte(uint8_t register_address, uint8_t* data)
{
    HAL_I2C_Mem_Read(&i2c_handler, port_slave_address, register_address, 1, data, 1, HAL_MAX_DELAY);
}
