/*
 * buttons.c
 *
 *  Created on: Jan 23, 2026
 *      Author: Kaue Lucas
 */


#include "buttons.h"
#include "stm32f1xx_hal.h"

void Buttons_init(void)
{
    // Nada aqui por enquanto.

}


static Button_t Buttons_ReadRaw(void)
{
    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9) == GPIO_PIN_SET)
        return BTN_UP;

    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15) == GPIO_PIN_SET)
        return BTN_DOWN;

    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3) == GPIO_PIN_SET)
        return BTN_ENTER;

    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) == GPIO_PIN_SET)
        return BTN_BACK;

    return BTN_NONE;
}

Button_t Buttons_ReadDebounced(void)
{
    static uint32_t last_time = 0;
    static Button_t last_stable = BTN_NONE;

    Button_t current = Buttons_ReadRaw();

    if (current != last_stable)
    {
        if (HAL_GetTick() - last_time >= 30)
        {
            last_time = HAL_GetTick();
            last_stable = current;

            if (current != BTN_NONE)
                return current;
        }
    }
    else
    {
        last_time = HAL_GetTick();
    }

    return BTN_NONE;
}

