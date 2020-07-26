#include "tim.h"
#include "main.h"
#include "stm32l4xx_hal_gpio.h"
#include "stm32l4xx_hal_tim.h"
#include "tim.h"
#include "gpio.h"
#include "stdio.h"
#include "retarget.h"
#include "PwmDriver.h"
#include "ButtonManager.h"
#include "stdbool.h"

#define PWM_CHANNEL (TIM_CHANNEL_1)
#define RAMP_RATE 1

static void PWMDriver_ChangeFrequency(TIM_HandleTypeDef *htim, uint32_t arr);
static void PWMDriver_updateSpeed(void);
static int32_t rampStatePWM = 0;

void PWMDriver_init(TIM_HandleTypeDef *htim)
{
  //HAL_TIM_PWM_Init(htim);
}

void PWMDriver_Enable(void)
{
  HAL_TIM_Base_Start_IT(&htim2);
  HAL_TIM_PWM_Start_IT(&htim2, PWM_CHANNEL);
  HAL_TIM_Base_Start_IT(&htim6);

  //PWMDriver_ChangeFrequency(&htim2, 1000);
  //PWMDriver_ChangeDutyCycle(&htim2, 1000);

  //PWMDriver_ChangeFrequency(&htim6, 10);
}

void PWMDriver_Disable(TIM_HandleTypeDef *htim)
{
  HAL_TIM_PWM_Stop_IT(htim, PWM_CHANNEL);
  HAL_TIM_PWM_Stop_IT(&htim2, PWM_CHANNEL);
  HAL_TIM_Base_Stop_IT(&htim6);
}

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
    HAL_GPIO_WritePin(LD3_GPIO_Port,LD3_Pin,GPIO_PIN_RESET);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  ///////////////////////////////////////////
  //    This is for the PWM Generation Timer
  ///////////////////////////////////////////
  if (htim == &htim2){
    HAL_GPIO_WritePin(LD3_GPIO_Port,LD3_Pin,GPIO_PIN_SET);
  }
  ///////////////////////////////////////////
  //    This is for the Speed Control Timer
  //    Every time this hits, it updates the speed depending
  //    on the state of the button
  ///////////////////////////////////////////
  else if (htim == &htim6) {
    PWMDriver_updateSpeed();
  }
}


static void PWMDriver_updateSpeed(void)
{
  rampStatePWM += RAMP_RATE;
  if (rampStatePWM > 1000 && IsButtonPushed()){
      rampStatePWM = 1000;
  }
  else if (rampStatePWM < 0 && !IsButtonPushed()){
      rampStatePWM = 0;
  }

  PWMDriver_ChangeDutyCycle(&htim2,rampStatePWM);
}


static void PWMDriver_ChangeFrequency(TIM_HandleTypeDef *htim, uint32_t arr)
{
  __HAL_TIM_SET_AUTORELOAD(htim, arr);
}

void PWMDriver_ChangeDutyCycle(TIM_HandleTypeDef *htim, uint32_t duty)
{
  __HAL_TIM_SET_COMPARE(htim, PWM_CHANNEL, duty);
}
