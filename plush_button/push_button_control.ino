#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define plush 12
#define Gre_Led 14

#define SDA 22
#define SCL 21

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Keep INPUT because you have a physical pull-down resistor on the breadboard
  pinMode(plush, INPUT);
  pinMode(Gre_Led, OUTPUT);

  Wire.begin(SDA, SCL);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Button Status:");
}

void loop() {
  if (digitalRead(plush) == HIGH) {
    digitalWrite(Gre_Led, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("PRESSED - LED ON ");
  } else {
    digitalWrite(Gre_Led, LOW);
    lcd.setCursor(0, 1);
    lcd.print("RELEASED- LED OFF");
  }

  delay(50);
}
