#include <assert.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

#include "API_leds.h"

/// @brief Struct that represents a HAL LED
typedef struct
{
    GPIO_TypeDef* port;
    uint16_t pin;
} LEDStruct;

/// @brief LUT that contains the Port/Pin information for each output.
static const LEDStruct AVAILABLE_LEDS[LEDS_TOTAL] =
{
    [LED1] = {GPIOB, GPIO_PIN_0},
    [LED2] = {GPIOB, GPIO_PIN_7},
    [LED3] = {GPIOB, GPIO_PIN_14},
};

void led_toggle(const BoardLEDs led)
{
    assert(led < LEDS_TOTAL);
    HAL_GPIO_TogglePin(AVAILABLE_LEDS[led].port, AVAILABLE_LEDS[led].pin);
}

void led_write(const BoardLEDs led, const LEDStatus status)
{
    assert(led < LEDS_TOTAL);
    assert(status == LED_ON || status == LED_OFF);

    const GPIO_PinState STATE = (status == LED_ON) ? GPIO_PIN_SET : GPIO_PIN_RESET;
    HAL_GPIO_WritePin(AVAILABLE_LEDS[led].port, AVAILABLE_LEDS[led].pin, STATE);
}

void led_set(const BoardLEDs led) { led_write(led, LED_ON); }

void led_clear(const BoardLEDs led) { led_write(led, LED_OFF); }
