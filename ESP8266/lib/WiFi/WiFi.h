#ifndef LIB_WIFI_H
#define LIB_WIFI_H

#include <ESP8266WiFi.h>

bool initWiFi(void);

extern WiFiClient client;

#endif /* LIB_WIFI_H */