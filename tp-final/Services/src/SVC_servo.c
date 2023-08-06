#include "API_delay.h"
#include "API_pwm.h"
#include "SVC_servo.h"

#define SERVO_IDLE_DC 6.5f
#define SERVO_0_DEGREES_DC 2.5f
#define SERVO_180_DEGREES_DC 11.0f

#define SERVO_FSM_DELAY_TIMEOUT_MS 2000

typedef enum
{
    SERVO_IDLE = 0,
    SERVO_POSITION_0,
    SERVO_POSITION_180,
} ServoFSMState;


static delay_t servo_delay = {};
static ServoFSMState current_state = SERVO_IDLE;
static bool_t button_pressed = false;


void svc_servo_change_state()
{
    button_pressed = true;
}

void svc_servo_init()
{
    pwm_init();
    current_state = SERVO_IDLE;
    pwm_set_dc(SERVO_IDLE_DC);
    delay_init(&servo_delay, SERVO_FSM_DELAY_TIMEOUT_MS);
}

void svc_servo_fsm_update()
{
    switch(current_state)
    {
    case SERVO_IDLE:
        pwm_set_dc(SERVO_IDLE_DC);
        if(button_pressed) {
            current_state = SERVO_POSITION_0;
            button_pressed = false;
        }
        break;
    case SERVO_POSITION_0:
        pwm_set_dc(SERVO_0_DEGREES_DC);
        if(button_pressed) {
            current_state = SERVO_IDLE;
            button_pressed = false;
        }
        if(delay_read(&servo_delay)) {
            current_state = SERVO_POSITION_180;
        }
        break;
    case SERVO_POSITION_180:
        pwm_set_dc(SERVO_180_DEGREES_DC);
        if(button_pressed) {
            current_state = SERVO_IDLE;
            button_pressed = false;
        }
        if(delay_read(&servo_delay)) {
            current_state = SERVO_POSITION_0;
        }
        break;

    }
}
