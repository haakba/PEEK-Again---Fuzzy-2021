#include "functions.h"
int LEDPin = 7;
float calculateTemp(float temp) {
  return (temp - 0.5) * 100;
}

void reactOnTemp(float temp) {
  if (temp < 20) {
    Serial.print("Need to increase temp. Turn on ");
    digitalWrite(LEDPin,LOW);
  }
  else if (temp >25) {
    Serial.print("Need to decrease temp. Turn off ");
    digitalWrite(LEDPin,HIGH); 
  }
  else {
    Serial.print("Normal condition. LED off ");
    digitalWrite(LEDPin,LOW); 
  }
}
