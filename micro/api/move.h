/*
 * videobot - automatic mode
 * description:  Displacement-related functions
 *               (in heavy developpement)
 * file: api/move.h
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

#ifndef DEF_MOVE
#define DEF_MOVE

#include "../wrapper/io.h"
#include "../wrapper/port.h"

#define STEPPER_PHASES_NB 8

static const int stepperPhases[STEPPER_PHASES_NB] = {0x20,0x28,0x08,0x88,0x80,0x82,0x02,0x22};

static void moveMotorRightForwards(outputs*);
static void moveMotorRightBackwards(outputs*);
static void moveMotorRightStops(outputs*);

static void moveMotorLeftBackwards(outputs*);
static void moveMotorLeftForwards(outputs*);
static void moveMotorLeftStops(outputs*);

static int motorSteps(int);

void moveForwards(outputs*);

void moveBackwards(outputs*);

void moveStops(outputs*);

void moveTurnsRight(outputs*);

void moveTurnsLeft(outputs*);

#endif
