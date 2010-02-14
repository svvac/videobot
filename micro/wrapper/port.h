/*
 * videobot - automatic mode
 * description:  Wraps ports management
 * file: wrapper/port.h
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

#ifndef DEF_PORT
#define DEF_PORT

typedef struct port port;
struct port {
    volatile unsigned char *pointer;
    volatile unsigned char *mask;
    short B[8];
    /*short *B0;
    short *B1;
    short *B2;
    short *B3;
    short *B4;
    short *B5;
    short *B6;
    short *B7;*/

    int fridge;

    short isOutput;
    short isFreezed;
};

void portInit(port*, volatile unsigned char*, volatile unsigned char*);

void portSetOutput(port*);
void portSetInput(port*);
void portSetFreezed(port*);
void portSetLive(port*);

void portSync(port*);
void portSyncCond(port*);

void portGetByte(port*, int);
void portSetByte(port*, int, short);
void portSetRaw(port*, int);
void portGetRaw(port*);

void portBlank(port*);

void portByteIsEdge(port*, port*, int);

static int rawFromByte(short byte[8]);
static int rawFromInline(short, short, short, short, short, short, short, short);


#endif
