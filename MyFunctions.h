#include "Initialisations.h"

void _MQ2()
{
  MQ2_Val = analogRead(MQ2);
  Serial.print("Gas sensor value: ");
  Serial.println(MQ2_Val);
  if(MQ2_Val > 300)
    {
      Serial.println("Smoke around you detected");
    }
  }

  void _LM35()
  {
    LM35_Val = analogRead(LM35);
    Serial.print("Temperature value: ");
    float mV = ( LM35_Val/1024.0)*5000;
    float Temp_Val = mV/10;
    Serial.println(Temp_Val);
    if(Temp_Val > 40)
    {
      Serial.println("High Temperature around you detected. Something might be burning.");
      }
      else;
    }

void _RCWL()
{
    RCWL_Val = digitalRead(RCWL);
    Serial.print("RCWL Status: ");
    Serial.println(RCWL_Val);
    if(RCWL_Val > 0   )
    {
      digitalWrite(motor, HIGH);
      Serial.println("Some moving object detected.");
      }
      else
      {
        digitalWrite(motor, LOW);
        }
   }

void _Cu_Strip()
{
  Cu_Strip_Val = digitalRead(Cu_Strip);
  Serial.print("Copper Strip Status: ");
  Serial.println(Cu_Strip_Val);
  if(Cu_Strip_Val == HIGH)
    {
      digitalWrite(motor, HIGH);
      Serial.println("Pit or mud in your way.");
      }
      else
      {
        digitalWrite(motor, LOW);
        }
  }

void _HCSR04()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
  }
  
void _Send_JSON()
{
  StaticJsonDocument<200> doc;
  a = digitalRead(Cu_Strip);
  b = digitalRead(RCWL);
  c = analogRead(LM35);
  d = analogRead(MQ2);

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  e = pulseIn(echoPin, HIGH);
  f = (e*.0343)/2;
  
  doc["MQ2_Val"] = d;
  doc["LM35_Val"] = c;
  doc["RCWL_Val"] = b;
  doc["Cu_Strip_Val"] = a;
  doc["Distance"] = f;

  Serial.println();
  
  serializeJsonPretty(doc, Serial);

  Serial.println();
  }

void _Send_String()
{
  string1 = String("Cu_Strip:");
  string2 = String("RCWL_Status:");
  string3 = String("LM35_Status:");
  string4 = String("MQ2_Status:");
  string5 = String("Distance:");
  
  a = digitalRead(Cu_Strip);
  b = digitalRead(RCWL);
  c = analogRead(LM35);
  d = analogRead(MQ2);

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  e = pulseIn(echoPin, HIGH);
  f = (e*.0343)/2;

  w = string1 + a;
  x = string2 + b;
  y = string3 + c;
  z = string4 + d;
  z1 = string5 + f;

  string6 = '@'+w+','+x+','+y+','+z+','+z1+'#';
  Serial.println(string6);
  }
