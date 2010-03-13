/*
 * videobot - automatic mode
 * description:  The bot goes forward until it encounters an obstacle
 *               (in heavy developpement)
 *               Please note that I've absolutely no experience in MCU
 *               programmation, especially with C. I'm actually trying
 *               some pieces of code to catch the logic of the board,
 *               before to start the "real" program.
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

#include "wrapper/port.h"



void main() {
    // Define port accessors
    port A, B, C, D;

    // Command container
    char input[100];

    // Initializes ports
    portInit(&A, &PORTA, &TRISA);
    portInit(&B, &PORTB, &TRISB);
    portInit(&C, &PORTC, &TRISC);
    portInit(&D, &PORTD, &TRISD);


    // Endless loop
    do {

    } while (1);
}
