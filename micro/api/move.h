/*
 * videobot - automatic mode
 * description:  Displacement-related functions
 *               (in heavy developpement)
 * file: inc/move.h
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

#include "freeze.h"

static void moveMotorRightForwards(outputs*);
static void moveMotorRightBackwards(outputs*);
static void moveMotorRightStops(outputs*);

static void moveMotorLeftBackwards(outputs*);
static void moveMotorLeftForwards(outputs*);
static void moveMotorLeftStops(outputs*);

void moveForwards(outputs*);

void moveBackwards(outputs*);

void moveStops(outputs*);

void moveTurnsRight(outputs*);

void moveTurnsLeft(outputs*);

#endif
