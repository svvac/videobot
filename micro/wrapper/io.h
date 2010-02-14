/*
 * videobot - automatic mode
 * description:  Provide memory freeze functionnalities
 * file: wrapper/io.h
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

#ifndef DEF_IO
#define DEF_IO

#include "port.h"

typedef struct inputs inputs;
struct inputs {
    port *device;

    short startButton;
    short camCeil;
    short camFloor;
    short distCritical;
    short distAcceptable;
};

typedef struct outputs outputs;
struct outputs {
    port *devicea;
    port *deviceb;

    short delReady;
    short delRun;
    short delWaiting;
    short delError;
    short delDebug;

    short cameraUpw;
    short cameraDownw;

    short motorRForw;
    short motorRBackw;
    short motorLForw;
    short motorLBackw;
};

void freezeInputs(inputs*);

void syncOutputs(outputs*);

#endif
