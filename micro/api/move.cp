#line 1 "S:/videobot/micro/api/move.c"
#line 1 "s:/videobot/micro/api/move.h"
#line 1 "s:/videobot/micro/api/../wrapper/freeze.h"
#line 20 "s:/videobot/micro/api/../wrapper/freeze.h"
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
#line 23 "s:/videobot/micro/api/move.h"
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
#line 20 "S:/videobot/micro/api/move.c"
static void moveMotorRightForwards(outputs *mem) {
 mem->motorRForw = 1;
 mem->motorRBackw = 0;
}

static void moveMotorRightBackwards(outputs *mem) {
 mem->motorRForw = 0;
 mem->motorRBackw = 1;
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
 moveMotorRightForwards(mem);
 moveMotorLeftForwards(mem);
}

void moveBackwards(outputs *mem) {
 moveMotorRightBackwards(mem);
 moveMotorLeftBackwards(mem);
}

void moveStops(outputs *mem) {
 moveMotorRightStops(mem);
 moveMotorLeftStops(mem);
}

void moveTurnsRight(outputs *mem) {
 moveMotorRightBackwards(mem);
 moveMotorLeftForwards(mem);
}

void moveTurnsLeft(outputs *mem) {
 moveMotorRightForwards(mem);
 moveMotorLeftBackwards(mem);
}
