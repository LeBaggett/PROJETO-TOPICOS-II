/*
 * buttons.h
 *
 *  Created on: Jan 24, 2026
 *      Author: Kaue Lucas
 */

#ifndef BUTTONS_H
#define BUTTONS_H

#include "stm32f1xx_hal.h"
#include <stdint.h>

typedef enum {
    BTN_0 = 0,
    BTN_1,
    BTN_2,
    BTN_3,
    BTN_4,
    BTN_5,
    BTN_6,
    BTN_7,
    BTN_8,
    BTN_COUNT
} ButtonId_t;


#define BUTTON_COUNT BTN_COUNT


typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin;
    GPIO_PinState state;
    GPIO_PinState last_state;
} Button_t;

// API
void Buttons_Init(void);
void Buttons_Update(void);

uint8_t Button_Pressed(uint8_t id);
uint8_t Button_Released(uint8_t id);

GPIO_PinState Button_GetState(uint8_t id);
GPIO_PinState Button_GetLastState(uint8_t id);



#endif
