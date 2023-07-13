/*
 * Project signal-intelligence
 * Description:
 * Author:
 * Date:
 */
#include "../lib/Adafruit_SSD1306/src/Adafruit_GFX.h"
#include "../lib/Adafruit_SSD1306/src/Adafruit_SSD1306.h"

#define OLED_RESET D4
Adafruit_SSD1306 display(OLED_RESET);

void testscrolltext(void) {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  display.clearDisplay();
  display.println("scroll");
  display.display();
 
  display.startscrollright(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);    
  display.startscrolldiagright(0x00, 0x07);
  delay(2000);
  display.startscrolldiagleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
}

// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);
  display.display(); // show splashscreen
  delay(2000);
  display.clearDisplay();
  String ipAddrString = String::format("localIP: %s", Cellular.localIP().toString().c_str());
  // draw scrolling text
  testscrolltext();
  delay(2000);
  display.clearDisplay();
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.

}