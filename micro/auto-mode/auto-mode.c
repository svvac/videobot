/*
 * videobot - automatic mode
 * description:  The bot goes forward until it encounters an obstacle
 *               (in heavy developpement)
 *               Please note that I've absolutely no experience in MCU
 *               programmation, especially with C. I'm actually trying
 *               some pieces of code to catch the logic of the board,
 *               before to start the “real” program.
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

// Bounds I/O associations
#include "inc/io.h"

void main() {
    const int delay = 500;
    int i = 0;
    
    // TMR0 prescaler. No idea of what this means
    OPTION_REG = 0x87;
    // Allow TMR0 interruptions
    INTCON = 0xA0;
    
    // Outputs
    TRISC = 0;
    PORTC = 0;
    
    TRISD = 0;
    PORTD = 0;
    
    // Input (I guess)
    TRISB = 0b11111111;
    
    // Wait until user press on start
    while (!bSTART);
    
    // Main loop
    while (1) {
        i++;
        LED1 = i % 2;
        Delay_ms(delay);
        LED2 = i % 2;
        Delay_ms(delay);
        LED3 = i % 2;
        Delay_ms(delay);
        LED4 = i % 2;
        Delay_ms(delay);
        LED5 = i % 2;
        Delay_ms(delay);
        LED6 = i % 2;
        Delay_ms(delay);
        LED7 = i % 2;
        Delay_ms(delay);
        LED8 = i % 2;
        Delay_ms(delay);
    }
}

