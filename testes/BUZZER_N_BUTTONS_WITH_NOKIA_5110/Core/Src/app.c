/*
 * app.c
 *
 *  Created on: Jan 24, 2026
 *      Author: Kaue Lucas
 */

#include "app.h"

ButtonId_t App_GetButtonPressed(void)
{
    for (uint8_t i = 0; i < BTN_COUNT; i++)
    {
        if (Button_Pressed(i))
        {
            return (ButtonId_t)i;
        }
    }

    return BTN_COUNT; // nenhum botão
}

void App_OnButtonPressed(ButtonId_t btn)
{
    Buzzer_Beep(50);   // feedback imediato

    Display_Clear();
    Display_WriteLine(3, "           ");
    Display_WriteLine(4, "           ");

    switch (btn)
    {
        case BTN_0:
        	Display_WriteLine(2, "   BOTAO 0");
            break;

        case BTN_1:
        	Display_WriteLine(2, "   BOTAO 1");
            break;

        case BTN_2:
        	Display_WriteLine(2, "   BOTAO 2");
            break;

        case BTN_3:
        	Display_WriteLine(2, "   BOTAO 3");
            break;

        case BTN_4:
        	Display_WriteLine(2, "   BOTAO 4");
            break;

        case BTN_5:
        	Display_WriteLine(2, "   BOTAO 5");
            break;

        case BTN_6:
        	Display_WriteLine(2, "   BOTAO 6");
            break;

        case BTN_7:
        	Display_WriteLine(2, "   BOTAO 7");
            break;

        case BTN_8:
        	Display_WriteLine(2, "   BOTAO 8");
            break;

        default:
        	Display_WriteLine(2, "    NONE");
            break;
    }
}
