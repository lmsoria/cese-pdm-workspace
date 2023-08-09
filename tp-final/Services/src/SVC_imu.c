#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "API_delay.h"
#include "API_uart.h"

#include "SVC_imu.h"
#include "SVC_protocol.h"

#include "MPU6500.h"

#define IMU_FSM_SAMPLE_RATE_MS 100

#define UART_TX_BUFFER_SIZE 256

typedef enum
{
    IMU_IDLE = 0,
    IMU_STREAMING,
    IMU_FSM_STATES_QTY, ///< Always keep this value at the bottom!
} IMUFSMState;


static delay_t imu_delay = {};
static IMUFSMState current_state = IMU_IDLE;
static bool_t button_pressed = false;
static IMUMeasurementReadyCommand command;

static void svc_imu_tx_data();

void svc_imu_init()
{
    const MPU6500_config_t CONFIG =
    {
        .accel_full_scale = ACCEL_FS_4g,
        .gyro_full_scale = GYRO_FS_500dps,
        .accel_dlpf_mode = ACCEL_DLPF_41HZ,
        .gyro_dlpf_mode = GYRO_DLPF_41HZ,
        .gyro_fchoice = FCHOICE_0,
        .sample_rate = 100
    };

    assert(uart_init());
    MPU6500_init(&CONFIG);
    current_state = IMU_IDLE;
    delay_init(&imu_delay, IMU_FSM_SAMPLE_RATE_MS);
}


void svc_imu_button_pressed() { button_pressed = true; }
//void svc_imu_button_pressed() { svc_imu_tx_data(); }

void svc_imu_fsm_update()
{
    switch(current_state)
    {
    case IMU_IDLE:
        if(button_pressed) {
            current_state = IMU_STREAMING;
            button_pressed = false;
        }
        break;
    case IMU_STREAMING:
        if(button_pressed) {
            current_state = IMU_IDLE;
            button_pressed = false;
        }
        if(delay_read(&imu_delay)) {
            svc_imu_tx_data();
        }
        break;
    default:
        assert(false && "Invalid state");
        break;
    }
}



static void svc_imu_tx_data()
{
    MPU6500_read_acceleration_raw(&command.measurement.accel_x, &command.measurement.accel_y, &command.measurement.accel_z);
    MPU6500_read_rotation_raw(&command.measurement.gyro_x, &command.measurement.gyro_y, &command.measurement.gyro_z);

    command.header.magic_word = 0xaa;
    command.footer.magic_word = 0x55;
    uart_send_string_size((uint8_t*)(&command), sizeof(command));
}
