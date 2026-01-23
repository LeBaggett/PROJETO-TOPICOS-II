/*
 * buttons.h
 *
 *  Created on: Jan 23, 2026
 *      Author: Kaue Lucas
 */

#ifndef INC_BUTTONS_H_
#define INC_BUTTONS_H_

typedef enum {
    BTN_UP,
    BTN_DOWN,
    BTN_ENTER,
    BTN_BACK,
    BTN_NONE
} Button_t;

void Buttons_init(void);
Button_t Buttons_ReadDebounced(void);

#endif /* INC_BUTTONS_H_ */
