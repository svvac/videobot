/*
 * videobot - automatic mode
 * description:  Provide memory freeze functionnalities
 * file: wrapper/freeze.c
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

#include "freeze.h"

void freezeInputs(inputs *mem) {
    mem->startButton        = PORTB.F7;
    mem->camCeil            = PORTB.F0;
    mem->camFloor           = PORTB.F1;
    mem->distCritical       = PORTB.F2;
    mem->distAcceptable     = PORTB.F3;
}

void syncOutputs(outputs* mem) {
    PORTD.F0                = mem->delReady;
    PORTD.F1                = mem->delRun;
    PORTD.F2                = mem->delWaiting;
    PORTD.F3                = mem->delError;
    PORTD.F4                = mem->delDebug;

    /*PORTC.F4                = mem->cameraUpw;
    PORTC.F5                = mem->cameraDownw;

    PORTC.F0                = mem->motorRForw;
    PORTC.F1                = mem->motorRBackw;
    PORTC.F2                = mem->motorLForw;
    PORTC.F3                = mem->motorLBackw;*/
}
