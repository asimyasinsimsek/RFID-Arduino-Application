
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C ekran(0x27,16,2);
int RST_PIN= 9;
int SS_PIN= 10;
MFRC522 rfid(SS_PIN, RST_PIN);
byte ID[4]={57,30,244,179};
int ledred1= 8;
int ledred2= 7;
int ledred3= 6;
int ledgreen1= 5;
int ledgreen2= 4;
int ledgreen3= 3;
int re = 293;
int mi = 331;
int fa = 350;
int buzzer = 2;



void setup() {
 Serial.begin(9600);
 SPI.begin();
 rfid.PCD_Init();
 ekran.init();
 ekran.backlight();



}

void loop() {
  if(! rfid.PICC_IsNewCardPresent())
  return;
  if(! rfid.PICC_ReadCardSerial())
  return;
  
  if( rfid.uid.uidByte[0] == ID[0] && rfid.uid.uidByte[1] == ID[1] && rfid.uid.uidByte[2] == ID[2] && rfid.uid.uidByte[3] == ID[3])
  {Serial.print("Correct Entry!");
  ekranaYazdir();
  ekran.setCursor(1,0);
  ekran.print("Correct Entry! ");
  ekran.setCursor(4,1);
   tone(buzzer, re);
  delay(300);
  noTone(buzzer);
  delay(10);
 
  tone(buzzer, mi);
  delay(300);
  noTone(buzzer);
  delay(10);
 
 
  digitalWrite(5,HIGH);
    delay(300);
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
    delay(300);
    digitalWrite(4,LOW);
    digitalWrite(3,HIGH);
    delay(300);
    digitalWrite(3,LOW);}
  else{
    Serial.print("Incorrect Entry");
    ekranaYazdir();
    ekran.setCursor(1,0);
    ekran.print("Incorrect Entry!");
    ekran.setCursor(4,1);
 
 
  tone(buzzer, fa);
  delay(300);
  noTone(buzzer);
  delay(10);
 
  tone(buzzer, fa);
  delay(300);
  noTone(buzzer);
  delay(10);
    digitalWrite(8,HIGH);
    delay(300);
    digitalWrite(8,LOW);
    digitalWrite(7,HIGH);
    delay(300);
    digitalWrite(7,LOW);
    digitalWrite(6,HIGH);
    delay(300);
    digitalWrite(6,LOW);
  }
  rfid.PICC_HaltA();
}
void ekranaYazdir(){
  Serial.print("ID Numarasi: ");
  for(int sayac=0; sayac<4; sayac++){
    Serial.print(rfid.uid.uidByte[sayac]);
    Serial.print(" ");
  }

 Serial.println(" ");

}
