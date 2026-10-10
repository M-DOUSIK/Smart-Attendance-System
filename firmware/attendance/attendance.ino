#include <SPI.h>
#include <MFRC522.h>
#include <TimeLib.h>

#define SS_PIN 10
#define RST_PIN 9
#define TIME_HEADER  "T"
#define TIME_REQUEST  7 

MFRC522 mfrc522(SS_PIN, RST_PIN);

byte card_ID[4];
byte Student1[4]={0x00,0x5B,0x49,0x1A};
byte Student2[4]={0x20,0x37,0xB0,0x20};    

int const Buzzer=8;

String Name;
long Number;
int n ;

int greenLed = 4;
int sensor = 2;
int sensorState;
int redLed = 3;
int esensor = 5;
int esensorState;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  pinMode(Buzzer,OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(sensor, INPUT);


   }
    
void loop() {
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);
  sensorState = digitalRead(sensor);
  esensorState = digitalRead(esensor);

  if (sensorState == HIGH) {
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, HIGH);
    digitalWrite(Buzzer, HIGH);
    delay(1000);
    digitalWrite(Buzzer, LOW);
    
    while (true) {
      esensorState = digitalRead(esensor);
      if ( ! mfrc522.PICC_IsNewCardPresent()) {
        if (esensorState == LOW){
          continue;
        }
        else {
          digitalWrite(Buzzer, HIGH);
          delay(100);
          digitalWrite(Buzzer, LOW);
          digitalWrite(Buzzer, HIGH);
          delay(100);
          digitalWrite(Buzzer, LOW);
          Serial.println("Exit Again and Wait for 5 seconds");
          delay(5000);
          return;
        }
 }
 
 if ( ! mfrc522.PICC_ReadCardSerial()) {
  if (esensorState == LOW){
          continue;
        }
        else {
          digitalWrite(Buzzer, HIGH);
          delay(100);
          digitalWrite(Buzzer, LOW);
          digitalWrite(Buzzer, HIGH);
          delay(100);
          digitalWrite(Buzzer, LOW);
          Serial.println("Exit Again and Wait for 5 seconds");
          delay(5000);
          return;
        }
 }
 
 for (byte i = 0; i < mfrc522.uid.size; i++) {
     card_ID[i]=mfrc522.uid.uidByte[i];

       if(card_ID[i]==Student1[i]){
       Name="Dousik";
       Number=30;
      }
      else if(card_ID[i]==Student2[i]){
       Name="Deepak";
       Number=07;
      }
      else{
          goto cont;
     }
 }
      
      
      while (true){
        esensorState = digitalRead(esensor);
        if (esensorState == HIGH){
    
      Serial.print(Name);
      Serial.print(",");
      Serial.print(Number);
      Serial.print(",");
      Serial.println("Entry");
      digitalWrite(Buzzer,HIGH);
      delay(30);
      digitalWrite(Buzzer,LOW);
      delay(1000);
      break;
        } else {
          continue;
        }
        
      }
      break;

cont:
delay(2000);
    }
  } 
  
  else if (esensorState == HIGH) {
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, HIGH);
    digitalWrite(Buzzer, HIGH);
    delay(1000);
    digitalWrite(Buzzer, LOW);
    
    while (true) {
      sensorState = digitalRead(sensor);
      if ( ! mfrc522.PICC_IsNewCardPresent()) {
        if (sensorState == LOW){
          continue;
        }
        else {
          digitalWrite(Buzzer, HIGH);
          delay(100);
          digitalWrite(Buzzer, LOW);
          digitalWrite(Buzzer, HIGH);
          delay(100);
          digitalWrite(Buzzer, LOW);
          Serial.println("Enter Again and Wait for 5 seconds");
          delay(5000);
          return;
        }
 }
 
 if ( ! mfrc522.PICC_ReadCardSerial()) {
  if (sensorState == LOW){
          continue;
        }
        else {
          digitalWrite(Buzzer, HIGH);
          delay(100);
          digitalWrite(Buzzer, LOW);
          digitalWrite(Buzzer, HIGH);
          delay(100);
          digitalWrite(Buzzer, LOW);
          Serial.println("Enter Again and Wait for 5 seconds");
          delay(5000);
          return;
        }
 }
 
 for (byte i = 0; i < mfrc522.uid.size; i++) {
     card_ID[i]=mfrc522.uid.uidByte[i];

       if(card_ID[i]==Student1[i]){
       Name="Dousik";
       Number=30;
      }
      else if(card_ID[i]==Student2[i]){
       Name="Deepak";
       Number=07;
      }
      else{
          goto cont1;
     }
 }
      
      Serial.print(Name);
      Serial.print(",");
      Serial.print(Number);
      Serial.print(",");
      Serial.println("Exit");
      digitalWrite(Buzzer,HIGH);
      delay(30);
      digitalWrite(Buzzer,LOW);
      delay(1000);
      break;

cont1:
delay(2000);
    }
  }

}

    
