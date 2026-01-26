/*
 * display.h
 *
 *  Created on: Jan 23, 2026
 *      Author: Kaue Lucas
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#include <stdint.h>
#include "main.h"
#include "lcd_pcd8544.h"

void Display_Init(void);
void Display_Clear(void);
void Display_WriteLine(uint8_t line, const char *text);

#endif /* INC_DISPLAY_H_ */
