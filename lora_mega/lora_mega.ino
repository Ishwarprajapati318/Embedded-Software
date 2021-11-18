
    /************************************************************************/
   /***************     Created by Praveen Kumar      **********************/
  /****************     MS Studend Computer Science   *********************/
 /*****************     +917737662589                 ********************/
/************************************************************************/    
    

    #include <SPI.h>
    #include <RH_RF95.h>
#include <LiquidCrystal.h>
  RH_RF95 Lora;
  int Count;
  int i;

const int rs = 9, en = 8, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
    Serial.begin(9600);
    lcd.begin(16, 2);
    
    Serial.println();
    Serial.println("Setup");
        if (!Lora.init())
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
        i=0;
        lcd.clear();
        lcd.setCursor(0, 0);
        String url="1";
        char dataurl[url.length()+1];
        strcpy(dataurl,url.c_str());
        Lora.send(dataurl, sizeof(dataurl));
        Serial.println("Sending...");
        lcd.print("Sending...");
        lcd.setCursor(14, 0);
        lcd.print(Count++);
        Lora.waitPacketSent();
        Serial.println(" done");
        lcd.setCursor(10, 0);
        lcd.print("Done");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Wait...");
        lcd.setCursor(0, 1);
        while(i<15)
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Wait...");
          lcd.setCursor(0, 1);
          lcd.print(i++);
          delay(1000); 
        }
        
  
}
