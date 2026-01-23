/*
 * screen.h
 *
 *  Created on: Jan 23, 2026
 *      Author: Kaue Lucas
 */

#ifndef INC_SCREEN_H_
#define INC_SCREEN_H_

#include <stdint.h>

typedef struct Screen {
    void (*on_enter)(void);
    void (*on_update)(void);
    void (*on_exit)(void);
} Screen_t;

#endif /* INC_SCREEN_H_ */
