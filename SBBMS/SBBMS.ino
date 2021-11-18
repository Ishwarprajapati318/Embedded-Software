/***************************************************************************************************************
* Made by  : Tushar Saini
* Email Id : tsaini1285@gmail.com
***************************************************************************************************************/
#include <SoftwareSerial.h>
#include <Wire.h>
#include <DHT.h>
#include "esp_attr.h"       // To store ISR on fast storage
#define ENABLE_5V 26

//String id = "Shimla";
const char signMessage[] PROGMEM  = {"AT+HTTPPARA=\"URL\",\"landslidemonitoring.esy.es/db_insertion.php?api_key=3WU63XFVOKEC1VBM&triplet="};

/***************************** DHT-22 ********************************/
#define DHTPIN 33
#define DHTTYPE DHT22
#define DEBUG true

DHT dht(DHTPIN, DHTTYPE);

float tempc;
float dewpoint;
float humidity;
/********************************************************************/
/***********************************************************************/
SoftwareSerial mySerial(14, 2);


void setup() {
  Serial.begin(9600);
  Serial.println("Setting up...");
  pinMode(ENABLE_5V, OUTPUT);
  
  digitalWrite(ENABLE_5V, HIGH);
  
  mySerial.begin(9600);
  dht.begin();

  Wire.begin();
  initSIM();
}

void loop() {
  getDHT();
  sendData(makeURL());
  delay(5000);
  deepSleep();
  delay(1000);
}

String makeURL() {
  String url="t1&t1s1=";
    url+=String(dht.readTemperature())+","+String(dht.readHumidity())+"&t1s2="+String(lat)+","+String(lon);
//  String url = "https://us-central1-aqi-iit-82dc7.cloudfunctions.net/app/adddata?id=" + id +
//  + "&pm1=" + String(PM01Value)
//  + "&pm25=" + String(PM2_5Value)
//  + "&pm10="  + String(PM10Value)
//  + "&co="  + String(readCO)
//  + "&no2="  + String(readNO2) 
//  + "&o3="  + String(o3) 
//  + "&so2="  + String(so2)
//  + "&ws="  + String(windSpeed)
//  + "&wd="  + String(heading)
//  + "&temp="  + String(temp)
//  + "&pres="  + String(pressure)
//  + "&hum="  + String(humidity)
//  + "&dp="  + String(dewpoint);
//  
  return url;
}
