/*
 * screen_main_menu.c
 *
 *  Created on: Jan 23, 2026
 *      Author: Kaue Lucas
 */

#include "screen_main_menu.h"
#include "display.h"
#include "buttons.h"

#define MENU_ITEMS 3

static uint8_t selected = 0;

static const char *menu_items[MENU_ITEMS] = {
    "Brightness",
    "Play Music",
    "Save File"
};

/* ===================== DRAW ===================== */

static void draw_menu(void)
{
    Display.clear();
    Display.write_line(0, "Main Menu");

    for (uint8_t i = 0; i < MENU_ITEMS; i++)
    {
        char line[16];

        if (i == selected)
            snprintf(line, sizeof(line), "> %s", menu_items[i]);
        else
            snprintf(line, sizeof(line), "  %s", menu_items[i]);

        Display.write_line(i + 1, line);
    }
}

/* ===================== LIFECYCLE ===================== */

static void menu_on_enter(void)
{
    selected = 0;
    draw_menu();
}

static void menu_on_update(void)
{
    Button_t btn = Buttons_ReadDebounced();

    if (btn == BTN_DOWN && selected < MENU_ITEMS - 1)
    {
        selected++;
        draw_menu();
    }
    else if (btn == BTN_UP && selected > 0)
    {
        selected--;
        draw_menu();
    }
    else if (btn == BTN_ENTER)
    {
        // FUTURO:
        // UI_Manager_SetScreen(&Screen_Brightness);
        // UI_Manager_SetScreen(&Screen_Music);
    }
}

static void menu_on_exit(void)
{
    // Nada por enquanto
}

/* ===================== EXPORT ===================== */

Screen_t Screen_Menu = {
    .on_enter  = menu_on_enter,
    .on_update = menu_on_update,
    .on_exit   = menu_on_exit
};
