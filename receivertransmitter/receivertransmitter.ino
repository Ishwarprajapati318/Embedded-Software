


#include <SPI.h>
#include <RH_RF95.h>
#include<LowPower.h>
#include <Wire.h>
void(* resetFunc) (void) = 0;
// Singleton instance of the radio driver
RH_RF95 SX1278;
int Counter;

#define ALARM A2
#define LED 9
int buf=1;
void setup() {
    Serial.begin(9600);
    pinMode(ALARM, OUTPUT);
    pinMode(LED, OUTPUT);
    digitalWrite(ALARM, LOW);
    digitalWrite(LED, LOW);
//    UCSR0B = (1<<TXEN0);
//    UBRR0L = 103;
    Serial.println("Setup");
    while (!Serial) ; // Wait for serial port to be available
    while (!SX1278.init()) {
        Serial.println("init failed");
    }
    Serial.println("init success..");
}

void loop() {
   if (!SX1278.init());
    digitalWrite(ALARM, LOW);
    digitalWrite(LED, LOW);
    if (SX1278.available()) {
        uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
        uint8_t len = sizeof(buf);
    if(buf[0]=='1') {
      String url="buf[0]";
      const uint8_t data[]="url";
      SX1278.send(data, sizeof(data));
      Serial.println("Sending...");
      delay(1000);
      SX1278.waitPacketSent();
      Serial.println(" done");
      delay(5000);
      digitalWrite(ALARM,HIGH);
      delay(1000);
      resetFunc();
      buf[0]='0';
    }
  
    
    } else {
      Serial.println("no signal...");
    }
    digitalWrite(ALARM, LOW);
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_ON);
    
}
