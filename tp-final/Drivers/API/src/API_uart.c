#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"

#include "API_uart.h"

#define INITIALIZATION_BUFFER_SIZE 256 // Size of the buffer used for transmitting the UART initialization message

static UART_HandleTypeDef uart_handler;

/// @brief Returns a printable string of the UART instance in use.
/// @param handler UART instance
/// @return 
static const char* uart_instance_name(UART_HandleTypeDef* handler)
{
    if(handler->Instance == USART1) { return "USART1"; }
    else if(handler->Instance == USART2) { return "USART2"; }
    else if(handler->Instance == USART3) { return "USART3"; }
    else if(handler->Instance == UART4) { return "UART4"; }
    else if(handler->Instance == UART5) { return "UART5"; }
    else { return "Unknown"; }
}

/// @brief Returns a printable string of the data bits used by the UART instance.
/// @param handler 
/// @return 
static const char* uart_data_bits_string(UART_HandleTypeDef* handler)
{
    if(handler->Init.WordLength == UART_WORDLENGTH_8B) { return "8 bits"; }
    else if(handler->Init.WordLength == UART_WORDLENGTH_9B) { return "9 bits"; }
    else { return "Unknown"; }
}

/// @brief Returns a printable string of the stop bits used by the UART instance.
/// @param handler UART instance
/// @return 
static const char* uart_stop_bits_string(UART_HandleTypeDef* handler)
{
    if(handler->Init.StopBits == UART_STOPBITS_1) { return "1 bit"; }
    else if(handler->Init.StopBits == UART_STOPBITS_2) { return "2 bits"; }
    else { return "Unknown"; }
}

/// @brief Returns a printable string of the parity used by the UART instance.
/// @param handler UART instance
/// @return 
static const char* uart_parity_string(UART_HandleTypeDef* handler)
{
    if(handler->Init.Parity == UART_PARITY_NONE) { return "None"; }
    else if(handler->Init.Parity == UART_PARITY_EVEN) { return "Even"; }
    else if(handler->Init.Parity == UART_PARITY_ODD) { return "Odd"; }
    else { return "Unknown"; }
}

bool_t uart_init()
{
    uint8_t buffer[INITIALIZATION_BUFFER_SIZE];

    bool_t ret = false;
    uart_handler.Instance = USART3;
    uart_handler.Init.BaudRate = 115200;
    uart_handler.Init.WordLength = UART_WORDLENGTH_8B;
    uart_handler.Init.StopBits = UART_STOPBITS_1;
    uart_handler.Init.Parity = UART_PARITY_NONE;
    uart_handler.Init.Mode = UART_MODE_TX_RX;
    uart_handler.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    uart_handler.Init.OverSampling = UART_OVERSAMPLING_16;

    ret = (HAL_UART_Init(&uart_handler) == HAL_OK);

//    if(ret) { // Only print the message if the initialization was OK
//        snprintf((char*)buffer, INITIALIZATION_BUFFER_SIZE,
//                "--------------------\r\n"
//                "%s initialized!\r\n"
//                "Parameters:\r\n"
//                "\t> Baudrate: %ld\r\n"
//                "\t> Data bits: %s\r\n"
//                "\t> Stop bits: %s\r\n"
//                "\t> Parity: %s\r\n"
//                "--------------------\r\n",
//                uart_instance_name(&uart_handler),
//                uart_handler.Init.BaudRate,
//                uart_data_bits_string(&uart_handler),
//                uart_stop_bits_string(&uart_handler),
//                uart_parity_string(&uart_handler));
//
//        uart_send_string(buffer);
//    }

    return ret;
}

void uart_send_string(uint8_t* p_string)
{
    uint16_t size = 0;
    uint8_t* p_aux = p_string;

    while(*p_aux++) {
        size++;
    }

    HAL_UART_Transmit(&uart_handler, p_string, size, HAL_MAX_DELAY);
}

void uart_send_string_size(uint8_t* p_string, uint16_t size)
{
    HAL_UART_Transmit(&uart_handler, p_string, size, HAL_MAX_DELAY);
}

void uart_receive_string_size(uint8_t* p_string, uint16_t size)
{
    HAL_UART_Receive(&uart_handler, p_string, size, HAL_MAX_DELAY);
}
