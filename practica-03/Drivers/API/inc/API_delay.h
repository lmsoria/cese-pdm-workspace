#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef uint32_t tick_t;
typedef bool bool_t;

/// @brief struct representing a non-blocking delay.
typedef struct {
    tick_t start_time; ///< used to keep tracking of when the delay started
    tick_t duration; ///< duration of the delay, in ms.
    bool_t running; ///< flag to determine whether the delay is still nunning.
} delay_t;

/// @brief Initializes a delay with the specified duration. This function DO NOT initializes the delay,
/// in order to do that you'll need to call delay_read() after initializing the struct.
/// @param delay struct to be initialized
/// @param duration in ms
void delay_init(delay_t* const delay, const tick_t duration);

/// @brief Queries whether the delay has reached its duration.
/// If the timer is not running, it will start running it first.
/// @param delay struct to be queried.
/// @return true if the duration has been reached. false, otherwise.
bool_t delay_read(delay_t* const delay);

/// @brief Change the duration of a delay
/// @param delay struct to be written
/// @param duration in ms
void delay_write(delay_t* const delay, const tick_t duration);
