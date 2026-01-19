/*
 * system.c
 *
 *  Created on: Jan 8, 2026
 *      Author: Ivo Samuel
 */
#include "system.h"
#include "lcd.h"
#include "buttons.h"

// Variável global que armazena o estado atual do console
SystemState_t systemState = STATE_SPLASH;
uint8_t menuOption = 0; // 0 = JOGAR, 1 = CONFIG

void System_Init(void) {
    LCD_Init();
    LCD_Clear();

    // Tela Inicial (Splash Screen)
    LCD_SetCursor(15, 2);
    LCD_PrintString("TOPICOS II");
    LCD_SetCursor(10, 4);
    LCD_PrintString("PRESS START");
}

void System_Loop(void) {
    switch (systemState) {
        case STATE_SPLASH:
            // Se o botão B5 (Central) for pressionado, vai para o Menu
            if (BTN_IsPressed(B5_GPIO_Port, B5_Pin)) {
                systemState = STATE_MENU;
                LCD_Clear();
            }
            break;

        case STATE_MENU:
            // Navegação: B1 (Cima) e B2 (Baixo)
            if (BTN_IsPressed(B1_GPIO_Port, B1_Pin)) menuOption = 0;
            if (BTN_IsPressed(B2_GPIO_Port, B2_Pin)) menuOption = 1;

            // Renderização das opções
            LCD_SetCursor(0, 1);
            LCD_PrintString(menuOption == 0 ? "> JOGAR " : "  JOGAR ");
            LCD_SetCursor(0, 2);
            LCD_PrintString(menuOption == 1 ? "> CONFIG" : "  CONFIG");

            // Confirmar com B6 (Botão de Ação 1 na direita)
            if (BTN_IsPressed(B6_GPIO_Port, B6_Pin)) {
                if (menuOption == 0) systemState = STATE_GAME;
                LCD_Clear();
            }
            break;

        case STATE_GAME:
            // Tela provisória do jogo
            LCD_SetCursor(10, 2);
            LCD_PrintString("EM JOGO...");
            // Botão B5 (Central) para voltar ou pausar
            if (BTN_IsPressed(B5_GPIO_Port, B5_Pin)) {
                systemState = STATE_MENU;
                LCD_Clear();
            }
            break;

        default:
            break;
    }
}

