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

#ifndef DEF_OBSTACLE
#define DEF_OBSTACLE

#include "freeze.h"
#include "debug.h"

int obstacleDistanceIsFaraway(inputs);

int obstacleDistanceIsOk(inputs);

int obstacleDistanceIsCritical(inputs);

int obstacleGetDistance(inputs);

#endif
