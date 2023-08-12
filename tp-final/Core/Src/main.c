/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
#include <main.h>
#include "usb_device.h"
#include "gpio.h"

#include "API_debounce.h"
#include "API_delay.h"
#include "API_leds.h"

#include "SVC_imu.h"
#include "SVC_servo.h"

#define HEARTBEAT_LED LED1
#define HEARTBEAT_PERIOD_MS 1000
#define SERVO_LED LED2

void SystemClock_Config(void);

/// @brief Callback pressed when the button is pressed.
static void servo_button_pressed()
{
    led_toggle(SERVO_LED);
    svc_servo_change_state();
}

/// @brief Callback pressed when the button is pressed.
static void streaming_button_pressed()
{
    led_toggle(LED3);
    svc_imu_button_pressed();
}

/// @brief handlers called whenever the servo button is pressed/released
static button_handlers_t servo_button_fsm_handlers =
{
    .pressed_cb = &servo_button_pressed,
    .released_cb = NULL,
};

/// @brief handlers called whenever the imu streaming button is pressed/released
static button_handlers_t streaming_button_fsm_handlers =
{
    .pressed_cb = &streaming_button_pressed,
    .released_cb = NULL,
};

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
    delay_t heatbeat_delay = {};

    delay_init(&heatbeat_delay, HEARTBEAT_PERIOD_MS);

    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USB_DEVICE_Init();

    debounce_fsm_init(SERVO_BUTTON, &servo_button_fsm_handlers);
    debounce_fsm_init(USER_BUTTON, &streaming_button_fsm_handlers);

    svc_servo_init();
    svc_imu_init();

    while (1)
    {
        debounce_fsm_update();
        svc_servo_fsm_update();
        svc_imu_fsm_update();
        if(delay_read(&heatbeat_delay)) { led_toggle(HEARTBEAT_LED); }
    }
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 384;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 8;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
