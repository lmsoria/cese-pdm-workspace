#pragma once

#include "API_types.h"

/// @brief Initialize a UART peripheral, with the following parameters:
///     * 115200 bauds
///     * 8 data bits
///     * 1 stop bit
///     * No parity
/// @return true if initialization was successful, or false otherwise.
bool_t uart_init();

/// @brief Send a string until the first '\0' character is found.
/// @param p_string pointer to the string.
void uart_send_string(uint8_t* const p_string);

/// @brief Send `size` bytes of a givent string
/// @param p_string pointer to the string.
/// @param size bytes to be sent.
void uart_send_string_size(uint8_t* const p_string, const uint16_t size);

/// @brief Receive `size` bytes from the UART RX's buffer and store them.
/// @param p_string Address where RX'd data should be stored
/// @param size Number of bytes to be read.
void uart_receive_string_size(uint8_t* const p_string, const uint16_t size);
