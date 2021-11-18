
    /************************************************************************/
   /***************     Created by Praveen Kumar      **********************/
  /****************     MS Studend Computer Science   *********************/
 /*****************     +917737662589                 ********************/
/************************************************************************/    
    

#include <SPI.h>
#include <RH_RF95.h>
//#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

RH_RF95 SX1278(53, 2);
  int Count;
  int i;
  long prevmillis;
#define LORA_DIO0 2
#define LORA_SS 53
#define LORA_RST 9 
#define LED 12
//const int rs = 9, en = 8, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
    Serial.begin(9600);
    lcd.init();
    lcd.backlight(); 
//    lcd.home();
    pinMode(LED,OUTPUT);
    pinMode(LORA_RST, OUTPUT);
    digitalWrite(LORA_RST,HIGH);
    digitalWrite(LED,LOW);
    pinMode(LORA_SS, OUTPUT);
    digitalWrite(LORA_SS,HIGH);
    Serial.println();
    Serial.println("Setup");
        if (!SX1278.init())
        {
          Serial.println("Notice:init failed");
          lcd.print("init failed");
        }
        else
        {
          Serial.println("Notice:init Success");
          lcd.print("init Success");
        }
     
   delay(2000);
        
         
 
  
}

void loop() {
//      if (!SX1278.init());
        digitalWrite(LORA_RST,HIGH);
        digitalWrite(LED,LOW);
        lcd.clear();
        lcd.setCursor(0, 0);
        const uint8_t data[] = "1";
        SX1278.send(data, sizeof(data));
        Serial.println("Sending...");
        lcd.print("Sending...");
        delay(1000);
        SX1278.waitPacketSent();
        Serial.println(" done");
        lcd.print("Done...");
        delay(4000);
        digitalWrite(LED,HIGH);
        delay(1000);
        digitalWrite(LED,LOW);
        delay(1000);  
        digitalWrite(LED,HIGH);
        delay(1000);
        digitalWrite(LED,LOW);
        delay(100);
        digitalWrite(LED,HIGH);
        delay(1000);

         
}
