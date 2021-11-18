


#include <SPI.h>
#include <RH_RF95.h>
#include<LowPower.h>
//#include <Wire.h>
RH_RF95 Lora;
#define ALARM A2
#define LED 9
void setup() {
    Serial.begin(9600);
    pinMode(ALARM, OUTPUT);
    pinMode(LED, OUTPUT);
    digitalWrite(ALARM, LOW);
    digitalWrite(LED, LOW);
//    UCSR0B = (1<<TXEN0);
//    UBRR0L = 103;
    Serial.println("Setup");
        if (!Lora.init())
        {
          Serial.println("Notice:init failed");
        }
        else
        {
          Serial.println("Notice:init Success");
        }
     
   delay(2000); 
}

void loop() {
  while (!Lora.init())
        {
          Serial.println("Notice:init failed");
         
        }
    if (Lora.available()) {
        const uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
        if (Lora.recv(buf, sizeof(buf)))
        {
          digitalWrite(LED,HIGH);        
//         digitalWrite(ALARM, HIGH);
          delay(1000);
    if(buf[0]=='1') {
          Serial.print("hvhth: ");
//          digitalWrite(ALARM,HIGH);
          Serial.print("Receive Message: ");
          Serial.println((char*)buf);
          Serial.print("RSSI: ");
          Serial.println(Lora.lastRssi(), DEC);
      delay(1000);

    }
        }  
    else
        {
            Serial.println("recv failed");
        }
//               buf[0]='0';

    }
//    digitalWrite(ALARM, LOW);
//    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_ON);
    
}
