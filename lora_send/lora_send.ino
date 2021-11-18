#include <SPI.h> // arduino spi library
#include <LoRa.h> // arduino libraries ra02 lora

#define LORA_SS 53
#define LORA_RST 9
#define LORA_DIO0 8

int counter = 0;
void setup() {
// SS, RST, DIO0
pinMode(LORA_SS, OUTPUT);
digitalWrite(LORA_SS, HIGH);

LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO0);
Serial.begin(115200);

while (!Serial);
Serial.println("LoRa Sender");

if (!LoRa.begin(433E6)) {
Serial.println("Starting LoRa failed!");
while (1);
}

// LoRa.setSpreadingFactor(10);
// LoRa.setSignalBandwidth(62.5E3);
}

void loop() {
Serial.print("Sending packet: ");
Serial.println(counter);

// send packet
LoRa.beginPacket();
LoRa.print("1");
Serial.println(counter);
LoRa.endPacket();
counter++;
delay(2000);

}
