/*
 * API_delay.h
 *
 *  Created on: Jul 6, 2023
 *      Author: lsoria
 */

#ifndef API_INC_API_DELAY_H_
#define API_INC_API_DELAY_H_

#include <stdbool.h>
#include <stdint.h>

typedef uint32_t tick_t;
typedef bool bool_t;

typedef struct {
	tick_t start_time;
	tick_t duration;
	bool_t running;
} delay_t;


void delay_init(delay_t* const delay, const tick_t duration);
bool_t delay_read(delay_t* const delay);
void delay_write(delay_t* const delay, const tick_t duration);

#endif /* API_INC_API_DELAY_H_ */
