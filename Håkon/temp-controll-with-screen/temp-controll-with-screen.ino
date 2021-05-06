/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

#include <Wire.h> // A4 = SDA, A5 = SCL
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// r- vin, g-3v0,black-gnd,y-do,white-cs,blue-clk
#include <SPI.h>
#include "Adafruit_MAX31855.h"

#include "utilities.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


#define MAXDO   3
#define MAXCS   4
#define MAXCLK  5

Adafruit_MAX31855 thermocouple(MAXCLK, MAXCS, MAXDO);


void setup() {
    Serial.begin(115200);
    
    while (!Serial) delay(1); // wait for Serial on Leonardo/Zero, etc
    Serial.println("MAX31855 test");
    // wait for MAX chip to stabilize
    delay(500);
    Serial.print("Initializing sensor...");
    if (!thermocouple.begin()) {
      Serial.println("ERROR.");
      while (1) delay(10);
    }
    Serial.println("DONE.");  
  

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
}

void loop() {
  // basic readout test, just print the current temp
   Serial.print("Internal Temp = ");
   Serial.println(thermocouple.readInternal());

   double c = thermocouple.readCelsius();
   if (isnan(c)) {
     Serial.println("Something wrong with thermocouple!");
   } 
   else {
     Serial.print("C = ");
     Serial.println(c);
   }
   //Serial.print("F = ");
   //Serial.println(thermocouple.readFahrenheit());

   delay(1000);
   testtext(c);
   reactOnTemp(c,195); // change 195 to what temperature you want to hold
}


void testtext(double data) {
  display.clearDisplay();

  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  display.println(String(data));
  display.display();      // Show initial text
}
