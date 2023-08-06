#include <assert.h>

#include "tim.h"

#include "API_pwm.h"

static TIM_HandleTypeDef timer_handle;

void pwm_init()
{
    MX_TIM2_Init(&timer_handle);
    HAL_TIM_Base_Start(&timer_handle);
    HAL_TIM_PWM_Start(&timer_handle, TIM_CHANNEL_1);
}

void pwm_set_dc(const float duty_cycle)
{
    assert(duty_cycle >= 0.0f && duty_cycle <= 100.0f);
    uint32_t ccr1_value = (uint32_t)(duty_cycle * 100);
    timer_handle.Instance->CCR1 = ccr1_value;
}
