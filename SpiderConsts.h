#ifndef Consts
#define Consts
//Задержка
int del = 10;

//Пьезодинамик
#define TONE_PIN 13 
//Ультразвук
#define PIN_TRIG A0
#define PIN_ECHO A1
//Светодиоды
#define blueLED 12
#define greenLED 11
#define redLED 10
//Сервоприводы
Servo servoA;  
Servo servoB;
Servo servoC;
Servo servoD;
Servo servoE;
Servo servoF;
Servo servoG;
Servo servoH;
//Массивы для мелодии
const int notes[] =     {164, 261, 220, 220, 164, 164, 246, 195, 195, 164, 164, 246, 195, 195, 146, 146, 184, 184, 195};
const int durations[] = {216, 216, 216, 108, 216, 108, 216, 216, 108, 216, 108, 216, 216, 108, 216, 216, 216, 108, 216};
const int pauses[] =    {240, 240, 240, 120, 240, 120, 240, 240, 120, 240, 120, 240, 240, 120, 240, 240, 240, 120, 240};
const int noteCount = sizeof(notes) / sizeof(notes[0]);
//Массив для цветов
const int colors[][3] = {
  {255, 0, 0},
  {0, 255, 0},
  {0, 0, 255},
  {255, 255, 0},
  {0, 255, 255},
  {255, 0, 255},
  {255, 128, 0},
  {128, 0, 255},
  {128, 128, 128},
  {255, 255, 255}
};
#endif