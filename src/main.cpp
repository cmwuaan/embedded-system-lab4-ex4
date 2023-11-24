#include <Arduino.h>

#define trigPin 2
#define echoPin 3

byte ledPins[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
byte pinCount;
unsigned long duration = 0;
int distance = 0;
int distanceMax = 100;

int getDistance();

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinCount = sizeof(ledPins);
  for (int i = 0; i < pinCount; i++)
  {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
  distance = getDistance();
  delay(10);
  Serial.println(distance);
  for (int i = 0; i < pinCount; i++)
  {
    digitalWrite(ledPins[i], LOW);
  }

  int ledIndex = map(distance, 1, distanceMax, 0, pinCount);
  // Serial.println(ledIndex);
  for (int i = ledIndex; i < pinCount; i++)
  {
    digitalWrite(ledPins[i], HIGH);
  }
}
