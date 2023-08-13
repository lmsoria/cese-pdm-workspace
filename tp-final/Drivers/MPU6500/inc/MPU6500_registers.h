#pragma once

/// MPU6500 Register Map
/// This header file was creating by taking the following document as reference:
/// https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6500-Register-Map2.pdf
///
/// All register addresses are defined here. However, only for the registers used
/// in this project the internal bits and bit lenghts were defined.
/// The addresses are in hex format, while the bits and bit lengts are in decimal
/// format, sorrounded by parenthesis ().

/// -------------- Gyroscope Self-Test Registers -------------
#define MPU_6500_REG_SELF_TEST_X_GYRO                     0x00
#define MPU_6500_REG_SELF_TEST_Y_GYRO                     0x01
#define MPU_6500_REG_SELF_TEST_Z_GYRO                     0x02
/// ----------------------------------------------------------

/// ------------ Accelerometer Self-Test Registers -----------
#define MPU_6500_REG_SELF_TEST_X_ACCEL                    0x0D
#define MPU_6500_REG_SELF_TEST_Y_ACCEL                    0x0E
#define MPU_6500_REG_SELF_TEST_Z_ACCEL                    0x0F
/// ----------------------------------------------------------

/// --------------- Gyroscope Offset Registers ---------------
#define MPU_6500_REG_XG_OFFSET_H                          0x13
#define MPU_6500_REG_XG_OFFSET_L                          0x14
#define MPU_6500_REG_YG_OFFSET_H                          0x15
#define MPU_6500_REG_YG_OFFSET_L                          0x16
#define MPU_6500_REG_ZG_OFFSET_H                          0x17
#define MPU_6500_REG_ZG_OFFSET_L                          0x18
/// ----------------------------------------------------------

/// ------------------- Sample Rate Divider ------------------
#define MPU_6500_REG_SMPLRT_DIV                           0x19
/// ----------------------------------------------------------

// ----------------------- Configuration ---------------------
#define MPU_6500_REG_CONFIG                               0x1A
#define MPU_6500_REG_CONFIG_FIFO_MODE_BIT                 (6)
#define MPU_6500_REG_CONFIG_EXT_SYNC_SET_BIT              (5) // [5:3]
#define MPU_6500_REG_CONFIG_EXT_SYNC_SET_LENGHT           (3)
#define MPU_6500_REG_CONFIG_DLPF_CFG_BIT                  (2) // [2:0]
#define MPU_6500_REG_CONFIG_DLPF_CFG_LENGHT               (3)
/// ----------------------------------------------------------

// ----------------- Gyroscope Configuration -----------------
#define MPU_6500_REG_GYRO_CONFIG                          0x1B
#define MPU_6500_REG_GYRO_CONFIG_XG_ST_BIT                (7)
#define MPU_6500_REG_GYRO_CONFIG_YG_ST_BIT                (6)
#define MPU_6500_REG_GYRO_CONFIG_ZG_ST_BIT                (5)
#define MPU_6500_REG_GYRO_CONFIG_FS_SEL_BIT               (4) // [4:3]
#define MPU_6500_REG_GYRO_CONFIG_FS_SEL_LENGHT            (2)
#define MPU_6500_REG_GYRO_CONFIG_FCHOICE_B_BIT            (1) // [1:0]
#define MPU_6500_REG_GYRO_CONFIG_FCHOICE_B_LENGHT         (2)
/// ----------------------------------------------------------

// --------------- Accelerometer Configuration ---------------
#define MPU_6500_REG_ACCEL_CONFIG                         0x1C
#define MPU_6500_REG_ACCEL_CONFIG_XA_ST_BIT               (7)
#define MPU_6500_REG_ACCEL_CONFIG_YA_ST_BIT               (6)
#define MPU_6500_REG_ACCEL_CONFIG_ZA_ST_BIT               (5)
#define MPU_6500_REG_ACCEL_CONFIG_FS_SEL_BIT              (4) // [4:3]
#define MPU_6500_REG_ACCEL_CONFIG_FS_SEL_LENGHT           (2)
/// ----------------------------------------------------------

// -------------- Accelerometer Configuration 2 --------------
#define MPU_6500_REG_ACCEL_CONFIG_2                       0x1D
#define MPU_6500_REG_ACCEL_CONFIG_2_ACCEL_FC_CHOICE_B_BIT (3)
#define MPU_6500_REG_ACCEL_CONFIG_2_A_DLPF_CFG_BIT        (2) // [2:0]
#define MPU_6500_REG_ACCEL_CONFIG_2_A_DLPF_CFG_LENGHT     (3)
/// ----------------------------------------------------------

/// ----------- Low Power Accelerometer ODR Control ----------
#define MPU_6500_REG_LP_ACCEL_ODR                         0x1E
/// ----------------------------------------------------------

/// ---------------- Wake-on Motion Threshold ----------------
#define MPU_6500_REG_WOM_THR                              0x1F
/// ----------------------------------------------------------

/// ----------------------- FIFO Enable ----------------------
#define MPU_6500_REG_FIFO_EN                              0x23
/// ----------------------------------------------------------

/// --------------------- I2C Master Control -----------------
#define MPU_6500_REG_I2C_MST_CTRL                         0x24
/// ----------------------------------------------------------

/// ------------------- I2C Slave 0 Control ------------------
#define MPU_6500_REG_I2C_SLV0_ADDR                        0x25
#define MPU_6500_REG_I2C_SLV0_REG                         0x26
#define MPU_6500_REG_I2C_SLV0_CTRL                        0x27
/// ----------------------------------------------------------

/// ------------------- I2C Slave 1 Control ------------------
#define MPU_6500_REG_I2C_SLV1_ADDR                        0x28
#define MPU_6500_REG_I2C_SLV1_REG                         0x29
#define MPU_6500_REG_I2C_SLV1_CTRL                        0x2A
/// ----------------------------------------------------------

/// ------------------- I2C Slave 2 Control ------------------
#define MPU_6500_REG_I2C_SLV2_ADDR                        0x2B
#define MPU_6500_REG_I2C_SLV2_REG                         0x2C
#define MPU_6500_REG_I2C_SLV2_CTRL                        0x2D
/// ----------------------------------------------------------

/// ------------------- I2C Slave 3 Control ------------------
#define MPU_6500_REG_I2C_SLV3_ADDR                        0x2E
#define MPU_6500_REG_I2C_SLV3_REG                         0x2F
#define MPU_6500_REG_I2C_SLV3_CTRL                        0x30
/// ----------------------------------------------------------

/// ------------------- I2C Slave 4 Control ------------------
#define MPU_6500_REG_I2C_SLV4_ADDR                        0x31
#define MPU_6500_REG_I2C_SLV4_REG                         0x32
#define MPU_6500_REG_I2C_SLV4_DO                          0x33
#define MPU_6500_REG_I2C_SLV4_CTRL                        0x34
#define MPU_6500_REG_I2C_SLV4_DI                          0x35
/// ----------------------------------------------------------

/// -------------------- I2C Master Status -------------------
#define MPU_6500_REG_I2C_MST_STATUS                       0x36
/// ----------------------------------------------------------

/// ----------- INT Pin/Bypass Enable Configuration ----------
#define MPU_6500_REG_INT_PIN_CFG                          0x37
/// ----------------------------------------------------------

/// --------------------- Interrupt Enable -------------------
#define MPU_6500_REG_INT_ENABLE                           0x38
/// ----------------------------------------------------------

/// --------------------- Interrupt Status -------------------
#define MPU_6500_REG_INT_STATUS                           0x3A
/// ----------------------------------------------------------

/// --------------- Accelerometer Measurements ---------------
#define MPU_6500_REG_ACCEL_XOUT_H                         0x3B
#define MPU_6500_REG_ACCEL_XOUT_L                         0x3C
#define MPU_6500_REG_ACCEL_YOUT_H                         0x3D
#define MPU_6500_REG_ACCEL_YOUT_L                         0x3E
#define MPU_6500_REG_ACCEL_ZOUT_H                         0x3F
#define MPU_6500_REG_ACCEL_ZOUT_L                         0x40
/// ----------------------------------------------------------

/// ----------------- Temperature Measurement ----------------
#define MPU_6500_REG_TEMP_OUT_H                           0x41
#define MPU_6500_REG_TEMP_OUT_L                           0x42
/// ----------------------------------------------------------

/// ------------------ Gyroscope Measurements ----------------
#define MPU_6500_REG_GYRO_XOUT_H                          0x43
#define MPU_6500_REG_GYRO_XOUT_L                          0x44
#define MPU_6500_REG_GYRO_YOUT_H                          0x45
#define MPU_6500_REG_GYRO_YOUT_L                          0x46
#define MPU_6500_REG_GYRO_ZOUT_H                          0x47
#define MPU_6500_REG_GYRO_ZOUT_L                          0x48
/// ----------------------------------------------------------

/// ------------------ External Sensor Data ------------------
#define MPU_6500_REG_EXT_SENS_DATA_00                     0x49
#define MPU_6500_REG_EXT_SENS_DATA_01                     0x4A
#define MPU_6500_REG_EXT_SENS_DATA_02                     0x4B
#define MPU_6500_REG_EXT_SENS_DATA_03                     0x4C
#define MPU_6500_REG_EXT_SENS_DATA_04                     0x4D
#define MPU_6500_REG_EXT_SENS_DATA_05                     0x4E
#define MPU_6500_REG_EXT_SENS_DATA_06                     0x4F
#define MPU_6500_REG_EXT_SENS_DATA_07                     0x50
#define MPU_6500_REG_EXT_SENS_DATA_08                     0x51
#define MPU_6500_REG_EXT_SENS_DATA_09                     0x52
#define MPU_6500_REG_EXT_SENS_DATA_10                     0x53
#define MPU_6500_REG_EXT_SENS_DATA_11                     0x54
#define MPU_6500_REG_EXT_SENS_DATA_12                     0x55
#define MPU_6500_REG_EXT_SENS_DATA_13                     0x56
#define MPU_6500_REG_EXT_SENS_DATA_14                     0x57
#define MPU_6500_REG_EXT_SENS_DATA_15                     0x58
#define MPU_6500_REG_EXT_SENS_DATA_16                     0x59
#define MPU_6500_REG_EXT_SENS_DATA_17                     0x5A
#define MPU_6500_REG_EXT_SENS_DATA_18                     0x5B
#define MPU_6500_REG_EXT_SENS_DATA_19                     0x5C
#define MPU_6500_REG_EXT_SENS_DATA_20                     0x5D
#define MPU_6500_REG_EXT_SENS_DATA_21                     0x5E
#define MPU_6500_REG_EXT_SENS_DATA_22                     0x5F
#define MPU_6500_REG_EXT_SENS_DATA_23                     0x60
/// ----------------------------------------------------------

/// ------------------- I2C Slave 0 Data Out -----------------
#define MPU_6500_REG_I2C_SLV0_DO                          0x63
/// ----------------------------------------------------------

/// ------------------- I2C Slave 1 Data Out -----------------
#define MPU_6500_REG_I2C_SLV1_DO                          0x64
/// ----------------------------------------------------------

/// ------------------- I2C Slave 2 Data Out -----------------
#define MPU_6500_REG_I2C_SLV2_DO                          0x65
/// ----------------------------------------------------------

/// ------------------- I2C Slave 3 Data Out -----------------
#define MPU_6500_REG_I2C_SLV3_DO                          0x66
/// ----------------------------------------------------------

/// ----------------- I2C Master Delay Control ---------------
#define MPU_6500_REG_I2C_MST_DELAY_CTRL                   0x67
/// ----------------------------------------------------------

/// ------------------ I2C Signal Path Reset -----------------
#define MPU_6500_REG_SIGNAL_PATH_RESET                    0x68
/// ----------------------------------------------------------

/// ------------- Accelerometer Interrupt Control ------------
#define MPU_6500_REG_ACCEL_INTEL_CTRL                     0x69
/// ----------------------------------------------------------

/// ---------------------- User Control ----------------------
#define MPU_6500_REG_USER_CTRL                            0x6A
/// ----------------------------------------------------------

/// ------------------- Power Management 1 -------------------
#define MPU_6500_REG_PWR_MGMT_1                           0x6B
#define MPU_6500_REG_PWR_MGMT_1_DEVICE_RESET_BIT          (7)
#define MPU_6500_REG_PWR_MGMT_1_DEVICE_SLEEP_BIT          (6)
#define MPU_6500_REG_PWR_MGMT_1_DEVICE_CYCLE_BIT          (5)
#define MPU_6500_REG_PWR_MGMT_1_DEVICE_GYRO_STANDBY_BIT   (4)
#define MPU_6500_REG_PWR_MGMT_1_DEVICE_TEMP_DIS_BIT       (3)
#define MPU_6500_REG_PWR_MGMT_1_DEVICE_CLKSEL_BIT         (2) // [2:0]
#define MPU_6500_REG_PWR_MGMT_1_DEVICE_CLKSEL_LENGHT      (3)
/// ----------------------------------------------------------

/// ------------------- Power Management 2 -------------------
#define MPU_6500_REG_PWR_MGMT_2                           0x6C
#define MPU_6500_REG_PWR_MGMT_2_DIS_XA_BIT                (5)
#define MPU_6500_REG_PWR_MGMT_2_DIS_YA_BIT                (4)
#define MPU_6500_REG_PWR_MGMT_2_DIS_ZA_BIT                (3)
#define MPU_6500_REG_PWR_MGMT_2_DIS_XG_BIT                (2)
#define MPU_6500_REG_PWR_MGMT_2_DIS_YG_BIT                (1)
#define MPU_6500_REG_PWR_MGMT_2_DIS_ZG_BIT                (0)
/// ----------------------------------------------------------

/// ------------------ FIFO Count Registers ------------------
#define MPU_6500_REG_FIFO_COUNT_H                         0x72
#define MPU_6500_REG_FIFO_COUNT_L                         0x73
/// ----------------------------------------------------------

/// ----- FIFO Read/Write -----
#define MPU_6500_REG_FIFO_R_W                             0x74
/// ----------------------------------------------------------

/// ------------------------ Who Am I? -----------------------
#define MPU_6500_REG_WHO_AM_I                             0x75
/// ----------------------------------------------------------

/// ------------- Accelerometer Offset Registers -------------
#define MPU_6500_REG_XA_OFFSET_H                          0x77
#define MPU_6500_REG_XA_OFFSET_L                          0x78
#define MPU_6500_REG_YA_OFFSET_H                          0x7A
#define MPU_6500_REG_YA_OFFSET_L                          0x7C
#define MPU_6500_REG_ZA_OFFSET_H                          0x7C
#define MPU_6500_REG_ZA_OFFSET_L                          0x7D
/// ----------------------------------------------------------