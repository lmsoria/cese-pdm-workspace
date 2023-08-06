#include <assert.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

#include "API_button.h"
#include "API_debounce.h"
#include "API_delay.h"

#define DEBOUNCE_PERIOD_MS 40

/// @brief Enum that represent a button possible state
typedef enum
{
    BUTTON_UP = 0,  ///< Button released (default state)
    BUTTON_FALLING, ///< Button going from released to pressed
    BUTTON_DOWN,    ///< Button pressed
    BUTTON_RAISING, ///< Button going from pressed to released
} DebounceState;

static delay_t debounce_delay[BUTTONS_TOTAL] = {};
static DebounceState current_state[BUTTONS_TOTAL] = { BUTTON_UP };
static button_handlers_t* fsm_handlers[BUTTONS_TOTAL] = { NULL } ;

void debounce_fsm_init(const BoardButtons button, button_handlers_t* const handlers)
{
    assert(button > 0 && button < BUTTONS_TOTAL);
    assert(handlers);

    fsm_handlers[button] = handlers;
    current_state[button] = BUTTON_UP;
    delay_init(&debounce_delay[button], DEBOUNCE_PERIOD_MS);
}

void debounce_fsm_update()
{
    for(uint8_t button = 0; button < BUTTONS_TOTAL; button++) {
        const ButtonStatus BUTTON_STATUS = button_read(button);
        DebounceState* const STATE = &current_state[button];

        switch(*STATE)
        {
        case BUTTON_UP:
            if(BUTTON_STATUS == BUTTON_PRESSED) {
                *STATE = BUTTON_FALLING;
            }
            break;
        case BUTTON_FALLING:
            if(delay_read(&debounce_delay[button])) {
                if(BUTTON_STATUS == BUTTON_PRESSED) {
                    if(fsm_handlers[button]->pressed_cb) { fsm_handlers[button]->pressed_cb(); }
                    *STATE = BUTTON_DOWN;
                } else {
                    *STATE = BUTTON_UP;
                }
            }
            break;
        case BUTTON_DOWN:
            if(BUTTON_STATUS == BUTTON_RELEASED) {
                *STATE = BUTTON_RAISING;
            }
            break;
        case BUTTON_RAISING:
            if(delay_read(&debounce_delay[button])) {
                if(BUTTON_STATUS == BUTTON_RELEASED) {
                    if(fsm_handlers[button]->released_cb) { fsm_handlers[button]->released_cb(); }
                    *STATE = BUTTON_UP;
                } else {
                    *STATE = BUTTON_DOWN;
                }
            }
            break;
        default:
            assert(false && "Invalid state");
            break;
        }
    }

}
