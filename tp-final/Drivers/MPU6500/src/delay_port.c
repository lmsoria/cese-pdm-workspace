#include "stm32f4xx_hal.h"

#include "delay_port.h"

void delay_port_wait(const uint32_t msec) { HAL_Delay(msec); }
