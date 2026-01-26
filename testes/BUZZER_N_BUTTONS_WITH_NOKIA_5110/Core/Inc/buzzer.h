/*
 * buzzer.h
 *
 *  Created on: Jan 24, 2026
 *      Author: Kaue Lucas
 */

#ifndef BUZZER_H
#define BUZZER_H

#include "stm32f1xx_hal.h"
#include <stdint.h>

void Buzzer_Init(void);
void Buzzer_Beep(uint16_t duration_ms);
void Buzzer_Update(void);

#endif
