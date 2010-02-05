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

// Set status of debug mode
#include "inc/debug.h"

// I/O management wrappers
#include "inc/freeze.h"

// Displacement API
#include "inc/move.h"
// Obstacle detection API
#include "inc/obstacle.h"

void main() {
    // I/O structures
    inputs  iMem;
    outputs oMem = {0};
    
    // Ports mapping
    INTCON = 0;
    // Outputs
    TRISC = 0;
    PORTC = 0;
    TRISD = 0;
    PORTD = 0;
    // Input
    TRISB = 0xff;
    
    // Cleans ports
    syncOutputs(&oMem);
    // Updates inbound
    freezeInputs(&iMem);
    
    // Turns on READY LED
    oMem.delReady = 1;
    // Turns on WAITING LED
    oMem.delWaiting = 1;
    // If in debug mode, turns on DEBUG LED
    if (DBGMODE)    oMem.delDebug = 1;
    
    // Stops motors (just in case)
    moveStops(oMem);
    
    // Commit on ports
    syncOutputs(&oMem);
    
    
    // Wait until user press on start
    while (!iMem.startButton)     freezeInputs(&iMem);
    
    
    // Turns off READY and WAITING LEDs
    oMem.delReady = 0;
    oMem.delWaiting = 0;
    // Turns on RUNNING LED
    oMem.delRun = 1;
    // Commits
    syncOutputs(&oMem);
    
    // Main loop
    while (1) {
        // Gets a snapshot of the inputs to prevent such issues as in bug #24
        freezeInputs(&iMem);
        // Commit output changes
        syncOutputs(&oMem);
        
        // Distance checks
        // If obstacle is "FAR AWAY", we continue forward
        if (obstacleDistanceIsFaraway(iMem)) {
            moveForwards(oMem);
        // If obsacle is close, but not too much, we turns left
        } else if (obstacleDistanceIsOk(iMem)) {
            moveTurnsLeft(oMem);
        // If obstacle is too close, we stops motors and stops the program
        } else {
            moveStops(oMem);
            break;
        }
    }
    
    // This is the shutdown program, executed when the infinite loop
    // is broken.
    // We turns off the RUN LED and turns on the ERROR LED
    oMem.delRun = 0;
    oMem.delError = 1;
    // Just in case, we stops the motors.
    moveStops(oMem);
    // Sync
    syncOutputs(&oMem);
}

