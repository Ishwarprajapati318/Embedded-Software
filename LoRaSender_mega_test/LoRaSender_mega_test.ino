#include <SPI.h>
#include <LoRa.h>

#define LORA_DIO0 2
#define LORA_SS 53
#define LORA_RST 9 
#define LED 13
#define GSEN 12
#define L_EN 16
int counter = 0;

void setup() {
  
    pinMode(LED,OUTPUT);
    pinMode(LORA_RST, OUTPUT);
    pinMode(L_EN, OUTPUT);
    digitalWrite(LORA_RST,LOW);
    digitalWrite(L_EN,HIGH);
    digitalWrite(LED,LOW);
    pinMode(LORA_SS, OUTPUT);
    digitalWrite(LORA_SS,HIGH);
     pinMode(GSEN, OUTPUT);
    digitalWrite(GSEN,HIGH);
    
    LoRa.setPins(LORA_SS,LORA_RST,LORA_DIO0);
    Serial.begin(115200);
  while (!Serial);

  Serial.println("LoRa Sender");
// LoRa.setPins(RST,DIO0);
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  digitalWrite(LORA_RST,HIGH);
    digitalWrite(L_EN,HIGH);
    digitalWrite(LED,LOW);
     digitalWrite(GSEN,HIGH);
//  Serial.print("Sending packet: ");
//  Serial.println(counter);

  // send packet
//  int num=1;
  const uint8_t data="1";
//  Serial.println(num,OCT);
  Serial.println(data,OCT);
  digitalWrite(LED,HIGH);
  LoRa.beginPacket();
  LoRa.print(data);
  Serial.print("Sending  ");
   Serial.print(data);
  LoRa.endPacket();
  Serial.print("Sending done ");
   digitalWrite(LED,LOW);
   delay(1000);
    digitalWrite(LED,HIGH);
    delay(1000);

  delay(500);
}
