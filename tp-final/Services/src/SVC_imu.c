#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "API_delay.h"
#include "API_uart.h"

#include "SVC_imu.h"

#define IMU_FSM_SAMPLE_RATE_MS 1000

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
static uint8_t uart_tx_buffer[UART_TX_BUFFER_SIZE] = {0};

#define DUMMY_VALUES_SIZE 5
static int32_t dummy_values[DUMMY_VALUES_SIZE] = { -2, -1, 0, 1, 2 };
static char dummy_value_str[3] = {0};

static void svc_imu_tx_data();

void svc_imu_init()
{
    assert(uart_init());
    current_state = IMU_IDLE;
    delay_init(&imu_delay, IMU_FSM_SAMPLE_RATE_MS);
}


void svc_imu_button_pressed() { button_pressed = true; }

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
    static uint8_t dummy_value_index = 2;
    itoa(dummy_values[dummy_value_index], dummy_value_str, 10);
    snprintf((char*)uart_tx_buffer, UART_TX_BUFFER_SIZE, "[%s] hello!\r\n", dummy_value_str);
    uart_send_string(uart_tx_buffer);
    dummy_value_index = (dummy_value_index + 1) % DUMMY_VALUES_SIZE;
}
