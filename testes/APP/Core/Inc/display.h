/*
 * display.h
 *
 *  Created on: Jan 23, 2026
 *      Author: Kaue Lucas
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#include <stdint.h>

typedef struct {
    void (*init)(void);
    void (*clear)(void);
    void (*write_line)(uint8_t line, const char *text);
} Display_t;

extern Display_t Display;

#endif /* INC_DISPLAY_H_ */
