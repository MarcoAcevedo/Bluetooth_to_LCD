#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int tx = 1;
int rx = 0;
char inSerial[32];
String old = "";
int i = 0;

void setup() {
  Serial.begin(9600);
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);
  lcd.begin(16, 2);
  lcd.print("Booting");

}

void loop() {
  delay(2000);
  i = 0;
  if (Serial.available() > 0) {
    while (Serial.available() > 0) {
      inSerial[i] = Serial.read();
      i++;
    }
    inSerial[i] = '\0';
    method(inSerial);
    old = inSerial;
    while (i >= 0) {
      inSerial[i--] = 0;
    }
  }
}

void method(char inSerial[]) {
  inSerial[i--] = 0;
  inSerial[i--] = 0;
  inSerial[i--] = 0;
  lcd.clear();
  String s = inSerial;
  lcd.print(s);
}
