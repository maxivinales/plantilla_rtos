#if defined(ESP32)
#include <WiFiMulti.h>
WiFiMulti wifiMulti;
#define DEVICE "ESP32"
#elif defined(ESP8266)
#include <ESP8266WiFiMulti.h>
ESP8266WiFiMulti wifiMulti;
#define DEVICE "ESP8266"
#endif
#ifndef _WIFI_H_


#define WIFI_SSID "FAN-IOT"
#define WIFI_PASSWORD "f4n10t2020"
#endif
