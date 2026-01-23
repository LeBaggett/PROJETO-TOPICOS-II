/*
 * nokia5110.c
 *
 *  Created on: Jan 23, 2026
 *      Author: Kaue Lucas
 */

#include "nokia5110.h"

extern SPI_HandleTypeDef hspi1;

void LCD_Init(void) {
    LCD_Reset();

    LCD_Write(0x21, 0); // Modo estendido
    LCD_Write(0xB8, 0); // CONTRASTE ALTO (teste)
    LCD_Write(0x04, 0); // Coef. temperatura
    LCD_Write(0x14, 0); // Bias mode
    LCD_Write(0x20, 0); // Modo básico
    LCD_Write(0x0C, 0); // Display normal
}

void LCD_Write(uint8_t data, uint8_t isData) {
    HAL_GPIO_WritePin(LCD_DC_PORT, LCD_DC_PIN,
                      isData ? GPIO_PIN_SET : GPIO_PIN_RESET);

    HAL_GPIO_WritePin(LCD_CE_PORT, LCD_CE_PIN, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, &data, 1, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(LCD_CE_PORT, LCD_CE_PIN, GPIO_PIN_SET);
}

void LCD_Reset(void) {
    HAL_GPIO_WritePin(LCD_RESET_PORT, LCD_RESET_PIN, GPIO_PIN_RESET);
    HAL_Delay(10);
    HAL_GPIO_WritePin(LCD_RESET_PORT, LCD_RESET_PIN, GPIO_PIN_SET);
}

void LCD_Clear(void) {
	LCD_SetXY(0, 0);
    for (int i = 0; i < 504; i++) { // 84 × 48 / 8 = 504 bytes
        LCD_Write(0x00, 1);
    }
}

void LCD_SetXY(uint8_t x, uint8_t y) {
    LCD_Write(0x80 | x, 0);  // X: 0..83
    LCD_Write(0x40 | y, 0);  // Y: 0..5 (banks)
}


