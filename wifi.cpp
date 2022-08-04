#include "wifi.h"


void wifi_launch(){
  WiFi.mode(WIFI_STA);
  wifiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connecting to wifi");
  while (wifiMulti.run() != WL_CONNECTED) {
  Serial.print(".");
  vTaskDelay(pdMS_TO_TICKS(100));
}
}