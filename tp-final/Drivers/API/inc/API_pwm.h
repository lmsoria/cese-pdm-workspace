#pragma once

#include "API_types.h"

/// @brief Initialize the PWM peripheral. The implementation will be hardware dependant.
/// (here we are relying on a Timer peripheral provided by ST). It should initialize a 50 Hz PWM signal.
void pwm_init();

/// @brief Set the duty cycle of the peripheral, in percentage. A bound check is performed. 
/// @param duty_cycle percentage, between 0.0% and 100.0%
void pwm_set_dc(const float duty_cycle);
