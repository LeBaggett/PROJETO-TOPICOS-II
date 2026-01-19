/*
 * buttons.h
 *
 *  Created on: Jan 8, 2026
 *      Author: Ivo Samuel
 */

#ifndef CORE_DRIVERS_BUTTONS_H_
#define CORE_DRIVERS_BUTTONS_H_

#include "main.h"

// Grupo Esquerdo (Controle/Navegação)
#define BT_UP_Pin     GPIO_PIN_9
#define BT_UP_Port    GPIOA
#define BT_DOWN_Pin   GPIO_PIN_10
#define BT_DOWN_Port  GPIOA
#define BT_LEFT_Pin   GPIO_PIN_11
#define BT_LEFT_Port  GPIOA
#define BT_RIGHT_Pin  GPIO_PIN_12
#define BT_RIGHT_Port GPIOA
#define BT_CENTER_Pin GPIO_PIN_15
#define BT_CENTER_Port GPIOA

// Grupo Direito (Ação)
#define BT_A1_Pin     GPIO_PIN_3
#define BT_A1_Port    GPIOB
#define BT_A2_Pin     GPIO_PIN_4
#define BT_A2_Port    GPIOB
#define BT_A3_Pin     GPIO_PIN_5
#define BT_A3_Port    GPIOB
#define BT_A4_Pin     GPIO_PIN_6
#define BT_A4_Port    GPIOB

// Função para ler o estado do botão
uint8_t BTN_IsPressed(GPIO_TypeDef* Port, uint16_t Pin);

#endif
