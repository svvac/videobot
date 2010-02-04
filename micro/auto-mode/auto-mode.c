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

// Bounds I/O associations
#include "inc/io.h"

// Set to "1" if in debug mode
const int DBGMODE = 1;

// Includes bot's functions
#include "inc/move.h"
#include "inc/obstacle.h"
//#include "inc/logic.h"

void main() {
    // TMR0 prescaler. No idea of what this means
    //OPTION_REG = 0x87;
    // Allow TMR0 interruptions
    INTCON = 0;
    
    // Outputs
    TRISC = 0;
    PORTC = 0;
    TRISD = 0;
    PORTD = 0;
    
    // Input
    TRISB = 0xff;
    
    // Turns on READY LED
    dREADY = 1;
    // Turns on WAITING LED
    dWAITING = 1;
    
    // If in debug mode, turns on DEBUG LED
    if (DBGMODE)    dDEBUG = 1;
    
    // Stops motors (just in case)
    moveStops();
    
    // Wait until user press on start
    while (!bSTART);
    // Turns off READY and WAITING LEDs
    dREADY = 0;
    dWAITING = 0;
    // Turns on RUNNING LED
    dRUN = 1;
    
    // Main loop
    while (1) {
        // Gets a snapshot of the inputs to prevent such issues as in bug #24
        int mem[5];
        mem[0] = bSTART;
        mem[1] = iCAMTOP;
        mem[2] = iCAMBTM;
        mem[3] = iDISTCRIT;
        mem[4] = iDISTOK;
        
        // Distance checks
        // If obstacle is "FAR AWAY", we continue forward
        if (obstacleDistanceIsFaraway(mem)) {
            moveForwards();
        // If obsacle is close, but not too much, we turns left
        } else if (obstacleDistanceIsOk(mem)) {
            moveTurnsLeft();
        // If obstacle is too close, we stops motors and stops the program
        } else {
            moveStops();
            break;
        }
    }
    
    // This is the shutdown program, executed when the infinite loop
    // is broken.
    // We turns off the RUN LED and turns on the ERROR LED
    dRUN = 0;
    dERROR = 1;
    // Just in case, we stops the motors.
    moveStops();
}

