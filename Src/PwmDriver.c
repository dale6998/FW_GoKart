#include "tim.h"
#include "tim.h"
#include "gpio.h"

#define PWM_CHANNEL (1)

void PWMDriver_init(TIM_HandleTypeDef *htim)
{
  HAL_TIM_PWM_Init(htim);
}

void PWMDriver_Enable(TIM_HandleTypeDef *htim)
{
HAL_TIM_PWM_Start_IT(htim, PWM_CHANNEL);
}

void PWMDriver_Disable(TIM_HandleTypeDef *htim)
{
HAL_TIM_PWM_Stop_IT(htim, PWM_CHANNEL);
}

void PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
  HAL_GPIO_WritePin(LD3_GPIO_Port,LD3_Pin,GPIO_PIN_RESET);
}

void PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  HAL_GPIO_WritePin(LD3_GPIO_Port,LD3_Pin,GPIO_PIN_RESET);
}


void PWMDriver_ChangeFrequency(TIM_HandleTypeDef *htim, uint16_t arr)
{
__HAL_TIM_SET_AUTORELOAD(htim, arr);
}

void PWMDriver_ChangeDutyCycle(TIM_HandleTypeDef *htim, uint16_t duty)
{
  uint16_t ccr = duty; //TODO make this use some math and getters to convert a freq to a ccr value
__HAL_TIM_SET_COMPARE(htim, PWM_CHANNEL, ccr);
}
