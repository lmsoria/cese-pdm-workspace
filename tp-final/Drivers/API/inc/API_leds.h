#pragma once

#include "API_types.h"

/// @brief Enum that keeps track of the available LEDs
typedef enum
{
    LED1 = 0,  ///< Green LED
    LED2,      ///< Blue LED
    LED3,      ///< Red LED
    LEDS_TOTAL /// Total amount of LEDs. Keep this value always at the bottom!
} BoardLEDs;

/// @brief Toggle the status of the specified led
/// @param led Must be one of the defined in BoardLEDs.
void led_toggle(const BoardLEDs led);

/// @brief Set the specified LED with the desired status
/// @param led Must be one of the defined in BoardLEDs.
/// @param status Can be LED_ON or LED_OFF
void led_write(const BoardLEDs led, const LEDStatus status);

/// @brief Turn on the specified LED. It's equivalent to call `led_set(led, LED_ON)`
/// @param led Must be one of the defined in BoardLEDs.
void led_set(const BoardLEDs led);

/// @brief Turn off the specified LED. It's equivalent to call `led_set(led, LED_OFF)`
/// @param led Must be one of the defined in BoardLEDs.
void led_clear(const BoardLEDs led);
