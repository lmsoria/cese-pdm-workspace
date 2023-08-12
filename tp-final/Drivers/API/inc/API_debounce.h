#pragma once

#include "API_button.h"
#include "API_types.h"

/// @brief Callback function used for notifying that a button has been pressed/released
typedef void (*button_callback_t)(void);

/// @brief Struct containing the handlers for press/release events. They can be NULL if not needed.
typedef struct
{
    button_callback_t pressed_cb;
    button_callback_t released_cb;
} button_handlers_t;

/// @brief Initialize the user button anti-debouncing FSM
void debounce_fsm_init(const BoardButtons button, button_handlers_t* const handlers);

/// @brief Update the anti-debouncing FSM. This function must be called periodically.
void debounce_fsm_update();
