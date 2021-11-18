void getDHT() {
  humidity = dht.readHumidity();
  tempc = dht.readTemperature();
  
  if (isnan(humidity) || isnan(tempc)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    tempc=0.0,humidity=0.0; dewpoint=0.0;
  } else {
    dewpoint = calDewpoint(humidity, tempc);

    if (DEBUG) {
      Serial.print("Humidity: ");  Serial.println(humidity);
      Serial.print("Temperature (C): ");  Serial.println(tempc);
      Serial.print("Dewpoint: ");  Serial.println(dewpoint);
    }
  }
}

float calDewpoint(float hum, float temp) {
  float Tda;
  Tda = log(hum/100) + (17.62 * temp) / (243.12 + temp);
  return 243.12 * Tda / (17.62 - Tda);
}
