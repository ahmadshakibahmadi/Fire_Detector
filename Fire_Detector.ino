#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Set the LCD address (usually 0x27 or 0x3F), and size (16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2); 
const int flameSensor = 2;  // D0 from sensor
const int buzzer = 8;       // Optional buzzer
void setup() {
  pinMode(flameSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("Fire Detector");
  delay(2000);
  lcd.clear();
}
void loop() {
  int flameState = digitalRead(flameSensor);
  lcd.setCursor(0, 0);
  if (flameState == LOW) {
    lcd.print("Fire Detected!");
    digitalWrite(buzzer, HIGH);
    Serial.println(" Fire Detected!");
  } else {
    lcd.print(" Safe");
    digitalWrite(buzzer, LOW);
    Serial.println(“Safe");
  }
  delay(500);
}

