/*
 * API_delay.c
 *
 *  Created on: Jul 6, 2023
 *      Author: lsoria
 */

#include <assert.h>

#include "stm32f4xx_hal.h"

#include "API_delay.h"

void delay_init(delay_t* const delay, const tick_t duration)
{
	assert(delay);

	delay->start_time = (tick_t)HAL_GetTick();
	delay->duration = duration;
	delay->running = false;
}

bool_t delay_read(delay_t* const delay)
{
	assert(delay);

	const tick_t CURRENT_TIME = (tick_t)HAL_GetTick();
	bool_t ret = false;

	if(!delay->running) {
		delay->start_time = CURRENT_TIME;
		delay->running = true;
	} else {
		ret = (CURRENT_TIME - delay->start_time) >= delay->duration;
		delay->running = !ret; // stop running flag if we reached the duration.
	}

	return ret;
}

void delay_write(delay_t* const delay, const tick_t duration)
{
	assert(delay);

	delay->duration = duration;
}


