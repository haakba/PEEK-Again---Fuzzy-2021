#include "utilities.h"


bool trigger = false;

//unsigned long previousTime = 0;


long onTime = 3000;
long offTime = 5000;

unsigned long onTimestamp = 0;
long offTimestamp = -offTime;


void reactOnTemp(double temperature, double maxTemp) {

  if(!trigger && temperature<175 && (millis() - offTimestamp) >= offTime)
  {
    trigger = true;
    onTimestamp = millis();
    MConOFF("ON");
  }
  else if((temperature>=maxTemp) || (trigger && (millis() - onTimestamp) >= onTime))
  {
    trigger = false;
    offTimestamp = millis();
    MConOFF("OFF");
  }  
}


void MConOFF(String set) {
  if (set == "ON") {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 255);
  }
  if (set == "OFF") {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enA, 0);
  }
}
