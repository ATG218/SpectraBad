#include <CapacitiveSensor.h>
CapacitiveSensor Sensor1 = CapacitiveSensor(4, 5);
CapacitiveSensor Sensor2 = CapacitiveSensor(4, 6);
CapacitiveSensor Sensor3 = CapacitiveSensor(4, 7);
CapacitiveSensor Sensor4 = CapacitiveSensor(4, 8);
CapacitiveSensor Sensor5 = CapacitiveSensor(4, 9);
CapacitiveSensor Sensor6 = CapacitiveSensor(4, 10);
CapacitiveSensor Sensor7 = CapacitiveSensor(4, 11);
CapacitiveSensor Sensor8 = CapacitiveSensor(4, 12);
CapacitiveSensor Sensor9 = CapacitiveSensor(4, 13);
CapacitiveSensor Sensor10 = CapacitiveSensor(4, 14);
CapacitiveSensor Sensor11 = CapacitiveSensor(4, 15);
CapacitiveSensor Sensor12 = CapacitiveSensor(4, 16);
CapacitiveSensor Sensor13 = CapacitiveSensor(4, 17);
CapacitiveSensor Sensor14 = CapacitiveSensor(4, 18);
CapacitiveSensor Sensor15 = CapacitiveSensor(4, 19);
CapacitiveSensor Sensor16 = CapacitiveSensor(4, 20);

long val1;
long val2;
long val3;
long val4;
long val5;
long val6;
long val7;
long val8;
long val9;
long val10;
long val11;
long val12;
long val13;
long val14;
long val15;
long val16;

int A = 440;
int Bflat = 466;
int B = 494;
int C = 523;
int Csharp = 554;
int D = 587;
int Eflat = 622;
int E = 659;
int F = 698;
int Fsharp = 740;
int G = 784;
int Gsharp = 831;
int A2 = (A*2);
int Bflat2 = (Bflat*2);
int B2 = (B*2);
int C2 = (C*2);

int pad;

#define buzzer 21; // idk if the buzzer is analog or digital ngl

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if (val1 >= 1000) { pad = 1;}
  if (val2 >= 1000) { pad = 2;}
  if (val3 >= 1000) { pad = 3;}
  if (val4 >= 1000) { pad = 4;}
  if (val5 >= 1000) { pad = 5;}
  if (val6 >= 1000) { pad = 6;}
  if (val7 >= 1000) { pad = 7;}
  if (val8 >= 1000) { pad = 8;}
  if (val9 >= 1000) { pad = 9;}
  if (val10 >= 1000) { pad = 10;}
  if (val11 >= 1000) { pad = 11;}
  if (val12 >= 1000) { pad = 12;}
  if (val13 >= 1000) { pad = 13;}
  if (val14 >= 1000) { pad = 14;}
  if (val15 >= 1000) { pad = 15;}
  if (val16 >= 1000) { pad = 16;}

  switch (pad) {
    case 1:
      tone(buzzer,A,1000);
      break;
    case 2:
      tone(buzzer,Bflat,1000);
      break;
    case 3:
      tone(buzzer,B,1000);
      break;
    case 4:
      tone(buzzer,C,1000);
      break;
    case 5:
      tone(buzzer,Csharp,1000);
      break;
    case 6:
      tone(buzzer,D,1000);
      break;
    case 7:
      tone(buzzer,Eflat,1000);
      break;
    case 8:
      tone(buzzer,E,1000);
      break;
    case 9:
      tone(buzzer,F,1000);
      break;
    case 10:
      tone(buzzer,Fsharp,1000);
      break;
    case 11:
      tone(buzzer,G,1000);
      break;
    case 12:
      tone(buzzer,Gsharp,1000);
      break;
    case 13:
      tone(buzzer,A2,1000);
      break;
    case 14:
      tone(buzzer,Bflat2,1000);
      break;
    case 15:
      tone(buzzer,B2,1000);
      break;
    case 16:
      tone(buzzer,C2,1000);
      break;
  }
}