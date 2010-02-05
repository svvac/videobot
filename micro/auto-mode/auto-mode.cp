#line 1 "S:/videobot/micro/auto-mode/auto-mode.c"
#line 1 "s:/videobot/micro/auto-mode/inc/io.h"
#line 26 "S:/videobot/micro/auto-mode/auto-mode.c"
const int DBGMODE = 1;
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
#line 1 "s:/videobot/micro/auto-mode/inc/move.h"
#line 18 "s:/videobot/micro/auto-mode/inc/move.h"
void moveMotorRightForwards(void) {
  PORTC.F0  = 1;
  PORTC.F1  = 0;
}

void moveMotorRightBackwards(void) {
  PORTC.F0  = 0;
  PORTC.F1  = 1;
}

void moveMotorRightStops(void) {
  PORTC.F0  = 0;
  PORTC.F1  = 0;
}

void moveMotorLeftBackwards(void) {
  PORTC.F2  = 0;
  PORTC.F3  = 1;
}
void moveMotorLeftForwards(void) {
  PORTC.F2  = 1;
  PORTC.F3  = 0;
}

void moveMotorLeftStops(void) {
  PORTC.F2  = 0;
  PORTC.F3  = 0;
}

void moveForwards(void) {
 moveMotorRightForwards();
 moveMotorLeftForwards();
}

void moveBackwards(void) {
 moveMotorRightBackwards();
 moveMotorLeftBackwards();
}

void moveStops(void) {
 moveMotorRightStops();
 moveMotorLeftStops();
}

void moveTurnsRight(void) {
 moveMotorRightBackwards();
 moveMotorLeftForwards();
}

void moveTurnsLeft(void) {
 moveMotorRightForwards();
 moveMotorLeftBackwards();
}
#line 1 "s:/videobot/micro/auto-mode/inc/obstacle.h"
#line 19 "s:/videobot/micro/auto-mode/inc/obstacle.h"
const int ObstacleCriticalMetric = 20;
const int ObstacleOkMetric = 40;
const int ObstacleFarawayMetric = 100;


const int iDistOkOffset = 4;
const int iDistCritOffset = 3;
#line 33 "s:/videobot/micro/auto-mode/inc/obstacle.h"
int obstacleDistanceIsFaraway(int mem[5]) {

 if (DBGMODE) {

 return (!mem[iDistCritOffset] && !mem[iDistOkOffset]);
 }



 return 0;
}
#line 50 "s:/videobot/micro/auto-mode/inc/obstacle.h"
int obstacleDistanceIsOk(int mem[5]) {

 if (DBGMODE) {

 return (!mem[iDistCritOffset] && mem[iDistOkOffset]);
 }



 return 0;
}
#line 67 "s:/videobot/micro/auto-mode/inc/obstacle.h"
int obstacleDistanceIsCritical(int mem[5]) {

 if (DBGMODE) {

 return (mem[iDistCritOffset]);
 }



 return 1;
}
#line 84 "s:/videobot/micro/auto-mode/inc/obstacle.h"
int obstacleGetDistance(int mem[5]) {

 if (DBGMODE) {



 if (obstacleDistanceIsFaraway(mem)) return ObstacleFarawayMetric;
 else if (obstacleDistanceIsOk(mem)) return ObstacleOkMetric;
 else return ObstacleCriticalMetric;
 }



}
#line 36 "S:/videobot/micro/auto-mode/auto-mode.c"
void main() {



 INTCON = 0;


 TRISC = 0;
 PORTC = 0;
 TRISD = 0;
 PORTD = 0;


 TRISB = 0xff;


  PORTD.F0  = 1;

  PORTD.F2  = 1;


 if (DBGMODE)  PORTD.F4  = 1;


 moveStops();


 while (! PORTB.F7 );

  PORTD.F0  = 0;
  PORTD.F2  = 0;

  PORTD.F1  = 1;


 while (1) {

 int mem[5];
 mem[0] =  PORTB.F7 ;
 mem[1] =  PORTB.F0 ;
 mem[2] =  PORTB.F1 ;
 mem[3] =  PORTB.F2 ;
 mem[4] =  PORTB.F3 ;



 if (obstacleDistanceIsFaraway(mem)) {
 moveForwards();

 } else if (obstacleDistanceIsOk(mem)) {
 moveTurnsLeft();

 } else {
 moveStops();
 break;
 }
 }




  PORTD.F1  = 0;
  PORTD.F3  = 1;

 moveStops();
}
