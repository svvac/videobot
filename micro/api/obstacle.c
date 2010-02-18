/*
 * videobot - automatic mode
 * description:  Obstacle-related functions
 *               (in heavy developpement)
 * file: api/obstacle.c
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

#include "obstacle.h"

void obstacleInitAnalogInput(void) {
    // Okay this is ugly, we don't use the port wrapper. But
    // we really did NOT need it at all. It's like using a
    // bazooka to kill a fly in this very case.

    // Configure analog channels and Vref (from ADC samples)
    ADCON1 = 0x80;
    // Configure Port A as input
    TRISA  = 0xff;
}

int obstacleDistanceIsFaraway(inputs mem) {
    // If in debug mode
    if (DBGMODE) {
        // Returns true *only* if iDISTFAW == iDISTOK == 0
        return (!mem.distCritical && !mem.distAcceptable);
    }

    // If in normal mode
    // (Unimplemented)
    return 0;
}

int obstacleDistanceIsOk(inputs mem) {
    // If in debug mode
    if (DBGMODE) {
        // Returns true if iDISTCRIT == 0 and iDISTOK == 1
        return (!mem.distCritical && mem.distAcceptable);
    }

    // If in normal mode
    // Unimplemented
    return 0;
}

int obstacleDistanceIsCritical(inputs mem) {
    // If in debug mode
    if (DBGMODE) {
        // Returns true if iDISTCRIT == 1
        return (mem.distCritical);
    }

    // If in normal mode
    // Unimplemented
    return 1;
}

int obstacleGetDistance(inputs mem) {
    // Unimplemented
    return -1;
}
