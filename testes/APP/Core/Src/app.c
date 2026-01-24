/*
 * app.c
 *
 *  Created on: Jan 23, 2026
 *      Author: Kaue Lucas
 */

#include "app.h"
#include "ui_menu.h"
#include "buttons.h"

typedef enum {
    APP_STATE_MENU,
    APP_STATE_BRIGHTNESS,
    APP_STATE_MUSIC,
    APP_STATE_SAVE
} AppState_t;

static AppState_t currentState = APP_STATE_MENU;

void App_Init(void)
{
    Menu_Init();
}

void App_Update(void)
{
    Button_t btn = Buttons_ReadDebounced();

    switch (currentState)
    {
        case APP_STATE_MENU:
            Menu_Update(btn, &currentState);
            break;

        case APP_STATE_BRIGHTNESS:
            // Brightness_Update(btn, &currentState);
            break;

        case APP_STATE_MUSIC:
            // Music_Update(btn, &currentState);
            break;

        case APP_STATE_SAVE:
            // Save_Update(btn, &currentState);
            break;
    }
}


