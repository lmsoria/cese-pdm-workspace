#include "tim.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_tim.h"

#include "API_pwm.h"

static TIM_HandleTypeDef timer_handle;

void pwm_init()
{
    MX_TIM2_Init(&timer_handle);
    HAL_TIM_Base_Start(&timer_handle);
    HAL_TIM_PWM_Start(&timer_handle, TIM_CHANNEL_1);
}

// TODO: actually, we are not passing the duty cycle. Adapt this code to be a float number between [0.0f - 100.0f] and determine the actual CCR1 value
void pwm_set_dc(const uint16_t duty_cycle)
{
    timer_handle.Instance->CCR1 = duty_cycle;
}
