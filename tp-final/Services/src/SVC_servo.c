#include <assert.h>
#include "API_delay.h"
#include "API_pwm.h"
#include "SVC_servo.h"

#define SERVO_FSM_DELAY_TIMEOUT_MS 2000

typedef enum
{
    SERVO_IDLE = 0,       ///< Initial/default state. The servo will be at 90 degrees.
    SERVO_POSITION_0,     ///< The servo will be at 0 degrees
    SERVO_POSITION_180,   ///< The servo will be at 180 degrees
    SERVO_FSM_STATES_QTY, ///< Always keep this value at the bottom!
} ServoFSMState;


/// @brief LUT containing the PWM duty cycle values for each FSM state.
static const float SERVO_DUTY_CYCLES[SERVO_FSM_STATES_QTY] =
{
    [SERVO_IDLE] = 6.5f,
    [SERVO_POSITION_0] = 2.5f,
    [SERVO_POSITION_180] = 11.0f,
};

static delay_t servo_delay = {};
static ServoFSMState current_state = SERVO_IDLE;
static bool_t button_pressed = false;

void svc_servo_init()
{
    pwm_init();
    pwm_set_dc(SERVO_DUTY_CYCLES[SERVO_IDLE]);
    delay_init(&servo_delay, SERVO_FSM_DELAY_TIMEOUT_MS);
    current_state = SERVO_IDLE;
}

void svc_servo_fsm_update()
{
    switch(current_state)
    {
    case SERVO_IDLE:
        if(button_pressed) {
            current_state = SERVO_POSITION_0;
            button_pressed = false;
        }
        break;
    case SERVO_POSITION_0:
        if(button_pressed) {
            current_state = SERVO_IDLE;
            button_pressed = false;
        }
        if(delay_read(&servo_delay)) {
            current_state = SERVO_POSITION_180;
        }
        break;
    case SERVO_POSITION_180:
        if(button_pressed) {
            current_state = SERVO_IDLE;
            button_pressed = false;
        }
        if(delay_read(&servo_delay)) {
            current_state = SERVO_POSITION_0;
        }
        break;
    default:
        assert(false && "Invalid state");
        break;
    }

    /// After determining the state, set the PWM's DC accordingly.
    pwm_set_dc(SERVO_DUTY_CYCLES[current_state]);
}

void svc_servo_change_state() { button_pressed = true; }
