/*
 * screen_logo.c
 *
 *  Created on: Jan 23, 2026
 *      Author: Kaue Lucas
 */

// screen_logo.c
// screen_logo.c
#include "screen_logo.h"
#include "display.h"
#include "ui_manager.h"   // para pedir troca de tela
#include "stm32f1xx_hal.h"

#define LOGO_TIME_MS 2000  // 2 segundos

static uint32_t start_time;

/* ================= CALLBACKS ================= */

static void Logo_OnEnter(void)
{
    Display.clear();

    Display.write_line(1, "Kaue Lucas");
    Display.write_line(2, "STM32 FW");
    Display.write_line(4, "Starting...");

    start_time = HAL_GetTick();
}

static void Logo_OnUpdate(void)
{
    if (HAL_GetTick() - start_time >= LOGO_TIME_MS)
    {
        UI_Manager_SetScreen(UI_SCREEN_MENU);
    }
}

static void Logo_OnExit(void)
{
    Display.clear();
}

/* ================= SCREEN ================= */

Screen_t Screen_Logo = {
    .on_enter  = Logo_OnEnter,
    .on_update = Logo_OnUpdate,
    .on_exit   = Logo_OnExit
};

