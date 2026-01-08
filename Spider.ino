
#include "Servo.h"
#include <math.h>
#include "SpiderConsts.h"
#include "SpiderMoves.h"

void setup() {
  servoA.attach(2); //передняя правая 1 
  servoB.attach(3); //передняя правая 2
  servoC.attach(4); //задняя правая 1
  servoD.attach(5); //задняя правая 2
  servoE.attach(6); //задняя левая 1
  servoF.attach(7); //задняя левая 2
  servoG.attach(8); //передняя левая 1
  servoH.attach(9); //передняя левая 2
}

void loop() 
{
  danceNonBlocking();
}
