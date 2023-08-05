#include <assert.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

#include "API_button.h"

/// @brief Struct that represents a button
typedef struct
{
    GPIO_TypeDef* port;
    uint16_t pin;
} ButtonStruct;

static const ButtonStruct AVAILABLE_BUTTONS[BUTTONS_TOTAL] =
{
    [USER_BUTTON] = {GPIOC, GPIO_PIN_13},
};

ButtonStatus button_read(const BoardButtons button)
{
    assert(button < BUTTONS_TOTAL);
    const GPIO_PinState BUTTON_STATE = HAL_GPIO_ReadPin(AVAILABLE_BUTTONS[button].port, AVAILABLE_BUTTONS[button].pin);

    return (BUTTON_STATE == GPIO_PIN_SET) ? BUTTON_PRESSED : BUTTON_RELEASED;
}
