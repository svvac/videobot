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

int stepperBase = 100;

static int motorSteps(int mod) {
    static int count = 0;
    static int step = 0;
    if (mod > 0) {
        count = (count + 1) % mod;
        if (count == 0) {
            step = (step + 1) % STEPPER_PHASES_NB;
        }
    }
    return step;
}

static void moveMotorRightForwards(outputs *mem) {
    PORTC = stepperPhases[motorSteps(-1)];
}

static void moveMotorRightBackwards(outputs *mem) {
    PORTC = stepperPhases[7 - motorSteps(-1)];
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
    motorSteps(stepperBase);
    moveMotorRightForwards(mem);
    //moveMotorLeftForwards(mem);
}

void moveBackwards(outputs *mem) {
    motorSteps(stepperBase);
    moveMotorRightBackwards(mem);
    //moveMotorLeftBackwards(mem);
}

void moveStops(outputs *mem) {
    motorSteps(stepperBase);
    moveMotorRightStops(mem);
    moveMotorLeftStops(mem);
}

void moveTurnsRight(outputs *mem) {
    motorSteps(stepperBase);
    moveMotorRightBackwards(mem);
    moveMotorLeftForwards(mem);
}

void moveTurnsLeft(outputs *mem) {
    motorSteps(stepperBase);
    moveMotorRightForwards(mem);
    moveMotorLeftBackwards(mem);
}
