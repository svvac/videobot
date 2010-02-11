#line 1 "S:/videobot/micro/api/obstacle.c"
#line 1 "s:/videobot/micro/api/obstacle.h"
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
#line 1 "s:/videobot/micro/api/../wrapper/debug.h"
#line 24 "s:/videobot/micro/api/obstacle.h"
int obstacleDistanceIsFaraway(inputs);

int obstacleDistanceIsOk(inputs);

int obstacleDistanceIsCritical(inputs);

int obstacleGetDistance(inputs);
#line 20 "S:/videobot/micro/api/obstacle.c"
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
