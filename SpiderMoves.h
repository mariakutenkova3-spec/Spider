#ifndef Moves
#define Moves
#include "SpiderConsts.h"
#include "SpiderStart.h"
#include "SpiderPrimeMoves.h"
#include <Arduino.h>

/*
Библиотека
go_by_hand() - движение за рукой по ультразвуку
lunging_sideNonBlocking() - выпады вправо-влево (танец) без delay
danceNonBlocking() - мелодия+свет без delay
*/

void go_by_hand(){//движение за рукой по ультразвуку
  int rasst =  0;
  for(int i = 0; i < 5; i++){//считываем расстояние 5 раз
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  delay(1);

  long duration = pulseIn(PIN_ECHO, HIGH) / 58;
  rasst += duration; 
    delay(1);
  }
  rasst /= 5;//берем среднее  для большей точности
  if (rasst > 10) forward(); else back();//если расстояние больле 10, шаг вперед. Иначе - шаг назад
  

}

//Переменные для lunging_sideNonBlocking
unsigned long previousMillisLunging = 0;
int phase = 0;  // фаза движения: 0- первый цикл i=90..30, 1- цикл j.. и т.д.
int i = 90;
int j = 0;
int subPhase = 0;

void lunging_sideNonBlocking() {//выпады вправо-влево (танец) без delay
  unsigned long currentMillis = millis();

  if (phase == 0) { 
    if (currentMillis - previousMillisLunging >= del) {
      previousMillisLunging = currentMillis;
      servoA.write(180 - i);
      servoC.write(i);
      servoE.write(180 - i);
      servoG.write(i);
      i -= 2;
      if (i < 30) {
        i = 90;
        phase = 1;
        j = 0;
        subPhase = 0;
      }
    }
  }
  else if (phase == 1) {
    if (j < 100) {
      if (currentMillis - previousMillisLunging >= del * 1.2) {
        previousMillisLunging = currentMillis;
        if (subPhase == 0) {
          servoB.write(180 - i);
          servoD.write(i);
          servoF.write(i);
          servoH.write(180 - i);
          i -= 2;
          if (i < 30) {
            i = 30;
            subPhase = 1;
          }
        }
        else if (subPhase == 1) {
          servoB.write(180 - i);
          servoD.write(i);
          servoF.write(i);
          servoH.write(180 - i);
          i += 2;
          if (i > 150) {
            i = 150;
            subPhase = 2;
          }
        }
        else if (subPhase == 2) {
          servoB.write(180 - i);
          servoD.write(i);
          servoF.write(i);
          servoH.write(180 - i);
          i -= 2;
          if (i < 90) {
            i = 90;
            j++;
            subPhase = 0;
          }
        }
      }
    } 
    else {
      phase = 2;
      i = 30;
    }
  }
  else if (phase == 2) {
    if (currentMillis - previousMillisLunging >= del) {
      previousMillisLunging = currentMillis;
      servoA.write(i);
      servoC.write(180 - i);
      servoE.write(i);
      servoG.write(180 - i);
      i += 2;
      if (i > 90) {
        phase = 3; // Конец движения
      }
    }
  }
  else if (phase == 3) {
    // Движение завершено, можно что-то сделать или повторить
  }
}

//Переменные для danceNonBlocking
unsigned long  previousMillis = 0;
int step = 0;
bool notePlaying = false;
int color = 0;

void danceNonBlocking() {//мелодия+свет без delay
  int currentMillis = millis();

  if (step >= sizeof(notes) / sizeof(notes[0])) {
    step = 0; // повторяем мелодию
  }

  if (!notePlaying) {
    // Запускаем ноту
    tone(TONE_PIN, notes[step]);
    rgb(colors[color][0], colors[color][1], colors[color][2]);
    previousMillis = currentMillis;
    notePlaying = true;
  } else {
    // Проверяем, не прошло ли время звучания ноты
    if (currentMillis - previousMillis >= durations[step]*1.5) {
      noTone(TONE_PIN); // остановить звук
      rgb(0, 0, 0);
      color += 1;
      color %= 10;
      previousMillis = currentMillis;
      notePlaying = false;
      step++;
      // Здесь пауза между нотами за счет этого состояния и условия в начале функции
      // Пауза длится пока notePlaying == false
    }
  }
}

#endif