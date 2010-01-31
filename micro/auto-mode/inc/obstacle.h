/*
 * videobot - automatic mode
 * description:  Obstacle-related functions
 *               (in heavy developpement)
 * file: inc/obstacle.h
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

//        CONSTANT                  VALUE (cm)      COMP    SIGNAL
const int ObstacleCriticalMetric    = 20;       //  <=      DIST_CRITICAL
const int ObstacleOkMetric          = 40;       //  <=      DIST_OK
const int ObstacleFarawayMetric     = 100;      //  >=      DIST_FARAWAY


/*
 * int obstacleDistanceIsFaraway(void)
 *
 * Returns true if distance to object can't be precisely computed.
 */
int obstacleDistanceIsFaraway(void) {
    // If in debug mode
    if (DBGMODE) {
        // Returns true *only* if iDISTFAW == iDISTOK == 0
        return (!iDISTCRIT && !iDISTOK);
    }
    
    // If in normal mode
    // (Unimplemented)
    return 0;
}

/*
 * int obstacleDistanceIsOk(void)
 *
 * Returns true if distance to object is between CRITICAL and FARAWAY
 */
int obstacleDistanceIsOk(void) {
    // If in debug mode
    if (DBGMODE) {
        // Returns true if iDISTCRIT == 0 and iDISTOK == 1
        return (!iDISTCRIT && iDISTOK);
    }
    
    // If in normal mode
    // Unimplemented
    return 0;
}

/*
 * int obstacleDistanceIsCritical(void)
 *
 * Returns true if distance to object is lower than CRITICAL
 */
int obstacleDistanceIsCritical(void) {
    // If in debug mode
    if (DBGMODE) {
        // Returns true if iDISTCRIT == 1
        return (iDISTCRIT);
    }
    
    // If in normal mode
    // Unimplemented
    return 1;
}

/*
 * int obstacleGetDistance(void)
 *
 * Returns the distance (in centimeters) to the obstacle
 */
int obstacleGetDistance(void) {
    // If in debug mode
    if (DBGMODE) {
        // We can't have a precise idea of the distance because there's no
        // captor. So we returns limits instead.
        
        if (obstacleDistanceIsFaraway())        return ObstacleFarawayMetric;
        else if (obstacleDistanceIsOk())        return ObstacleOkMetric;
        else                                    return ObstacleCriticalMetric;
    }
    
    // If in normal mode
    // Unimplemented
}


