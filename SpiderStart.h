#ifndef Start
#define Start
#include "SpiderConsts.h"
#include <Arduino.h>
#include <Wire.h>

/*
Библиотека
hello() - приветствие
center_servos() - исходное положение (углы по 90 градусов)
rgb(r, g, b) - /передача показателей цвета r,g,b на светодиоды
rainbow() - перелив цветов от красного к фиолетовому по кругу
sonarDistance() - измерение расстояния ультразвуком
song() - мелодия
bye() - прощание
*/
void center_servos() {//исходное положение (все сервоприводы на 90 градусов)
  servoA.write(90);
  servoB.write(90);
  servoC.write(90);
  servoD.write(90);
  servoE.write(90);
  servoF.write(90);
  servoG.write(90);
  servoH.write(90);
}
void hello(){ //приветствие
  for(int i = 90; i >= 45; i-=2){//две диагональные лапки чуть вперед для равновесия
    servoC.write(i);
    servoF.write(i);
    //servoG.write(180-i);
    delay(del*2);
  }
  delay(1000);
  for(int i = 90; i >= 0; i-=2){//лапка для приветствия поднимается
    servoB.write(i);
    delay(del);
  }
  for(int j = 0; j < 3; j++){//машем
    for(int i = 90; i >= 60; i-=2){
      servoA.write(i);
      delay(del);
    }
    for(int i = 60; i <= 120; i+=2){
      servoA.write(i);
      delay(del);
    }
    for(int i = 120; i >= 90; i-=2){
      servoA.write(i);
      delay(del);
    }
  }
  for(int i = 0; i <= 90; i+=2){//лапку для приветствия опускаем
    servoB.write(i);
    delay(del);
  }
  for(int i = 45; i <= 90; i+=2){//две диагональные лапки на место
    servoC.write(i);
    servoF.write(i);
    //servoG.write(180-i);
    delay(del*2);
  }
  delay(1000);

}
void song(){//мелодия
  for(int i = 0; i <= sizeof(notes); i++){
    tone(TONE_PIN, notes[i], durations[i]);
    delay(pauses[i]);
  }
}
void rgb(int r, int g, int b){//передача показателей цвета r,g,b на светодиоды
  analogWrite(blueLED, b);//отдельно на синий
  analogWrite(greenLED, g);//зеленый
  analogWrite(redLED, r);//красный
}
void rainbow(){//перелив цветов (радуга)
  rgb(255, 0, 0);//красный
  delay(100);
  for(int i = 0; i <= 255; i+=5){//оранжевый, желтый
    rgb(255, i, 0);
    delay(100);
  }
  for(int i = 255; i >= 0; i-=25){//зеленый
    rgb(i, 255, 0);
    delay(100);
  }
  for(int i = 0; i <= 255; i+=15){//голубой
    rgb(0, 255, i);
    delay(100);
  }
  for(int i = 255; i >= 0; i-=15){//синий
    rgb(0, i, 255);
    delay(100);
  }
  for(int i = 0; i <= 255; i+=15){//фиолетовый
    rgb(i, 0, 255);
    delay(100);
  }
  for(int i = 255; i >= 0; i-=15){//красный
    rgb(255, 0, i);
    delay(100);
  }
}
void sonarDistance(){//измерение расстояния ультразвуком
  //считываем расстояние 
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  delay(1);

  long distance = pulseIn(PIN_ECHO, HIGH) / 58;
  Serial.println(distance);

}
void bye(){ //прощание
  for(int i = 90; i >= 45; i-=2){
    servoC.write(i);
    servoF.write(i);
    //servoG.write(180-i);
    delay(del*2);
  }
  delay(1000);
  for(int j = 0; j < 3; j++){
    for(int i = 90; i >= 0; i-=2){
      servoB.write(i);
      delay(del);
    }
    for(int i = 0; i <= 90; i+=2){
      servoB.write(i);
      delay(del);
    }
  }  
  for(int i = 45; i <= 90; i+=2){
    servoC.write(i);
    servoF.write(i);
    //servoG.write(180-i);
    delay(del*2);
  }
  delay(1000);

 
}


#endif