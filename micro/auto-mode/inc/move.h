/*
 * videobot - automatic mode
 * description:  Displacement-related functions
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

void moveMotorRightForwards(void) {
    oRMOTORF = 1;
    oRMOTORB = 0;
}

void moveMotorRightBackwards(void) {
    oRMOTORF = 0;
    oRMOTORB = 1;
}

void moveMotorRightStops(void) {
    oRMOTORF = 0;
    oRMOTORB = 0;
}

void moveMotorLeftBackwards(void) {
    oLMOTORF = 0;
    oLMOTORB = 1;
}
void moveMotorLeftForwards(void) {
    oLMOTORF = 1;
    oLMOTORB = 0;
}

void moveMotorLeftStops(void) {
    oLMOTORF = 0;
    oLMOTORB = 0;
}

void moveForwards(void) {
    moveMotorRightForwards();
    moveMotorLeftForwards();
}

void moveBackwards(void) {
    moveMotorRightBackwards();
    moveMotorLeftBackwards();
}

void moveStops(void) {
    moveMotorRightStops();
    moveMotorLeftStops();
}

void moveTurnsRight(void) {
    moveMotorRightBackwards();
    moveMotorLeftForwards();
}

void moveTurnsLeft(void) {
    moveMotorRightForwards();
    moveMotorLeftBackwards();
}

