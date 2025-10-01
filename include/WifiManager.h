#ifndef WIFI_LAMP_ARDUINO_WIFIMANAGER_H
#define WIFI_LAMP_ARDUINO_WIFIMANAGER_H

#define WIFI_SSID "WIFI-LAMP"
#define WIFI_PASSWORD "11223344"
#define DEFAULT_IP 192,168,4,1
#define DEFAULT_GATEWAY 192,168,4,1
#define DEFAULT_MASK 255,255,255,0

#include <ESP8266WiFi.h>

enum WifiMode {
    Hotspot = 0,
    Client = 1
};

class WifiManager {
public:
    static void Setup();
    static void SwitchMode(WifiMode mode);

    static WifiMode currentMode;
};


#endif //WIFI_LAMP_ARDUINO_WIFIMANAGER_H