/*
 * buzzer.c
 *
 *  Created on: Jan 24, 2026
 *      Author: Kaue Lucas
 */

#include "buzzer.h"

extern TIM_HandleTypeDef htim1;

static uint32_t buzzer_off_time = 0;
static uint8_t buzzer_active = 0;

void Buzzer_Init(void)
{
    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
    buzzer_active = 0;
}

void Buzzer_Beep(uint16_t duration_ms)
{
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);

    buzzer_off_time = HAL_GetTick() + duration_ms;
    buzzer_active = 1;
}

void Buzzer_Update(void)
{
    if (buzzer_active && HAL_GetTick() >= buzzer_off_time)
    {
        HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
        buzzer_active = 0;
    }
}

