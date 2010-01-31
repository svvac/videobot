#line 1 "S:/videobot/micro/auto-mode/auto-mode.c"
#line 1 "s:/videobot/micro/auto-mode/inc/io.h"
#line 26 "S:/videobot/micro/auto-mode/auto-mode.c"
const int DBGMODE = 1;
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
#line 29 "s:/videobot/micro/auto-mode/inc/obstacle.h"
int obstacleDistanceIsFaraway(void) {

 if (DBGMODE) {

 return (! PORTB.F2  && ! PORTB.F3 );
 }



 return 0;
}
#line 46 "s:/videobot/micro/auto-mode/inc/obstacle.h"
int obstacleDistanceIsOk(void) {

 if (DBGMODE) {

 return (! PORTB.F2  &&  PORTB.F3 );
 }



 return 0;
}
#line 63 "s:/videobot/micro/auto-mode/inc/obstacle.h"
int obstacleDistanceIsCritical(void) {

 if (DBGMODE) {

 return ( PORTB.F2 );
 }



 return 1;
}
#line 80 "s:/videobot/micro/auto-mode/inc/obstacle.h"
int obstacleGetDistance(void) {

 if (DBGMODE) {



 if (obstacleDistanceIsFaraway()) return ObstacleFarawayMetric;
 else if (obstacleDistanceIsOk()) return ObstacleOkMetric;
 else return ObstacleCriticalMetric;
 }



}
#line 33 "S:/videobot/micro/auto-mode/auto-mode.c"
void main() {

 OPTION_REG = 0x87;

 INTCON = 0xA0;


 TRISC = 0;
 PORTC = 0;
 TRISD = 0;
 PORTD = 0;


 TRISB = 0b11111111;


  PORTD.F0  = 1;

  PORTD.F2  = 1;


 if (DBGMODE)  PORTD.F4  = 1;


 moveStops();


 while (! PORTB.F7 );

  PORTD.F0  = 0;
  PORTD.F2  = 0;

  PORTD.F1  = 1;


 while (1) {


 if (obstacleDistanceIsFaraway()) {
 moveForwards();

 } else if (obstacleDistanceIsOk()) {
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
