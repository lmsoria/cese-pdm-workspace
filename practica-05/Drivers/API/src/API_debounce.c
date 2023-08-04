#include <assert.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

#include "API_debounce.h"
#include "API_delay.h"

#define DEBOUNCE_PERIOD_MS 40

/// Enum that represent a button possible state
typedef enum
{
    BUTTON_UP = 0,  ///< Button released (default state)
    BUTTON_FALLING, ///< Button going from released to pressed
    BUTTON_DOWN,    ///< Button pressed
    BUTTON_RAISING, ///< Button going from pressed to released
} DebounceState;

/// Struct that represents a button
/// TODO handle me in a separate file!
typedef struct
{
    GPIO_TypeDef* port;
    uint16_t pin;
} ButtonStruct;

static const ButtonStruct USER_BUTTON = {.port = GPIOC, .pin = GPIO_PIN_13 };

static delay_t debounce_delay = {};
static DebounceState current_state = BUTTON_UP;
static bool_t key_falling = false;
static button_handlers_t* fsm_handlers;

void debounce_fsm_init(button_handlers_t* const handlers)
{
    assert(handlers->pressed_cb && handlers->released_cb);
    fsm_handlers = handlers;
    current_state = BUTTON_UP;
    delay_init(&debounce_delay, DEBOUNCE_PERIOD_MS);
}

void debounce_fsm_update()
{
    const GPIO_PinState BUTTON_STATE = HAL_GPIO_ReadPin(USER_BUTTON.port, USER_BUTTON.pin);

    switch(current_state)
    {
    case BUTTON_UP:
        if(BUTTON_STATE == GPIO_PIN_SET) {
            current_state = BUTTON_FALLING;
        }
        break;
    case BUTTON_FALLING:
        key_falling = true;
        if(delay_read(&debounce_delay)) {
            if(BUTTON_STATE == GPIO_PIN_SET) {
                fsm_handlers->pressed_cb();
                current_state = BUTTON_DOWN;
            } else {
                current_state = BUTTON_UP;
            }
        }
        break;
    case BUTTON_DOWN:
        if(BUTTON_STATE == GPIO_PIN_RESET) {
            current_state = BUTTON_RAISING;
        }
        break;
    case BUTTON_RAISING:
        if(delay_read(&debounce_delay)) {
            if(BUTTON_STATE == GPIO_PIN_RESET) {
                fsm_handlers->released_cb();
                current_state = BUTTON_UP;
            } else {
                current_state = BUTTON_DOWN;
            }
        }
        break;
    default:
        assert(false && "Invalid state");
        break;
    }
}

const bool_t read_key()
{
    const bool_t RET = key_falling;

    if(RET) {
        key_falling = false;
    }

    return RET;
}
