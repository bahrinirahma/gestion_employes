#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);
RTC_DS3231 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2);

String lastUID = "";

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  lcd.begin(16, 2);
  lcd.backlight();
  rtc.begin();

  lcd.print("Systeme Pret");
  delay(2000);
  lcd.clear();
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;

  String uid = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    uid += String(rfid.uid.uidByte[i], HEX);
  }

  uid.toUpperCase();
  DateTime now = rtc.now();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ID: " + uid);

  lcd.setCursor(0, 1);
  lcd.print(now.hour(), DEC);
  lcd.print(":");
  lcd.print(now.minute(), DEC);
  lcd.print(" ");

  if (uid != lastUID) {
    Serial.print("Pointage: ");
    Serial.print(uid);
    Serial.print(" à ");
    Serial.print(now.timestamp());
    Serial.println();

    lastUID = uid;
    delay(3000);  // Anti double scan
  }

  rfid.PICC_HaltA();
}

