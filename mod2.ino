#include <LiquidCrystal_I2C.h>
#include <SimpleDHT.h>

LiquidCrystal_I2C lcd(0x27, 14, 2);
SimpleDHT11 dht(2);

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.home();
  pinMode(4, OUTPUT);
  pinMode(6, INPUT);
  digitalWrite(4, HIGH);
  digitalWrite(6, LOW);
}

void loop() {
  byte temp, humid;
  int fire =digitalRead (A0);
  Serial.println(fire);
  if (fire==1){
    digitalWrite(4, LOW);
    digitalWrite(6, HIGH);
    delay(3000);
  }
  else{
    digitalWrite(4, HIGH);
    digitalWrite(6, LOW);
  }
  int err;
  if ((err = dht.read(&temp, &humid, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.print(SimpleDHTErrCode(err));
    Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  }

  lcd.clear();
  lcd.home();
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humid);
  lcd.print("%RH");
  delay(2000);
}
