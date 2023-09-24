#include <buildTime.h>
#include <microDS3231.h>

/*
Sketch for MetroWatch

20.09.2023

Alexander Livanov | INDEPCODE
*/

int D1 = A0;
int D2 = A1;
int D3 = A2;
int D4 = A3;

int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;

MicroDS3231 rtc;

void setup() {
  Serial.begin(9600);

  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);

  //rtc.setTime(COMPILE_TIME);

  DateTime now = rtc.getTime();
  rtc.setTime(now);

  uploading();
}

void loop() {
  DateTime now = rtc.getTime();

  Serial.print(now.hour);
  Serial.print(" ");
  Serial.println(now.minute);

  // auto hours = rtc.getHours();
  // int h1 = String(hours)[0];
  // int h2 = String(hours)[1];

  // auto minutes = rtc.getMinutes();
  // int m1 = String(minutes)[0];
  // int m2 = String(minutes)[1];
  int h1 = String(now.hour)[0];
  int h2 = String(now.hour)[1];
  int m1 = String(now.minute)[0];
  int m2 = String(now.minute)[1];
  if(now.minute < 10){
    int m1 = 0;
    int m2 = String(now.minute)[1];
  }else if(now.minute >= 10 and now.minute < 60){
    int m1 = String(now.minute)[0];
    int m2 = String(now.minute)[1];
  }

  digit1();whichNum(h1);delay(5);
  digit2();whichNum(h2);delay(5);
  digit3();whichNum(m1);delay(5);
  digit4();whichNum(m2);delay(5);
}

void whichNum(int number){
  switch(number){
    case 48:
      zero();
      break;
    case 49:
      one();
      break;
    case 50:
      two();
      break;
    case 51:
      three();
      break;
    case 52:
      four();
      break;
    case 53:
      five();
      break;
    case 54:
      six();
      break;
    case 55:
      seven();
      break;
    case 56:
      eight();
      break;
    case 57:
      nine();
      break;
    default:
      uploading();
      break;
  }
}

void zero() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}

void one() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void two() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}

void three() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}

void four() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void five() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void six() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void seven() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void eight() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void nine() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void uploading() {
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
  delay(300);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
  delay(300);
}


//functions to select individual digits on the display
void digit1() {
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
}

void digit2() {
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
}

void digit3() {
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH);
}

void digit4() {
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW);
}

void all4Digits() {
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
}
