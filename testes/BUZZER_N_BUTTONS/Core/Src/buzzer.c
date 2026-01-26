/*
 * buzzer.c
 *
 *  Created on: Jan 24, 2026
 *      Author: Kaue Lucas
 */

#include "buzzer.h"

extern TIM_HandleTypeDef htim1;  // TIM configurado

void Buzzer_Start(void)
{
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
//    TIM1->CCR1=250;
}

void Buzzer_Stop(void)
{
//	TIM1->CCR1=0;
    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
}

