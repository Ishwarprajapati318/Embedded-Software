
#include <SPI.h>
#include <RH_RF95.h>
#include<LowPower.h>
// Singleton instance of the radio driver
//RH_RF95 SX1278;
RH_RF95 SX1278(53, 2); // Rocket Scream Mini Ultra Pro with the RFM95W

//#define Serial SerialUSB
#define LORA_DIO0 2
#define LORA_SS 53
#define LORA_RST 9 
#define LED 13
#define GSEN 12
#define L_EN 16

void setup()
{
Serial.begin(9600);
   Serial.println("Setup"); 
    pinMode(LED,OUTPUT);
    pinMode(LORA_RST, OUTPUT);
    pinMode(L_EN, OUTPUT);
    digitalWrite(LORA_RST,HIGH);
    digitalWrite(L_EN,HIGH);
    digitalWrite(LED,LOW);
    pinMode(LORA_SS, OUTPUT);
    digitalWrite(LORA_SS,HIGH);
     pinMode(GSEN, OUTPUT);
    digitalWrite(GSEN,HIGH);
//     UCSR0B = (1<<TXEN0);
//     UBRR0L = 103;
    Serial.println("Setup1");
    while (!Serial) ; // Wait for serial port to be available
    if (!SX1278.init())
    {
        Serial.println("init failed");
    }
    else {
              Serial.println("init success");
    }
    Serial.println("Setup2");
    // Defaults init are 434.0MHz, 13dBm, Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on
}

void loop()
{
//Serial.println("Setup3");  
   if (!SX1278.init());
    digitalWrite(LORA_RST,HIGH);
    digitalWrite(L_EN,HIGH);
    digitalWrite(LED,LOW);
     digitalWrite(GSEN,HIGH);

//    digitalWrite(LED,LOW);
    Serial.println("Sx1278");
        const uint8_t data[]="1";
        SX1278.send(data, sizeof(data));
        Serial.println("Sending...");
        delay(1000);
        SX1278.waitPacketSent();
        Serial.println(" done");
        delay(5000);
        digitalWrite(LED,HIGH);
         delay(1000);
         digitalWrite(LED,LOW);
         delay(1000); 
}
