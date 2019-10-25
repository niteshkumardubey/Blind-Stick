#include <SoftwareSerial.h>
#include <ArduinoJson.h>
#include "MyFunctions.h"

void setup() {
  pinMode(MQ2, INPUT);
  pinMode(LM35, INPUT);
  pinMode(RCWL, INPUT);
  pinMode(Cu_Strip, INPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(motor, OUTPUT);

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
//   _MQ2();
//   delay(100);
//   _LM35();
//   delay(100);
//   _RCWL();
//   delay(100);
//   _Cu_Strip();
//   delay(100);
//   _HCSR04();
//   delay(100);
//   _Send_String();
//   delay(100);
   _Send_JSON();
   delay(100);
}
