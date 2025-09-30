#ifndef WIFI_LAMP_ARDUINO_WIFIMANAGER_H
#define WIFI_LAMP_ARDUINO_WIFIMANAGER_H

#define WIFI_SSID "WIFI-LAMP"
#define WIFI_PASSWORD "11223344"

#include <ESP8266WiFi.h>

class WifiManager {
public:
    static void Setup();
};


#endif //WIFI_LAMP_ARDUINO_WIFIMANAGER_H