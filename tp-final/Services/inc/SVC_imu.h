#pragma once

/// @brief Initialize the IMU service, which is in charge of
///     * Initializing the IMU driver (configuration options are defined at compile-time for the moment)
///     * Initializing the UART
///     * Initializing the FSM
/// After calling this method, `svc_imu_fsm_update()` must be called periodically.
void svc_imu_init();

/// @brief Callback used for switching the IMU service' state machine.
void svc_imu_button_pressed();

/// @brief Update the IMU service state machine. This function must be called periodically.
void svc_imu_fsm_update();
