/*
 * nokia5110.h
 *
 *  Created on: Jan 23, 2026
 *      Author: Kaue Lucas
 */

#ifndef INC_NOKIA5110_H_
#define INC_NOKIA5110_H_

#include <stdint.h>
#include "stm32f1xx_hal.h"

#define LCD_DC_PORT 		GPIOA
#define LCD_DC_PIN  		GPIO_PIN_1

#define LCD_CE_PORT 		GPIOA
#define LCD_CE_PIN  		GPIO_PIN_3

#define LCD_RESET_PORT 		GPIOA
#define LCD_RESET_PIN 		GPIO_PIN_0

#define LCD_BL_PORT 		GPIOB
#define LCD_BL_PIN		 	GPIO_PIN_0

void LCD_Write(uint8_t data, uint8_t isData);
void LCD_Reset(void);
void LCD_Init(void);
void LCD_Clear(void);
void LCD_SetXY(uint8_t x, uint8_t y);


#endif /* INC_NOKIA5110_H_ */
