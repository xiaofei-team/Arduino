#include <Servo.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Servo servo;
int pos = 0;
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);

void setup() {
  Serial.begin(115200);
  servo.attach(5);
  servo.write(0);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.display();
}

void loop() {
  int value=analogRead(6);
  int val=analogRead(2);
  int data=(val/650)*4;
  display.setCursor(0,0);
  display.setTextSize(2);
  display.println("the depth is:");
  display.print(data);
  display.println("cm");
  display.display();
  if(value==1){
    servo.write(180);
    delay(5000);
    servo.write(0);
    }                                
}
