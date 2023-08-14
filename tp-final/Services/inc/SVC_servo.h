#pragma once

/// @brief Initialize the Servo service, which is in charge of
///     * Initializing the PWM peripheral.
///     * Initializing the FSM
/// After calling this method, `svc_servo_fsm_update()` must be called periodically.
void svc_servo_init();

/// @brief Callback used for switching the Servo service' state machine.
void svc_servo_change_state();

/// @brief Update the Servo service state machine. This function must be called periodically.
void svc_servo_fsm_update();
