/*
 * ui_manager.h
 *
 *  Created on: Jan 23, 2026
 *      Author: Kaue Lucas
 */

#ifndef INC_UI_MANAGER_H_
#define INC_UI_MANAGER_H_

#include "screen.h"

void UI_Init(Screen_t *initial);
void UI_SetScreen(Screen_t *next);
void UI_Update(void);

#endif /* INC_UI_MANAGER_H_ */
