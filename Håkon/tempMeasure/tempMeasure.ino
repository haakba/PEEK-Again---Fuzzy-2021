#include "functions.h"
int tempPin = A0;
int tempPinReading = 0;
float tempVolt = 0;
float tempValue = 0;

void setup() {
   pinMode(tempPin, INPUT);  //set tempPin to be an input
   //pinMode(LED, OUTPUT); 
   Serial.begin(9600); 

}

void loop() { 
  tempPinReading = analogRead(tempPin); //mV
  tempVolt = tempPinReading * 5.0;
  tempVolt /= 1024;
  Serial.print(tempVolt); Serial.print(" volts");
  Serial.print("\t");
  
  tempValue = calculateTemp(tempVolt);
  
  Serial.print(tempValue); Serial.println(" degrees C");
  //calculateTemp(tempPin);
  
  reactOnTemp(tempValue);
  delay(1000);
  // put your main code here, to run repeatedly:

}
