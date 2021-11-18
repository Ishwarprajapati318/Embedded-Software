// TTGO T-Call pins
#define MODEM_RST            5
#define MODEM_PWKEY          4
#define MODEM_POWER_ON       23
#define MODEM_TX             27
#define MODEM_RX             26

SoftwareSerial myGsm(MODEM_RX, MODEM_TX);

void initSIM() {
  pinMode(MODEM_PWKEY, OUTPUT);
  pinMode(MODEM_RST, OUTPUT);
  pinMode(MODEM_POWER_ON, OUTPUT);
  digitalWrite(MODEM_PWKEY, LOW);
  digitalWrite(MODEM_RST, HIGH);
  digitalWrite(MODEM_POWER_ON, HIGH);

  delay(3000);
}

void sendData(String url) {
  Serial.println("URL: "+url);
  myGsm.begin(9600);
  myGsm.println(F("Setting up GSM."));

  myGsm.println(F("AT+CFUN=1"));  // Set phone functionality to full functionality.
  delay(4000); GsmResponse();
  
  myGsm.println(F("AT+CGATT?"));  // Attach GPRS
  delay(2000); GsmResponse();
  
  myGsm.println(F("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\""));  // Activate Bearer profile.
  delay(2000); GsmResponse();
  
  myGsm.println(F("AT+SAPBR=3,1,\"APN\",\"airtelgprs.com\""));  // Set APN of network, here we are using Airtel sim.
  delay(2000); GsmResponse();
  
  myGsm.println(F("AT+SAPBR=1,1"));
  delay(2000); GsmResponse();
  
  myGsm.println(F("AT+SAPBR=2,1")); // Shows IP
  delay(5000); GsmResponse();

  myGsm.println("AT+HTTPINIT"); // Initialize  HTTP  Service
  delay(2000);
  
  myGsm.println("AT+HTTPPARA=\"URL\",\""+url+"\""); // Set parameters for HTTP session
  delay(2000); GsmResponse(); 

  myGsm.println(F("AT+HTTPSSL=1")); // Enable HTTPS function
  delay(2000); GsmResponse();

  myGsm.println(F("AT+HTTPACTION=0"));  // GET session start
  delay(2000); GsmResponse();
  
  myGsm.println(F("AT+HTTPREAD"));  // Read the data of HTTP server
  delay(5000); GsmResponse();

  myGsm.println(F("AT+HTTPTERM"));  // Terminate HTTP service
  delay(5000); GsmResponse();
}

void GsmResponse() {
  String inData = "";
  while (myGsm.available() > 0) {
    inData = myGsm.readString();
    Serial.println(inData);
    Serial.println(F("***"));
  }
}
