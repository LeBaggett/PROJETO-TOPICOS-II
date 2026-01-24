/*
 * ui_screen.h
 *
 *  Created on: Jan 23, 2026
 *      Author: Kaue Lucas
 */

#ifndef INC_UI_SCREEN_H_
#define INC_UI_SCREEN_H_

typedef struct {
    void (*on_enter)(void);
    void (*on_update)(void);
    void (*on_exit)(void);
} Screen_t;

#endif /* INC_UI_SCREEN_H_ */
