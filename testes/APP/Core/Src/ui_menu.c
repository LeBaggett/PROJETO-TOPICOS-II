


void Menu_Update(Button_t btn, AppState_t *state)
{
    if (btn == BTN_DOWN && selected < 2) selected++;
    if (btn == BTN_UP   && selected > 0) selected--;

    if (btn == BTN_ENTER)
    {
        if (selected == 0) *state = APP_STATE_BRIGHTNESS;
        if (selected == 1) *state = APP_STATE_MUSIC;
        if (selected == 2) *state = APP_STATE_SAVE;
        return;
    }

    Display.write_line(1, selected == 0 ? ">Brightness" : " Brightness");
    Display.write_line(2, selected == 1 ? ">Play Music" : " Play Music");
    Display.write_line(3, selected == 2 ? ">Save File"  : " Save File");
}
