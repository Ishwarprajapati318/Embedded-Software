 
    /************************************************************************/
   /***************     Created by Praveen Kumar      **********************/
  /****************     MS Studend Computer Science   *********************/
 /*****************     +917737662589                 ********************/
/************************************************************************/    
    

    #include <avr/wdt.h>          // Library for Watch Dog Timer``  
    #include <SPI.h>
    #include <RH_RF95.h>
    #include <Wire.h>
    #include <LiquidCrystal_I2C.h>
  RH_RF95 Lora;
  int Count;
  int i;
  long prevmillis;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    Serial.begin(9600);
//  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  
  lcd.home();
  
  lcd.setCursor(0, 0);
    
    Serial.println();
    Serial.println("Setup");
//        if (!Lora.init())
//        {
//          Serial.println("Notice:init failed");
//          lcd.print("init failed");
//        }
//        else
//        {
          Serial.println("Notice:init Success");
          lcd.print("init Success");
//        }
     
   delay(2000);
        
         
 
  
}

void loop() {

            lcd.setCursor(10, 1);
//             if (!Lora.init())
//        {
//          Serial.println("Notice:init failed");
//          lcd.print("F");
//        }
//        else
//        {
//          Serial.println("Notice:init Success");
//          lcd.print("S");
//        }
            lcd.print("|");
            
        
        lcd.print(i++);
//    if (Lora.available())
//    {
//        uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
//        uint8_t len = sizeof(buf);
//        if (Lora.recv(buf, &len))
//        {
            
            //RH_RF95::printBuffer("request: ", buf, len);
            Serial.print("Receive Message: ");
//            Serial.println((char*)buf);
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Receive M");
            lcd.print(Count++);
            lcd.print(": ");
//            lcd.print((char*)buf);
            
//            Serial.print("RSSI: ");
//            Serial.println(Lora.lastRssi(), DEC);
            lcd.setCursor(0, 1);
            lcd.print("RSSI: ");
////            lcd.print(Lora.lastRssi(), DEC);
//            delay(1000);
//           
//        }
//        else
//        {
//            Serial.println("recv failed");
//        }
//    }

        
  
}
