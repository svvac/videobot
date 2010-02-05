/*
 * videobot - automatic mode
 * description:  Obstacle-related functions
 *               (in heavy developpement)
 * file: inc/obstacle.c
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
#include "freeze.h"
#include "debug.h"

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
