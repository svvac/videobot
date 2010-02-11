/*
 * videobot - automatic mode
 * description:  Provide memory freeze functionnalities
 * file: inc/freeze.h
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

#ifndef DEF_FREEZE
#define DEF_FREEZE

typedef struct inputs inputs;
struct inputs {
    int startButton;
    int camCeil;
    int camFloor;
    int distCritical;
    int distAcceptable;
};

typedef struct outputs outputs;
struct outputs {
    int delReady;
    int delRun;
    int delWaiting;
    int delError;
    int delDebug;
    
    int cameraUpw;
    int cameraDownw;
    
    int motorRForw;
    int motorRBackw;
    int motorLForw;
    int motorLBackw;
};

void freezeInputs(inputs*);

void syncOutputs(outputs*);

#endif
