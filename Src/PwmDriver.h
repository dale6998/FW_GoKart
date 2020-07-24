#pragma once
#include "tim.h"

void  PWMDriver_init(TIM_HandleTypeDef *htim);
void  PWMDriver_ChangeDutyCycle(TIM_HandleTypeDef * htim,uint16_t duty);
void  PWMDriver_ChangeFrequency(TIM_HandleTypeDef * htim,uint16_t arr);
void  PWMDriver_Disable(TIM_HandleTypeDef * htim);
void  PWMDriver_Enable(TIM_HandleTypeDef * htim);
void  PWMDriver_init(TIM_HandleTypeDef * htim);
void  PWM_PulseFinishedCallback(TIM_HandleTypeDef * htim);
void  PWM_PulseFinishedCallback(TIM_HandleTypeDef * htim);
