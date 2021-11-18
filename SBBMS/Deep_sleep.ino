void deepSleep() {
  const int seconds = 1800; //(currently: 30 min)
  esp_sleep_enable_timer_wakeup(seconds*1000000); // Microseconds 
  Serial.println("Going to sleep now");
  Serial.flush(); 
  esp_deep_sleep_start();
}
