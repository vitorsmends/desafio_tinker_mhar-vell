#include <LiquidCrystal.h>

const int rs = 6, en = 7, d4 =5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(3, OUTPUT);
  lcd.setCursor(0,0);
  lcd.print("iniciando");
  delay(1000);
  lcd.clear();
}

void loop(){
  if (Serial.available()) {
    float val = Serial.parseFloat();
    Serial.print(val);
    lcd.print(val);
    lcd.print("cm");
    delay(2000);
    lcd.clear();
  }
  delay(10); 
}
