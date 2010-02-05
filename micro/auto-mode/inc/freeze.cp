#line 1 "S:/videobot/micro/auto-mode/inc/freeze.c"
#line 1 "s:/videobot/micro/auto-mode/inc/freeze.h"
#line 17 "s:/videobot/micro/auto-mode/inc/freeze.h"
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
#line 19 "S:/videobot/micro/auto-mode/inc/freeze.c"
void freezeInputs(inputs *mem) {
 mem->startButton = PORTB.F7;
 mem->camCeil = PORTB.F0;
 mem->camFloor = PORTB.F1;
 mem->distCritical = PORTB.F2;
 mem->distAcceptable = PORTB.F3;
}

void syncOutputs(outputs* mem) {
 PORTD.F0 = mem->delReady;
 PORTD.F1 = mem->delRun;
 PORTD.F2 = mem->delWaiting;
 PORTD.F3 = mem->delError;
 PORTD.F4 = mem->delDebug;

 PORTC.F4 = mem->cameraUpw;
 PORTC.F5 = mem->cameraDownw;

 PORTC.F0 = mem->motorRForw;
 PORTC.F1 = mem->motorRBackw;
 PORTC.F2 = mem->motorLForw;
 PORTC.F3 = mem->motorLBackw;
}
