/*
 * videobot - automatic mode
 * description:  The bot goes forward until it encounters an obstacle
 *               (in heavy developpement)
 * file: auto-mode.c
 *
 * config:
 *   controller:      PIC16F877A (EasyPic 4)
 *   clock:           HS, 08.0000 MHz
 *   compiler:        mikroC PRO 2009 (3.2)
 * author: Simon "SwordOfPain" Wachter
 *
 * This file is a part of the videobot project.
 * Web: http://swordofpain.hd.free.fr/tracker/projects/videobot
 * GitHub repo: http://github.com/swordofpain/videobot
 */

#include "inc/physical.h"

void main() {
    OPTION_REG = 0x87;
    INTCON = 0xA0;
    
    TRISA = 0;
    PORTA = 0;
    TRISB = 0b111111;
    TRISD = 0;
    PORTD = 0;

    while (1) {
        LED1 = LED2 = LED3 = 1;
    }
}

