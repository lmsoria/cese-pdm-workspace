#pragma once

#include "API_types.h"

bool_t uart_init();

void uart_send_string(uint8_t* p_string);
void uart_send_string_size(uint8_t* p_string, uint16_t size);
void uart_receive_string_size(uint8_t* p_string, uint16_t size);
