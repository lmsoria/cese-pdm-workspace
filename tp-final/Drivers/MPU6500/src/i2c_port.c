#include "i2c.h"

#include "i2c_port.h"

static I2C_HandleTypeDef i2c_handler;
static uint8_t port_slave_address = 0;

I2CPortError i2c_port_init(const uint8_t slave_address)
{
    MX_I2C1_Init(&i2c_handler);
    port_slave_address = slave_address;
    return I2C_PORT_OK;
}

I2CPortError i2c_port_read_bit(const uint8_t register_address, const uint8_t bit_number, uint8_t* const data)
{
    if(bit_number < 0 || bit_number > 7) { return I2C_PORT_ERROR; }

    uint8_t register_value = 0x00;
    HAL_StatusTypeDef status = HAL_I2C_Mem_Read(&i2c_handler, port_slave_address, register_address, 1, &register_value, 1, HAL_MAX_DELAY);

    if(status != HAL_OK) {
        return I2C_PORT_ERROR;
    }

    *data = (register_value >> bit_number & 0x01);
    return I2C_PORT_OK;
}

I2CPortError i2c_port_read_bits(const uint8_t register_address, const uint8_t bit_start, const uint8_t length, uint8_t* const data)
{
    if (bit_start < 0 || bit_start > 7 || length < 1 || length > 8) { return I2C_PORT_ERROR; }

    uint8_t register_value = 0x00;
    HAL_StatusTypeDef status = HAL_I2C_Mem_Read(&i2c_handler, port_slave_address, register_address, 1, &register_value, 1, HAL_MAX_DELAY);

    if(status != HAL_OK) {
        return I2C_PORT_ERROR;
    }

    uint8_t bit_position = bit_start - length + 1;  // Calculate LSB position
    uint8_t mask = (1 << length) - 1;
    *data = (register_value >> bit_position) & mask;

    return I2C_PORT_OK;
}

I2CPortError i2c_port_read_byte(const uint8_t register_address, uint8_t* const data)
{
    HAL_StatusTypeDef status = HAL_I2C_Mem_Read(&i2c_handler, port_slave_address, register_address, 1, data, 1, HAL_MAX_DELAY);
    return (status == HAL_OK) ? I2C_PORT_OK : I2C_PORT_ERROR;
}

I2CPortError i2c_port_read_bytes(uint8_t register_address, const uint8_t length, uint8_t* const data)
{
    HAL_StatusTypeDef status = HAL_I2C_Mem_Read(&i2c_handler, port_slave_address, register_address, 1, data, length, HAL_MAX_DELAY);
    return (status == HAL_OK) ? I2C_PORT_OK : I2C_PORT_ERROR;
}

I2CPortError i2c_port_write_bit(const uint8_t register_address, const uint8_t bit_number, const uint8_t data)
{
    if(bit_number < 0 || bit_number > 7) { return I2C_PORT_ERROR; }

    uint8_t register_value = 0x00;

    // First retrieve existing value
    HAL_StatusTypeDef status = HAL_I2C_Mem_Read(&i2c_handler, port_slave_address, register_address, 1, &register_value, 1, HAL_MAX_DELAY);

    if(status != HAL_OK) {
        return I2C_PORT_ERROR;
    }

    // This sets the `bit_number` position to `data`
    register_value = (register_value & ~(1UL << bit_number)) | (data << bit_number);

    status = HAL_I2C_Mem_Write(&i2c_handler, port_slave_address, register_address, 1, &register_value, 1, HAL_MAX_DELAY);

    return (status == HAL_OK) ? I2C_PORT_OK : I2C_PORT_ERROR;

}

I2CPortError i2c_port_write_bits(const uint8_t register_address, const uint8_t bit_start, const uint8_t length, const uint8_t data)
{
    if (bit_start < 0 || bit_start > 7 || length < 1 || length > 8) { return I2C_PORT_ERROR; }

    uint8_t register_value = 0x00;

    // First retrieve existing value
    HAL_StatusTypeDef status = HAL_I2C_Mem_Read(&i2c_handler, port_slave_address, register_address, 1, &register_value, 1, HAL_MAX_DELAY);

    if(status != HAL_OK) {
        return I2C_PORT_ERROR;
    }

    uint8_t lsb_position = bit_start - length + 1;  // Calculate LSB position
    uint8_t mask = ((1 << length) - 1) << lsb_position;
    register_value = (register_value & ~mask) | ((data << lsb_position) & mask);

    status = HAL_I2C_Mem_Write(&i2c_handler, port_slave_address, register_address, 1, &register_value, 1, HAL_MAX_DELAY);
    return (status == HAL_OK) ? I2C_PORT_OK : I2C_PORT_ERROR;

}

I2CPortError i2c_port_write_byte(const uint8_t register_address, uint8_t data)
{
    HAL_StatusTypeDef status = HAL_I2C_Mem_Write(&i2c_handler, port_slave_address, register_address, 1, &data, 1, HAL_MAX_DELAY);
    return (status == HAL_OK) ? I2C_PORT_OK : I2C_PORT_ERROR;
}

I2CPortError i2c_port_write_bytes(const uint8_t register_address, const uint8_t length, uint8_t* const data)
{
    HAL_StatusTypeDef status = HAL_I2C_Mem_Write(&i2c_handler, port_slave_address, register_address, 1, data, length, HAL_MAX_DELAY);
    return (status == HAL_OK) ? I2C_PORT_OK : I2C_PORT_ERROR;
}
