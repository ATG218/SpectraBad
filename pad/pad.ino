#include <CapacitiveSensor.h>
#include <map>
#include <string>
#include <NewPing.h>

#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define MAX_DISTANCE 400 // Maximum distance we want to measure (in centimeters).

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
std::map<std::string, int> noteFrequencies = {
    {"A", 440},
    {"A#", 466},
    {"B", 494},
    {"C", 523},
    {"C#", 554},
    {"D", 587},
    {"D#", 622},
    {"E", 659},
    {"F", 698},
    {"F#", 740},
    {"G", 784},
    {"G#", 831}
};

std::map<std::string, int> noteFrequenciesA1 = {
    {"A1", 55},
    {"A#1", 58},
    {"B1", 62},
    {"C1", 65},
    {"C#1", 69},
    {"D1", 73},
    {"D#1", 78},
    {"E1", 82},
    {"F1", 87},
    {"F#1", 93},
    {"G1", 98},
    {"G#1", 104}
};

// potentiometer
int potPin = A3; // Potentiometer output connected to analog pin 3
int potVal = 0; // Variable to store the input from the potentiometer

// defining starting notes
int pad1 = noteFrequencies["A"];
int pad2 = noteFrequencies["A#"];
int pad3 = noteFrequencies["B"];
int pad4 = noteFrequencies["C"];
int pad5 = noteFrequencies["C#"];
int pad6 = noteFrequencies["D"];
int pad7 = noteFrequencies["D#"];
int pad8 = noteFrequencies["E"];
int pad9 = noteFrequencies["F"];
int pad10 = noteFrequencies["F#"];
int pad11 = noteFrequencies["G"];
int pad12 = noteFrequencies["G#"];
int pad13 = (noteFrequencies["A"]*2);
int pad14 = (noteFrequencies["A#"]*2);
int pad15 = (noteFrequencies["B"]*2);
int pad16 = (noteFrequencies["C"]*2);

// which button was clicked
int pad;
int buttonState = 0;  // variable for reading the pushbutton status

// defining input & output
const int buttonPin = 2;
#define buzzer 21 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void ultrasonic() {
  delay(50);
  int distance = sonar.ping_cm();
}

void setup() {
  pinMode(button, INPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    buttonState = buttonState + 1;
    if (buttonState > 2) {
      buttonState = 0;
    }
  }
  capactivesensors();
  if (buttonstate == 1) {
    potVal = analogRead(potPin);
    potVal = map(potVal,0,1023,2,7);
    pad1 = (noteFrequenciesA1["A1"]*pow(2,(potVal-1)));
    pad2 = (noteFrequenciesA1["A#1"]*pow(2,(potVal-1)));
    pad3 = (noteFrequenciesA1["B1"]*pow(2,(potVal-1)));
    pad4 = (noteFrequenciesA1["C1"]*pow(2,(potVal-1)));
    pad5 = (noteFrequenciesA1["C#1"]*pow(2,(potVal-1)));
    pad6 = (noteFrequenciesA1["D1"]*pow(2,(potVal-1)));
    pad7 = (noteFrequenciesA1["D#1"]*pow(2,(potVal-1)));
    pad8 = (noteFrequenciesA1["E1"]*pow(2,(potVal-1)));
    pad9 = (noteFrequenciesA1["F1"]*pow(2,(potVal-1)));
    pad10 = (noteFrequenciesA1["F#1"]*pow(2,(potVal-1)));
    pad11 = (noteFrequenciesA1["G1"]*pow(2,(potVal-1)));
    pad12 = (noteFrequenciesA1["G#1"]*pow(2,(potVal-1)));
    pad13 = (pad1*2);
    pad14 = (pad2*2);
    pad15 = (pad3*2);
    pad16 = (pad4*2);
    tone(buzzer,pad1);
  } else if (buttonstate == 2) {
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