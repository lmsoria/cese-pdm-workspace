#pragma once

#include "API_types.h"

/// @brief Enum that keeps track of the available LEDs
typedef enum
{
    USER_BUTTON = 0, ///< User Button (the blue one)
    SERVO_BUTTON = 1, ///< Button added to the protoboard. Will control the servo mechanism.
    BUTTONS_TOTAL,   ///< Total amount of buttons. Keep this value always at the bottom!
} BoardButtons;

/// @brief Read the status of the specified button
/// @param button Must be one of the defined in BoardButtons
/// @return BUTTON_PRESSED if the button is pressed, and BUTTON_RELEASED otherwise.
ButtonStatus button_read(const BoardButtons button);
