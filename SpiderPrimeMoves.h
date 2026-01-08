#ifndef PrimeMoves
#define PrimeMoves
#include "SpiderConsts.h"
#include "SpiderStart.h"
#include <Arduino.h>
/*
Библиотека
forward() - шаг вперед
forwardMirror() - шаг вперед другой стороной
back() - шаг назад
backMirror() - шаг назад другой стороной
right() - направо на месте
left() - налево на месте
right_line() - боком по прямой вправо
left_line() - боком по прямой влево
lunging_side() - выпады в стороны
workout_sides() - тренировка в стороны
workout_forward() - тренировка вперед-назад
*/

void back(){//шаг назад
  int B = 90;
  int D = 90;
  int F = 90;
  int H = 90;
  for(int i = 90; i <= 110; i+=2){
    servoA.write(180-i);
    B += 1;
    servoB.write(B);
    delay(5);

    servoC.write(i);
    D += 1;
    servoD.write(D);
    delay(5);
    
    servoE.write(i);
    F += 1;
    servoF.write(F);
    delay(5);

    servoG.write(180-i);
    H += 1;
    servoH.write(H);
    delay(5);
  }
  for(int i = 110; i <= 130; i+=2){
    servoA.write(180-i);
    B -= 1;
    servoB.write(B);
    delay(5);

    servoC.write(i);
    D -= 1;
    servoD.write(D);
    delay(5);

    servoE.write(i);
    F -= 1;
    servoF.write(F);
    delay(5);

    servoG.write(180-i);
    H -= 1;
    servoH.write(H);
    delay(5);
  }
  for(int i = 130; i >= 110; i-=2){
    servoA.write(180-i);
    B -= 1;
    servoB.write(B);
    delay(5);

    servoC.write(i);
    D -= 1;
    servoD.write(D);
    delay(5);

    servoE.write(i);
    F -= 1;
    servoF.write(F);
    delay(5);

    servoG.write(180-i);
    H -= 1;
    servoH.write(H);
    delay(5);
  }
  for(int i = 110; i >= 90; i-=2){
    servoA.write(180-i);
    B += 1;
    servoB.write(B);
    delay(5);

    servoC.write(i);
    D += 1;
    servoD.write(D);
    delay(5);

    servoE.write(i);
    F += 1;
    servoF.write(F);
    delay(5);

    servoG.write(180-i);
    H += 1;
    servoH.write(H);
    delay(5);
  }

}
void backMirror(){//шаг назад зеркально
  int B = 90;
  int D = 90;
  int F = 90;
  int H = 90;
  for(int i = 90; i <= 110; i+=2){
    servoA.write(i);
    B -= 1;
    servoB.write(B);
    delay(5);

    servoC.write(180-i);
    D -= 1;
    servoD.write(D);
    delay(5);
    
    servoE.write(180-i);
    F -= 1;
    servoF.write(F);
    delay(5);

    servoG.write(i);
    H -= 1;
    servoH.write(H);
    delay(5);
  }
  for(int i = 110; i <= 130; i+=2){
    servoA.write(i);
    B += 1;
    servoB.write(B);
    delay(5);

    servoC.write(180-i);
    D += 1;
    servoD.write(D);
    delay(5);

    servoE.write(180-i);
    F += 1;
    servoF.write(F);
    delay(5);

    servoG.write(i);
    H += 1;
    servoH.write(H);
    delay(5);
  }
  for(int i = 130; i >= 110; i-=2){
    servoA.write(i);
    B += 1;
    servoB.write(B);
    delay(5);

    servoC.write(180-i);
    D += 1;
    servoD.write(D);
    delay(5);

    servoE.write(180-i);
    F += 1;
    servoF.write(F);
    delay(5);

    servoG.write(i);
    H += 1;
    servoH.write(H);
    delay(5);
  }
  for(int i = 110; i >= 90; i-=2){
    servoA.write(i);
    B -= 1;
    servoB.write(B);
    delay(5);

    servoC.write(180-i);
    D -= 1;
    servoD.write(D);
    delay(5);

    servoE.write(180-i);
    F -= 1;
    servoF.write(F);
    delay(5);

    servoG.write(i);
    H -= 1;
    servoH.write(H);
    delay(5);
  }

}
void forward() {//шаг вперед
  int B = 90;
  int D = 90;
  int F = 90;
  int H = 90;

  // Этап 1: Лапы, которые шли вперед, теперь идут назад
  for (int i = 90; i <= 110; i += 2) {
    servoA.write(i); // Зеркальное отображение: было 180-i, стало i
    B += 1;
    servoB.write(B);
    delay(5);

    servoC.write(180 - i); // Зеркальное отображение: было i, стало 180-i
    D += 1;
    servoD.write(D);
    delay(5);

    servoE.write(180 - i); // Зеркальное отображение: было i, стало 180-i
    F += 1;
    servoF.write(F);
    delay(5);

    servoG.write(i); // Зеркальное отображение: было 180-i, стало i
    H += 1;
    servoH.write(H);
    delay(5);
  }

  // Этап 2
  for (int i = 110; i <= 130; i += 2) {
    servoA.write(i); // Зеркальное отображение
    B -= 1;
    servoB.write(B);
    delay(5);

    servoC.write(180 - i); // Зеркальное отображение
    D -= 1;
    servoD.write(D);
    delay(5);

    servoE.write(180 - i); // Зеркальное отображение
    F -= 1;
    servoF.write(F);
    delay(5);

    servoG.write(i); // Зеркальное отображение
    H -= 1;
    servoH.write(H);
    delay(5);
  }

  // Этап 3
  for (int i = 130; i >= 110; i -= 2) {
    servoA.write(i); // Зеркальное отображение
    B -= 1;
    servoB.write(B);
    delay(5);

    servoC.write(180 - i); // Зеркальное отображение
    D -= 1;
    servoD.write(D);
    delay(5);

    servoE.write(180 - i); // Зеркальное отображение
    F -= 1;
    servoF.write(F);
    delay(5);

    servoG.write(i); // Зеркальное отображение
    H -= 1;
    servoH.write(H);
    delay(5);
  }

  // Этап 4
  for (int i = 110; i >= 90; i -= 2) {
    servoA.write(i); // Зеркальное отображение
    B += 1;
    servoB.write(B);
    delay(5);

    servoC.write(180 - i); // Зеркальное отображение
    D += 1;
    servoD.write(D);
    delay(5);

    servoE.write(180 - i); // Зеркальное отображение
    F += 1;
    servoF.write(F);
    delay(5);

    servoG.write(i); // Зеркальное отображение
    H += 1;
    servoH.write(H);
    delay(5);
  }
}
void forwardMirror() {//шаг вперед зеркально
  int B = 90;
  int D = 90;
  int F = 90;
  int H = 90;

  // Этап 1: Лапы, которые шли вперед, теперь идут назад
  for (int i = 90; i <= 110; i += 2) {
    servoA.write(180-i); // Зеркальное отображение: было 180-i, стало i
    B -= 1;
    servoB.write(B);
    delay(5);

    servoC.write(i); // Зеркальное отображение: было i, стало 180-i
    D -= 1;
    servoD.write(D);
    delay(5);

    servoE.write(i); // Зеркальное отображение: было i, стало 180-i
    F -= 1;
    servoF.write(F);
    delay(5);

    servoG.write(180-i); // Зеркальное отображение: было 180-i, стало i
    H -= 1;
    servoH.write(H);
    delay(5);
  }

  // Этап 2
  for (int i = 110; i <= 130; i += 2) {
    servoA.write(180-i); // Зеркальное отображение
    B += 1;
    servoB.write(B);
    delay(5);

    servoC.write(i); // Зеркальное отображение
    D += 1;
    servoD.write(D);
    delay(5);

    servoE.write(i); // Зеркальное отображение
    F += 1;
    servoF.write(F);
    delay(5);

    servoG.write(180-i); // Зеркальное отображение
    H += 1;
    servoH.write(H);
    delay(5);
  }

  // Этап 3
  for (int i = 130; i >= 110; i -= 2) {
    servoA.write(180-i); // Зеркальное отображение
    B += 1;
    servoB.write(B);
    delay(5);

    servoC.write(i); // Зеркальное отображение
    D += 1;
    servoD.write(D);
    delay(5);

    servoE.write(i); // Зеркальное отображение
    F += 1;
    servoF.write(F);
    delay(5);

    servoG.write(180-i); // Зеркальное отображение
    H += 1;
    servoH.write(H);
    delay(5);
  }

  // Этап 4
  for (int i = 110; i >= 90; i -= 2) {
    servoA.write(180-i); // Зеркальное отображение
    B -= 1;
    servoB.write(B);
    delay(5);

    servoC.write(i); // Зеркальное отображение
    D -= 1;
    servoD.write(D);
    delay(5);

    servoE.write(i); // Зеркальное отображение
    F -= 1;
    servoF.write(F);
    delay(5);

    servoG.write(180-i); // Зеркальное отображение
    H -= 1;
    servoH.write(H);
    delay(5);
  }
}
void left() {//налево на месте
  int B = 90;
  int D = 90;
  int F = 90;
  int H = 90;

  for (int i = 90; i <= 150; i += 4) {
    servoA.write(i); 
    B -= 2;
    servoB.write(B);
    delay(5);

    servoE.write(i); 
    F -= 2;
    servoF.write(F);
    delay(5);
  }
  for (int i = 90; i <= 150; i += 4) {
    B += 2;
    servoB.write(B);
    delay(5);

    F += 2;
    servoF.write(F);
    delay(5);
  }
  for (int i = 90; i <= 150; i += 4) {
    servoC.write(i); 
    D += 2;
    servoD.write(D);
    delay(5);

    servoG.write(i); 
    H += 2;
    servoH.write(H);
    delay(5);
  }
  for (int i = 90; i <= 150; i += 4) {
    D -= 2;
    servoD.write(D);
    delay(5);

    H -= 2;
    servoH.write(H);
    delay(5);
  }

  // Этап 2
  for (int i = 150; i >= 90; i -= 4) {
    servoA.write(i); 
    delay(5);

    servoC.write(i); 
    delay(5);

    servoE.write(i);
    delay(5);

    servoG.write(i); 
    delay(5);
  }

 
}
void right() {//направо на месте
  int B = 90;
  int D = 90;
  int F = 90;
  int H = 90;

  for (int i = 90; i <= 150; i += 4) {
    servoA.write(180-i); 
    B -= 2;
    servoB.write(B);
    delay(5);

    servoE.write(180-i); 
    F -= 2;
    servoF.write(F);
    delay(5);
  }
  for (int i = 90; i <= 150; i += 4) {
    B += 2;
    servoB.write(B);
    delay(5);

    F += 2;
    servoF.write(F);
    delay(5);
  }
  for (int i = 90; i <= 150; i += 4) {
    servoC.write(180-i); 
    D += 2;
    servoD.write(D);
    delay(5);

    servoG.write(180-i); 
    H += 2;
    servoH.write(H);
    delay(5);
  }
  for (int i = 90; i <= 150; i += 4) {
    D -= 2;
    servoD.write(D);
    delay(5);

    H -= 2;
    servoH.write(H);
    delay(5);
  }

  // Этап 2
  for (int i = 150; i >= 90; i -= 4) {
    servoA.write(180-i); 
    delay(5);

    servoC.write(180-i); 
    delay(5);

    servoE.write(180-i);
    delay(5);

    servoG.write(180-i); 
    delay(5);
  }

 
}

void right_line(){//боком вправо
  int B = 90;
  int D = 90;
  int F = 90;
  int H = 90;
  for(int i = 90; i <= 110; i+=2){
    servoA.write(i);
    B += 2;
    servoB.write(B);

    servoC.write(i);
    D += 2;
    servoD.write(D);
    
    servoE.write(180-i);
    F += 2;
    servoF.write(F);

    servoG.write(180-i);
    H += 2;
    servoH.write(H);
    delay(del*3);
  }
  for(int i = 110; i <= 130; i+=2){
    servoA.write(i);
    B -= 2;
    servoB.write(B);

    servoC.write(i);
    D -= 2;
    servoD.write(D);

    servoE.write(180-i);
    F -= 2;
    servoF.write(F);

    servoG.write(180-i);
    H -= 2;
    servoH.write(H);
    delay(del*3);
  }
  for(int i = 130; i >= 110; i-=2){
    servoA.write(i);
    B -= 2;
    servoB.write(B);

    servoC.write(i);
    D -= 2;
    servoD.write(D);

    servoE.write(180-i);
    F -= 2;
    servoF.write(F);

    servoG.write(180-i);
    H -= 2;
    servoH.write(H);
    delay(del*3);
  }
  for(int i = 110; i >= 90; i-=2){
    servoA.write(i);
    B += 2;
    servoB.write(B);

    servoC.write(i);
    D += 2;
    servoD.write(D);

    servoE.write(180-i);
    F += 2;
    servoF.write(F);

    servoG.write(180-i);
    H += 2;
    servoH.write(H);
    delay(del*3);
  }
}
void left_line(){//боком влево
  int B = 90;
  int D = 90;
  int F = 90;
  int H = 90;
  for(int i = 90; i <= 110; i+=2){
    servoA.write(i);
    B -= 2;
    servoB.write(B);

    servoC.write(i);
    D -= 2;
    servoD.write(D);
    
    servoE.write(180-i);
    F -= 2;
    servoF.write(F);

    servoG.write(180-i);
    H -= 2;
    servoH.write(H);
    delay(del*3);
  }
  for(int i = 110; i <= 130; i+=2){
    servoA.write(i);
    B += 2;
    servoB.write(B);

    servoC.write(i);
    D += 2;
    servoD.write(D);

    servoE.write(180-i);
    F += 2;
    servoF.write(F);

    servoG.write(180-i);
    H += 2;
    servoH.write(H);
    delay(del*3);
  }
  for(int i = 130; i >= 110; i-=2){
    servoA.write(i);
    B += 2;
    servoB.write(B);

    servoC.write(i);
    D += 2;
    servoD.write(D);

    servoE.write(180-i);
    F += 2;
    servoF.write(F);

    servoG.write(180-i);
    H += 2;
    servoH.write(H);
    delay(del*3);
  }
  for(int i = 110; i >= 90; i-=2){
    servoA.write(i);
    B -= 2;
    servoB.write(B);

    servoC.write(i);
    D -= 2;
    servoD.write(D);

    servoE.write(180-i);
    F -= 2;
    servoF.write(F);

    servoG.write(180-i);
    H -= 2;
    servoH.write(H);
    delay(del*3);
  }
}

void lunging_side(){//выпады в сторону
  for(int i = 90; i >= 30; i-=2){
      servoA.write(180-i);
      servoC.write(i);
      servoE.write(180-i);
      servoG.write(i);
      delay(del);
  }  
  for(int j = 0; j < 10; j++){
    for(int i = 90; i >= 30; i-=2){
      servoB.write(180-i);
      servoD.write(i);
      servoF.write(i);
      servoH.write(180-i);
      delay(del*3);
    }  
    for(int i = 30; i <= 150; i+=2){
      servoB.write(180-i);
      servoD.write(i);
      servoF.write(i);
      servoH.write(180-i);
      delay(del*3);
    } 
    for(int i = 150; i >= 90; i-=2){
      servoB.write(180-i);
      servoD.write(i);
      servoF.write(i);
      servoH.write(180-i);
      delay(del*3);
    }   
  }
  for(int i = 30; i <= 90; i+=2){
      servoA.write(i);
      servoC.write(180-i);
      servoE.write(i);
      servoG.write(180-i);
      delay(del);
  }

}
void workout_sides(){//тренировка в стороны
  for(int i = 90; i >= 30; i-=2){
      servoA.write(180-i);
      servoC.write(i);
      servoE.write(180-i);
      servoG.write(i);
      delay(20);
  }  
  for(int j = 0; j < 2; j++){
    for(int i = 90; i >= 30; i-=2){
      servoB.write(180-i);
      servoD.write(i);
      servoF.write(i);
      servoH.write(180-i);
      delay(20);
    }  
    for(int i = 30; i <= 50; i+=2){
      servoB.write(180-i);
      servoD.write(i);
      servoF.write(i);
      servoH.write(180-i);
      delay(20);
    } 
    for(int i = 50; i >= 30; i-=2){
      servoB.write(180-i);
      servoD.write(i);
      servoF.write(i);
      servoH.write(180-i);
      delay(20);
    }
    for(int i = 30; i <= 150; i+=2){
      servoB.write(180-i);
      servoD.write(i);
      servoF.write(i);
      servoH.write(180-i);
      delay(20);
    }
    for(int i = 150; i >= 130; i-=2){
      servoB.write(180-i);
      servoD.write(i);
      servoF.write(i);
      servoH.write(180-i);
      delay(20);
    }
    for(int i = 130; i <= 150; i+=2){
      servoB.write(180-i);
      servoD.write(i);
      servoF.write(i);
      servoH.write(180-i);
      delay(20);
    } 
    for(int i = 150; i >= 90; i-=2){
      servoB.write(180-i);
      servoD.write(i);
      servoF.write(i);
      servoH.write(180-i);
      delay(20);
    }   
  }
  for(int i = 30; i <= 90; i+=2){
      servoA.write(180-i);
      servoC.write(i);
      servoE.write(180-i);
      servoG.write(i);
      delay(20);
  } 

}
void workout_forward(){//выпады вперед-назад
  for(int i = 90; i >= 30; i-=2){
      servoA.write(i);
      servoC.write(180-i);
      servoE.write(i);
      servoG.write(180-i);
      delay(20);
  }  
  for(int j = 0; j < 2; j++){
    for(int i = 90; i >= 30; i-=2){
      servoB.write(180-i);
      servoD.write(180-i);
      servoF.write(i);
      servoH.write(i);
      delay(20);
    }  
    for(int i = 30; i <= 50; i+=2){
      servoB.write(180-i);
      servoD.write(180-i);
      servoF.write(i);
      servoH.write(i);
      delay(20);
    } 
    for(int i = 50; i >= 30; i-=2){
      servoB.write(180-i);
      servoD.write(180-i);
      servoF.write(i);
      servoH.write(i);
      delay(20);
    }
    for(int i = 30; i <= 150; i+=2){
      servoB.write(180-i);
      servoD.write(180-i);
      servoF.write(i);
      servoH.write(i);
      delay(20);
    }
    for(int i = 150; i >= 130; i-=2){
      servoB.write(180-i);
      servoD.write(180-i);
      servoF.write(i);
      servoH.write(i);
      delay(20);
    }
    for(int i = 130; i <= 150; i+=2){
      servoB.write(180-i);
      servoD.write(180-i);
      servoF.write(i);
      servoH.write(i);
      delay(20);
    } 
    for(int i = 150; i >= 90; i-=2){
      servoB.write(180-i);
      servoD.write(180-i);
      servoF.write(i);
      servoH.write(i);
      delay(20);
    }   
  }
  for(int i = 30; i <= 90; i+=2){
      servoA.write(i);
      servoC.write(180-i);
      servoE.write(i);
      servoG.write(180-i);
      delay(20);
  } 

}

#endif