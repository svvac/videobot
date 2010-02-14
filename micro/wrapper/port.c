/*
 * videobot - automatic mode
 * description:  Wraps ports management
 * file: wrapper/port.c
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

#include "port.h"

void portInit(port *device, volatile unsigned char *pointer, volatile unsigned char *tris) {
    device->pointer = pointer;
    device->mask = tris;

    /*device->B0    = &device->B[0];
    device->B1    = &device->B[1];
    device->B2    = &device->B[2];
    device->B3    = &device->B[3];
    device->B4    = &device->B[4];
    device->B5    = &device->B[5];
    device->B6    = &device->B[6];
    device->B7    = &device->B[7];*/

    device->isFreezed = 0;
    device->isOutput = 0;
    portSetInput(device);
    portSync(device);
}

void portSync(port *device) {
    if (device->isOutput) {
        // if this port is an output, we commit the changes
        *(device->pointer) = rawFromByte(device->B);
    } else {
        // If the port is an input, we read the actual values
        device->B[0]    = device->pointer->F0;
        device->B[1]    = device->pointer->F1;
        device->B[2]    = device->pointer->F2;
        device->B[3]    = device->pointer->F3;
        device->B[4]    = device->pointer->F4;
        device->B[5]    = device->pointer->F5;
        device->B[6]    = device->pointer->F6;
        device->B[7]    = device->pointer->F7;
    }

    // In all cases, we calculates the new "fridge"
    device->fridge = rawFromByte(device->B);
}

void portSyncCond(port *device) {
    if (!device->isFreezed)
        portSync(device);
}

void portSetInput(port *device) {
    *(device->mask) = 0xff;
    device->isOutput = 0;
    portSyncCond(device);
}

void portSetOutput(port *device) {
    *(device->mask) = 0x00;
    device->isOutput = 1;
    portSyncCond(device);
}

void portSetFreezed(port *device) {
    device->isFreezed = 1;
}

void portSetLive(port *device) {
    device->isFreezed = 0;
    portSyncCond(device);
}

short portGetByte(port *device, int weight) {
    if (weight < 0 || weight > 7)
        return 0;

    portSyncCond(device);

    return device->B[weight];
}

void portSetByte(port *device, int weight, short state) {
    if (weight < 0 || weight > 7)
        return;

    device->B[weight] = state;

    portSyncCond(device);
}

void portSetRaw(port *device, int raw) {
    int pow[8] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };
    int i;

    for (i = 0; i < 8; i++) {
        if ((raw & pow[i]) > 0)
            portSetByte(device, i, 1);
        else
            portSetByte(device, i, 0);
    }

    portSyncCond(device);
}

int portGetRaw(port *device) {
    portSyncCond(device);
    return rawFromByte(device->B);
}

void portBlank(port *device) {
    portSetRaw(device, 0x00);
}

static int rawFromByte(short byte[8]) {
    int value = 0, i = 0;
    int pow[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    for (i=0; i < 8; i++)
        value += byte[i] * pow[i];

    return value;
}

static int rawFromInline(short b0, short b1, short b2, short b3, short b4, short b5, short b6, short b7) {
    int arr[8];
    arr[0] = b0;
    arr[1] = b1;
    arr[2] = b2;
    arr[3] = b3;
    arr[4] = b4;
    arr[5] = b5;
    arr[6] = b6;
    arr[7] = b7;

    return rawFromByte(arr);
}
