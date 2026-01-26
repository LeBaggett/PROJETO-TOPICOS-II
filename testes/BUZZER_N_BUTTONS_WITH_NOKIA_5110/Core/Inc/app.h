/*
 * app.h
 *
 *  Created on: Jan 24, 2026
 *      Author: Kaue Lucas
 */

#ifndef INC_APP_H_
#define INC_APP_H_

#include "main.h"
#include "buttons.h"
#include "display.h"
#include "buzzer.h"

ButtonId_t App_GetButtonPressed(void);
void App_OnButtonPressed(ButtonId_t btn);

#endif /* INC_APP_H_ */
