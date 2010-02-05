#line 1 "S:/videobot/micro/auto-mode/inc/obstacle.c"
#line 1 "s:/videobot/micro/auto-mode/inc/obstacle.h"
#line 21 "s:/videobot/micro/auto-mode/inc/obstacle.h"
int obstacleDistanceIsFaraway(inputs);

int obstacleDistanceIsOk(inputs);

int obstacleDistanceIsCritical(inputs);

int obstacleGetDistance(inputs);
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
#line 1 "s:/videobot/micro/auto-mode/inc/debug.h"
#line 22 "S:/videobot/micro/auto-mode/inc/obstacle.c"
int obstacleDistanceIsFaraway(inputs mem) {

 if ( 1 ) {

 return (!mem.distCritical && !mem.distAcceptable);
 }



 return 0;
}

int obstacleDistanceIsOk(inputs mem) {

 if ( 1 ) {

 return (!mem.distCritical && mem.distAcceptable);
 }



 return 0;
}

int obstacleDistanceIsCritical(inputs mem) {

 if ( 1 ) {

 return (mem.distCritical);
 }



 return 1;
}

int obstacleGetDistance(inputs mem) {

 return -1;
}
