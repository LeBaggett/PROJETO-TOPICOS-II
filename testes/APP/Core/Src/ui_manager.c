/*
 * ui_manager.c
 *
 *  Created on: Jan 23, 2026
 *      Author: Kaue Lucas
 */

#include "ui_manager.h"

static Screen_t *current = 0;

void UI_Init(Screen_t *initial)
{
    current = initial;
    if (current && current->init)
        current->init();
}

void UI_SetScreen(Screen_t *next)
{
    if (current && current->exit)
        current->exit();

    current = next;

    if (current && current->init)
        current->init();
}

void UI_Update(void)
{
    if (current && current->update)
        current->update();
}
