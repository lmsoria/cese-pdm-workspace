#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef uint32_t tick_t;
typedef bool bool_t;

/// @brief Posible LED status
typedef enum
{
    LED_OFF = 0,
    LED_ON = 1,
} LEDStatus;

/// @brief Possible Button status
typedef enum
{
    BUTTON_RELEASED = 0,
    BUTTON_PRESSED = 1,
} ButtonStatus;
