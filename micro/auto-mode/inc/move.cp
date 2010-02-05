#line 1 "S:/videobot/micro/auto-mode/inc/move.c"
#line 1 "s:/videobot/micro/auto-mode/inc/move.h"
#line 1 "s:/videobot/micro/auto-mode/inc/freeze.h"
#line 20 "s:/videobot/micro/auto-mode/inc/freeze.h"
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
#line 25 "s:/videobot/micro/auto-mode/inc/move.h"
static const int stepperPhases[ 8 ] = {0x20,0x28,0x08,0x88,0x80,0x82,0x02,0x22};

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
#line 20 "S:/videobot/micro/auto-mode/inc/move.c"
int stepperBase = 100;

static int motorSteps(int mod) {
 static int count = 0;
 static int step = 0;
 if (mod > 0) {
 count = (count + 1) % mod;
 if (count == 0) {
 step = (step + 1) %  8 ;
 }
 }
 return step;
}

static void moveMotorRightForwards(outputs *mem) {
 PORTC = stepperPhases[motorSteps(-1)];
}

static void moveMotorRightBackwards(outputs *mem) {
 PORTC = stepperPhases[7 - motorSteps(-1)];
}

static void moveMotorRightStops(outputs *mem) {
 mem->motorRForw = 0;
 mem->motorRBackw = 0;
}

static void moveMotorLeftBackwards(outputs *mem) {
 mem->motorLForw = 0;
 mem->motorLBackw = 1;
}
static void moveMotorLeftForwards(outputs *mem) {
 mem->motorLForw = 1;
 mem->motorLBackw = 0;
}

static void moveMotorLeftStops(outputs *mem) {
 mem->motorLForw = 0;
 mem->motorLBackw = 0;
}

void moveForwards(outputs *mem) {
 motorSteps(stepperBase);
 moveMotorRightForwards(mem);

}

void moveBackwards(outputs *mem) {
 motorSteps(stepperBase);
 moveMotorRightBackwards(mem);

}

void moveStops(outputs *mem) {
 motorSteps(stepperBase);
 moveMotorRightStops(mem);
 moveMotorLeftStops(mem);
}

void moveTurnsRight(outputs *mem) {
 motorSteps(stepperBase);
 moveMotorRightBackwards(mem);
 moveMotorLeftForwards(mem);
}

void moveTurnsLeft(outputs *mem) {
 motorSteps(stepperBase);
 moveMotorRightForwards(mem);
 moveMotorLeftBackwards(mem);
}
