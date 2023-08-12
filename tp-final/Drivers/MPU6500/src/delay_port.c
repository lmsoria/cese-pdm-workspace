#include "stm32f4xx_hal.h"

#include "delay_port.h"

 // Since this will run on an initialization stage (and for the sake of simplicity),
 // We'll use a simple, blocking delay.
void delay_port_wait(const uint32_t msec) { HAL_Delay(msec); }
