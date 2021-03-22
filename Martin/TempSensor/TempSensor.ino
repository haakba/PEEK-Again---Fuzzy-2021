int analogPin = A0;
float analogVal= 0;
float averageTemp = 0;
int measureToAverage = 50;
int counter = 0;
int relayPin = 7;
void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  pinMode(analogPin, INPUT);
  Serial.print("Average ");
}

void loop() {
  for(int i=0; i < measureToAverage; i++) {
    analogVal = analogRead(analogPin)*0.15;
    averageTemp += analogVal;
    delay(1);
  }
  averageTemp /= measureToAverage;
  Serial.print(averageTemp);
  Serial.print(" ");
  Serial.print(analogVal);
  Serial.print("\n");

  if (averageTemp > 24) {
      digitalWrite(relayPin, HIGH); 
   }
   else {
      digitalWrite(relayPin, LOW);
   }
}
