/*
 * videobot - automatic mode
 * description:  Displacement-related functions
 *               (in heavy developpement)
 * file: inc/move.c
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

#include "move.h"

static void moveMotorRightForwards(outputs *mem) {
    mem->motorRForw = 1;
    mem->motorRBackw = 0;
}

static void moveMotorRightBackwards(outputs *mem) {
    mem->motorRForw = 0;
    mem->motorRBackw = 1;
}

static void moveMotorRightStops(outputs *mem) {
    mem->motorRForw = 0;
    mem->motorRBackw = 0;
}

static void moveMotorLeftBackwards(outputs *mem) {
    mem->motorLForw = 0;
    mem->motorLBackw = 1;
}
static void moveMotorLeftForwards(outputs *mem) {
    mem->motorLForw = 1;
    mem->motorLBackw = 0;
}

static void moveMotorLeftStops(outputs *mem) {
    mem->motorLForw = 0;
    mem->motorLBackw = 0;
}

void moveForwards(outputs *mem) {
    moveMotorRightForwards(mem);
    moveMotorLeftForwards(mem);
}

void moveBackwards(outputs *mem) {
    moveMotorRightBackwards(mem);
    moveMotorLeftBackwards(mem);
}

void moveStops(outputs *mem) {
    moveMotorRightStops(mem);
    moveMotorLeftStops(mem);
}

void moveTurnsRight(outputs *mem) {
    moveMotorRightBackwards(mem);
    moveMotorLeftForwards(mem);
}

void moveTurnsLeft(outputs *mem) {
    moveMotorRightForwards(mem);
    moveMotorLeftBackwards(mem);
}
