#include "MPU6500.h"

#include "delay_port.h"
#include "i2c_port.h"


void MPU6500_init(const MPU6500_config_t* config)
{
    i2c_port_init(MPU_6500_DEFAULT_ADDRESS);

    uint8_t who_am_i;
    i2c_port_read_byte(MPU_6500_REG_WHO_AM_I, &who_am_i);

    if(who_am_i != MPU_6500_WHO_AM_I_VALUE) {
        return;
    }

    MPU6500_reset();

    MPU6500_set_clock_source(CLOCK_PLL);

    MPU6500_set_gyro_full_scale(config->gyro_full_scale);
    MPU6500_set_accel_full_scale(config->accel_full_scale);

    MPU6500_set_gyro_digital_low_pass_filter(config->gyro_dlpf_mode);
    MPU6500_set_accel_digital_low_pass_filter(config->accel_dlpf_mode);

    MPU6500_set_gyro_fchoice(config->gyro_fchoice);

    MPU6500_set_sample_rate(config->sample_rate);
}

void MPU6500_reset()
{
    i2c_port_write_bit(MPU_6500_REG_PWR_MGMT_1, MPU_6500_REG_PWR_MGMT_1_DEVICE_RESET_BIT, 1);
    delay_port_wait(100);
}

void MPU6500_set_clock_source(const ClockSource source)
{
    i2c_port_write_bits(MPU_6500_REG_PWR_MGMT_1, MPU_6500_REG_PWR_MGMT_1_DEVICE_CLKSEL_BIT, MPU_6500_REG_PWR_MGMT_1_DEVICE_CLKSEL_LENGHT, source);
}

void MPU6500_set_gyro_full_scale(GyroFullScale gyro_full_scale)
{
    i2c_port_write_bits(MPU_6500_REG_GYRO_CONFIG, MPU_6500_REG_GYRO_CONFIG_FS_SEL_BIT, MPU_6500_REG_GYRO_CONFIG_FS_SEL_LENGHT, gyro_full_scale);
}

void MPU6500_set_accel_full_scale(AccelFullScale accel_full_scale)
{
    i2c_port_write_bits(MPU_6500_REG_ACCEL_CONFIG, MPU_6500_REG_ACCEL_CONFIG_FS_SEL_BIT, MPU_6500_REG_ACCEL_CONFIG_FS_SEL_LENGHT, accel_full_scale);
}

void MPU6500_set_gyro_digital_low_pass_filter(GyroDLPFMode filter_mode)
{
    i2c_port_write_bits(MPU_6500_REG_CONFIG, MPU_6500_REG_CONFIG_DLPF_CFG_BIT, MPU_6500_REG_CONFIG_DLPF_CFG_LENGHT, filter_mode);
}

GyroDLPFMode MPU6500_get_gyro_digital_low_pass_filter()
{
    uint8_t ret = 0x00;
    i2c_port_read_bits(MPU_6500_REG_CONFIG, MPU_6500_REG_CONFIG_DLPF_CFG_BIT, MPU_6500_REG_CONFIG_DLPF_CFG_LENGHT, &ret);
    return (GyroDLPFMode)ret;
}

void MPU6500_set_accel_digital_low_pass_filter(AccelDLPFMode filter_mode)
{
    i2c_port_write_bits(MPU_6500_REG_ACCEL_CONFIG_2, MPU_6500_REG_ACCEL_CONFIG_2_A_DLPF_CFG_BIT, MPU_6500_REG_ACCEL_CONFIG_2_A_DLPF_CFG_LENGHT, filter_mode);
}

AccelDLPFMode MPU6500_get_accel_digital_low_pass_filter()
{
    uint8_t ret = 0x00;
    i2c_port_read_bits(MPU_6500_REG_ACCEL_CONFIG_2, MPU_6500_REG_ACCEL_CONFIG_2_A_DLPF_CFG_BIT, MPU_6500_REG_ACCEL_CONFIG_2_A_DLPF_CFG_LENGHT, &ret);
    return (AccelDLPFMode)ret;
}

void MPU6500_set_gyro_fchoice(GyroFChoice fchoice)
{
    i2c_port_write_bits(MPU_6500_REG_GYRO_CONFIG, MPU_6500_REG_GYRO_CONFIG_FCHOICE_B_BIT, MPU_6500_REG_GYRO_CONFIG_FCHOICE_B_LENGHT, fchoice);
}

GyroFChoice MPU6500_get_gyro_fchoice()
{
    uint8_t ret = 0x00;
    i2c_port_read_bits(MPU_6500_REG_GYRO_CONFIG, MPU_6500_REG_GYRO_CONFIG_FCHOICE_B_BIT, MPU_6500_REG_GYRO_CONFIG_FCHOICE_B_LENGHT, &ret);
    return (GyroFChoice)ret;
}

void MPU6500_set_sample_rate(uint16_t sample_rate)
{
    if(sample_rate < 4) { sample_rate = 4; }
    if(sample_rate > 1000) { sample_rate = 1000; }

    const uint16_t INTERNAL_SAMPLE_RATE = 1000;
    uint16_t divider = INTERNAL_SAMPLE_RATE / sample_rate - 1;
    i2c_port_write_byte(MPU_6500_REG_SMPLRT_DIV, (uint8_t)divider);
}

void MPU6500_read_temperature(int16_t* temperature)
{
    uint8_t buffer[2] = {0};
    i2c_port_read_bytes(MPU_6500_REG_TEMP_OUT_H, 2, buffer);
    *temperature = buffer[0] << 8 | buffer[1];
}

void MPU6500_read_acceleration_raw(int16_t* x, int16_t* y, int16_t* z)
{
    uint8_t buffer[6] = {0};
    i2c_port_read_bytes(MPU_6500_REG_ACCEL_XOUT_H, 6, buffer);
    *x = buffer[0] << 8 | buffer[1];
    *y = buffer[2] << 8 | buffer[3];
    *z = buffer[4] << 8 | buffer[5];
}

void MPU6500_read_rotation_raw(int16_t* x, int16_t* y, int16_t* z)
{
    uint8_t buffer[6] = {0};
    i2c_port_read_bytes(MPU_6500_REG_GYRO_XOUT_H, 6, buffer);
    *x = buffer[0] << 8 | buffer[1];
    *y = buffer[2] << 8 | buffer[3];
    *z = buffer[4] << 8 | buffer[5];
}
