#include <CapacitiveSensor.h>
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;

// defines variables
long duration;
int distance;

//define sensors
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

// define sensor values
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

// frequency for ultrasonic (theremin mode)
int frequency = 110; // A1

//define notes
int Aone = 55;
int Asharpone = 58;
int Bone = 62;
int Cone = 65;
int Csharpone = 69;
int Done = 73;
int Dsharpone = 78;
int Eone = 82;
int Fone = 87;
int Fsharpone = 93;
int Gone = 98;
int Gsharpone = 104;

// potentiometer
int potPin = A3; // Potentiometer output connected to analog pin 3
int potVal = 0; // Variable to store the input from the potentiometer

// defining starting notes
int pad1 = 440;
int pad2 = 466;
int pad3 = 494;
int pad4 = 523;
int pad5 = 554;
int pad6 = 587;
int pad7 = 622;
int pad8 = 659;
int pad9 = 698;
int pad10 = 740;
int pad11 = 784;
int pad12 = 831;
int pad13 = (pad1*2);
int pad14 = (pad2*2);
int pad15 = (pad3*2);
int pad16 = (pad4*2);

// which button was clicked
int pad;
int buttonState = 0;  // variable for reading the pushbutton status

// defining input & output
const int button = 2;
#define buzzer 21 

void ultrasonic() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
}

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(button, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(button) == HIGH) {
    buttonState = buttonState + 1;
    if (buttonState > 2) {
      buttonState = 0;
    }
  }
  capactivesensors();
  if (buttonState == 1) {
    potVal = analogRead(potPin);
    potVal = map(potVal,0,1023,2,7);
    pad1 = (Aone*pow(2,(potVal-1)));
    pad2 = (Asharpone*pow(2,(potVal-1)));
    pad3 = (Bone*pow(2,(potVal-1)));
    pad4 = (Cone*pow(2,(potVal-1)));
    pad5 = (Csharpone*pow(2,(potVal-1)));
    pad6 = (Done*pow(2,(potVal-1)));
    pad7 = (Dsharpone*pow(2,(potVal-1)));
    pad8 = (Eone*pow(2,(potVal-1)));
    pad9 = (Fone*pow(2,(potVal-1)));
    pad10 = (Fsharpone*pow(2,(potVal-1)));
    pad11 = (Gone*pow(2,(potVal-1)));
    pad12 = (Gsharpone*pow(2,(potVal-1)));
    pad13 = (pad1*2);
    pad14 = (pad2*2);
    pad15 = (pad3*2);
    pad16 = (pad4*2);
    tone(buzzer,pad1);
  } else if (buttonState == 2) {
    ultrasonic();
    if (distance < 400 && distance > 0) {
      frequency = map(distance,400,0,110,1320); // A1 --> A6 - closer (cm) = higher pitch
      pad1 = (frequency + pad1);
      pad2 = (frequency + pad2);
      pad3 = (frequency + pad3);
      pad4 = (frequency + pad4);
      pad5 = (frequency + pad5);
      pad6 = (frequency + pad6);
      pad7 = (frequency + pad7);
      pad8 = (frequency + pad8);
      pad9 = (frequency + pad9);
      pad10 = (frequency + pad10);
      pad11 = (frequency + pad11);
      pad12 = (frequency + pad12);
      pad13 = (pad1*2);
      pad14 = (pad2*2);
      pad15 = (pad3*2);
      pad16 = (pad4*2);
    }
    tone(buzzer,pad1);
  } else {
    switch (pad) {
      case 1:
        tone(buzzer,pad1,1000);
        break;
      case 2:
        tone(buzzer,pad2,1000);
        break;
      case 3:
        tone(buzzer,pad3,1000);
        break;
      case 4:
        tone(buzzer,pad4,1000);
        break;
      case 5:
        tone(buzzer,pad5,1000);
        break;
      case 6:
        tone(buzzer,pad6,1000);
        break;
      case 7:
        tone(buzzer,pad7,1000);
        break;
      case 8:
        tone(buzzer,pad8,1000);
        break;
      case 9:
        tone(buzzer,pad9,1000);
        break;
      case 10:
        tone(buzzer,pad10,1000);
        break;
      case 11:
        tone(buzzer,pad11,1000);
        break;
      case 12:
        tone(buzzer,pad12,1000);
        break;
      case 13:
        tone(buzzer,pad13,1000);
        break;
      case 14:
        tone(buzzer,pad14,1000);
        break;
      case 15:
        tone(buzzer,pad15,1000);
        break;
      case 16:
        tone(buzzer,pad16,1000);
        break;
    }
  }
}

void capactivesensors() {
  val1 = Sensor1.capacitiveSensor(30);
  val2 = Sensor2.capacitiveSensor(30);
  val3 = Sensor3.capacitiveSensor(30);
  val4 = Sensor4.capacitiveSensor(30);
  val5 = Sensor5.capacitiveSensor(30);
  val6 = Sensor6.capacitiveSensor(30);
  val7 = Sensor7.capacitiveSensor(30);
  val8 = Sensor8.capacitiveSensor(30);
  val9 = Sensor9.capacitiveSensor(30);
  val10 = Sensor10.capacitiveSensor(30);
  val11 = Sensor11.capacitiveSensor(30);
  val12 = Sensor12.capacitiveSensor(30);
  val13 = Sensor13.capacitiveSensor(30);
  val14 = Sensor14.capacitiveSensor(30);
  val15 = Sensor15.capacitiveSensor(30);
  val16 = Sensor16.capacitiveSensor(30);
  
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
}