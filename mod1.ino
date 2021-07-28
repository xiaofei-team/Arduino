#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,1);

void setup()
{
  Serial.begin(115200);
  pinMode(3,OUTPUT);
  lcd.init();                      
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Light:");
  digitalWrite(3,HIGH);
}


void loop() 
{
  float val;
  val=analogRead(6);
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Light:");
  lcd.println(val);
  delay(500);
  float water;
  water =analogRead(2);
  if (water <110 ){
    digitalWrite(3,LOW);
    delay(300000);
    digitalWrite(3,HIGH);
  }
}
