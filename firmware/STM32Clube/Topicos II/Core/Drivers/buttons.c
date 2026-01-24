/*
 * buttons.c
 *
 *  Created on: Jan 8, 2026
 *      Author: Ivo Samuel
 */

#include "buttons.h"

/**
 * @brief Verifica se um botão foi pressionado com tratamento de debounce.
 * @return 1 se pressionado, 0 se não.
 */
uint8_t BTN_IsPressed(GPIO_TypeDef* Port, uint16_t Pin) {
    // Como os botões estão em Pull-up, o estado pressionado é Nível Baixo (RESET)
    if (HAL_GPIO_ReadPin(Port, Pin) == GPIO_PIN_RESET) {
        HAL_Delay(20); // Aguarda 20ms para estabilizar o sinal (debounce)

        if (HAL_GPIO_ReadPin(Port, Pin) == GPIO_PIN_RESET) {
            // Loop opcional: espera o usuário soltar o botão para não repetir a ação
            // Remova o 'while' abaixo se quiser que o botão responda continuamente (ex: segurar para andar)
            while(HAL_GPIO_ReadPin(Port, Pin) == GPIO_PIN_RESET);

            return 1; // Confirmado
        }
    }
    return 0;
}
