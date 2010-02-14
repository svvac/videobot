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

#include "io.h"

void freezeInputs(inputs *mem) {
    portSync(mem->device);

    mem->startButton        = mem->device->B[7];
    mem->camCeil            = mem->device->B[0];
    mem->camFloor           = mem->device->B[1];
    mem->distCritical       = mem->device->B[2];
    mem->distAcceptable     = mem->device->B[3];
}

void syncOutputs(outputs* mem) {
    mem->devicea->B[0]      = mem->delReady;
    mem->devicea->B[1]      = mem->delRun;
    mem->devicea->B[2]      = mem->delWaiting;
    mem->devicea->B[3]      = mem->delError;
    mem->devicea->B[4]      = mem->delDebug;

    /*mem->deviceb->B[4]      = mem->cameraUpw;
    mem->deviceb->B[5]      = mem->cameraDownw;

    mem->deviceb->B[0]      = mem->motorRForw;
    mem->deviceb->B[1]      = mem->motorRBackw;
    mem->deviceb->B[2]      = mem->motorLForw;
    mem->deviceb->B[3]      = mem->motorLBackw;*/

    portSync(mem->devicea);
    portSync(mem->deviceb);
}
