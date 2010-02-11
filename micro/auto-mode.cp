#line 1 "S:/videobot/micro/auto-mode.c"
#line 1 "s:/videobot/micro/wrapper/debug.h"
#line 1 "s:/videobot/micro/wrapper/freeze.h"
#line 20 "s:/videobot/micro/wrapper/freeze.h"
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
#line 1 "s:/videobot/micro/api/move.h"
#line 1 "s:/videobot/micro/api/../wrapper/freeze.h"
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
#line 1 "s:/videobot/micro/api/obstacle.h"
#line 1 "s:/videobot/micro/api/../wrapper/freeze.h"
#line 1 "s:/videobot/micro/api/../wrapper/debug.h"
#line 24 "s:/videobot/micro/api/obstacle.h"
int obstacleDistanceIsFaraway(inputs);

int obstacleDistanceIsOk(inputs);

int obstacleDistanceIsCritical(inputs);

int obstacleGetDistance(inputs);
#line 33 "S:/videobot/micro/auto-mode.c"
void main() {

 inputs iMem;
 outputs oMem = {0};


 INTCON = 0;

 TRISC = 0;
 PORTC = 0;
 TRISD = 0;
 PORTD = 0;

 TRISB = 0xff;


 syncOutputs(&oMem);

 freezeInputs(&iMem);


 oMem.delReady = 1;

 oMem.delWaiting = 1;

 if ( 1 ) oMem.delDebug = 1;


 moveStops(&oMem);


 syncOutputs(&oMem);



 while (!iMem.startButton) freezeInputs(&iMem);



 oMem.delReady = 0;
 oMem.delWaiting = 0;

 oMem.delRun = 1;

 syncOutputs(&oMem);


 do {

 freezeInputs(&iMem);

 syncOutputs(&oMem);



 if (obstacleDistanceIsFaraway(iMem)) {
 moveForwards(&oMem);

 } else if (obstacleDistanceIsOk(iMem)) {
 moveTurnsLeft(&oMem);

 } else {
 moveStops(&oMem);
 break;
 }
 } while (1);




 oMem.delRun = 0;
 oMem.delError = 1;

 moveStops(&oMem);

 syncOutputs(&oMem);
}
