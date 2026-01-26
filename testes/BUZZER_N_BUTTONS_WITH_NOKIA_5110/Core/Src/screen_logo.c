/*
 * screen_logo.c
 *
 *  Created on: Jan 25, 2026
 *      Author: Kaue Lucas
 */

#include "screen_logo.h"

extern LCD_PCD8544_screen_t gLcdScreen;

void LogoScreen_Show(void)
{
    LCD_PCD8544_clear_ram(&gLcdScreen);

    LCD_PCD8544_draw_bitmap(&gLcdScreen, protogame_logo);

    HAL_Delay(2000); // mostra por 2 segundos
}

