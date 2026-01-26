/*
 * buttons.c
 *
 *  Created on: Jan 24, 2026
 *      Author: Kaue Lucas
 */

#include "buttons.h"

// ================= CONFIGURAÇÃO DOS BOTÕES =================


static Button_t buttons[BUTTON_COUNT] = {
    {GPIOA, GPIO_PIN_9, GPIO_PIN_RESET, GPIO_PIN_RESET},
    {GPIOA, GPIO_PIN_10, GPIO_PIN_RESET, GPIO_PIN_RESET},
    {GPIOA, GPIO_PIN_11, GPIO_PIN_RESET, GPIO_PIN_RESET},
    {GPIOA, GPIO_PIN_12, GPIO_PIN_RESET, GPIO_PIN_RESET},
    {GPIOA, GPIO_PIN_15, GPIO_PIN_RESET, GPIO_PIN_RESET},
    {GPIOB, GPIO_PIN_3, GPIO_PIN_RESET, GPIO_PIN_RESET},
    {GPIOB, GPIO_PIN_4, GPIO_PIN_RESET, GPIO_PIN_RESET},
    {GPIOB, GPIO_PIN_5, GPIO_PIN_RESET, GPIO_PIN_RESET},
    {GPIOB, GPIO_PIN_6, GPIO_PIN_RESET, GPIO_PIN_RESET}
};

// ================= IMPLEMENTAÇÃO ===========================

void Buttons_Init(void)
{
    for (uint8_t i = 0; i < BUTTON_COUNT; i++)
    {
        buttons[i].state = HAL_GPIO_ReadPin(buttons[i].port, buttons[i].pin);
        buttons[i].last_state = buttons[i].state;
    }
}

void Buttons_Update(void)
{
    for (uint8_t i = 0; i < BUTTON_COUNT; i++)
    {
        buttons[i].last_state = buttons[i].state;
        buttons[i].state = HAL_GPIO_ReadPin(buttons[i].port, buttons[i].pin);
    }
}

uint8_t Button_Pressed(uint8_t id)
{
    if (id >= BUTTON_COUNT) return 0;

    return (buttons[id].state == GPIO_PIN_SET &&
            buttons[id].last_state == GPIO_PIN_RESET);
}

uint8_t Button_Released(uint8_t id)
{
    if (id >= BUTTON_COUNT) return 0;

    return (buttons[id].state == GPIO_PIN_RESET &&
            buttons[id].last_state == GPIO_PIN_SET);
}

GPIO_PinState Button_GetState(uint8_t id)
{
    if (id >= BUTTON_COUNT) return GPIO_PIN_RESET;
    return buttons[id].state;
}

GPIO_PinState Button_GetLastState(uint8_t id)
{
    if (id >= BUTTON_COUNT) return GPIO_PIN_RESET;
    return buttons[id].last_state;
}


