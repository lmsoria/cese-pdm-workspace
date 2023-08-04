#pragma once

#include "API_debounce.h"
#include "API_types.h"


/// Enum that represent a button possible state
typedef enum
{
    BUTTON_UP = 0,  ///< Button released (default state)
    BUTTON_FALLING, ///< Button going from released to pressed
    BUTTON_DOWN,    ///< Button pressed
    BUTTON_RAISING, ///< Button going from pressed to released
} DebounceState;

typedef void (*button_callback_t)(const DebounceState state);

/// @brief Initialize the user button anti-debouncing FSM
void debounce_fsm_init(button_callback_t foo);

/// @brief Update the anti-debouncing FSM. This function must be called periodically.
void debounce_fsm_update();

/// @brief Check whether the user button is pressed or not.
/// @return button status.
bool_t read_key();
