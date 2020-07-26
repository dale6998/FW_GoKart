#include "tim.h"
#include "stm32l4xx_hal_tim.h"
#include "tim.h"
#include "gpio.h"
#include "stdio.h"
#include "retarget.h"

#define PWM_CHANNEL (TIM_CHANNEL_1)
#define RAMP_RATE 10

static void PWMDriver_ChangeFrequency(TIM_HandleTypeDef *htim, uint32_t arr);
static uint32_t rampStatePWM;

void PWMDriver_init(TIM_HandleTypeDef *htim)
{
  //HAL_TIM_PWM_Init(htim);
}

void PWMDriver_Enable(TIM_HandleTypeDef *htim)
{
  HAL_TIM_Base_Start_IT(htim);
  HAL_TIM_PWM_Start_IT(htim, PWM_CHANNEL);
}

void PWMDriver_Disable(TIM_HandleTypeDef *htim)
{
  HAL_TIM_PWM_Stop_IT(htim, PWM_CHANNEL);
}

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
//  printf("HAL_TIM_PWM_PulseFinishedCallback\r\n");
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

void PWMDriver_updateSpeed(void)
{
  rampStatePWM += RAMP_RATE;
  PWMDriver_ChangeFrequency(&htim2,rampStatePWM);
}
static void PWMDriver_ChangeFrequency(TIM_HandleTypeDef *htim, uint32_t arr)
{
  htim->Instance->ARR = arr;
}

void PWMDriver_ChangeDutyCycle(TIM_HandleTypeDef *htim, uint32_t duty)
{
  __HAL_TIM_SET_COMPARE(htim, PWM_CHANNEL, duty);
}
