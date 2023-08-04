#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"

#include "API_uart.h"

static UART_HandleTypeDef uart_handler;

bool_t uart_init()
{
    uart_handler.Instance = USART3;
    uart_handler.Init.BaudRate = 115200;
    uart_handler.Init.WordLength = UART_WORDLENGTH_8B;
    uart_handler.Init.StopBits = UART_STOPBITS_1;
    uart_handler.Init.Parity = UART_PARITY_NONE;
    uart_handler.Init.Mode = UART_MODE_TX_RX;
    uart_handler.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    uart_handler.Init.OverSampling = UART_OVERSAMPLING_16;

    return (HAL_UART_Init(&uart_handler) == HAL_OK);
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
