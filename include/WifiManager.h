#ifndef WIFI_LAMP_ARDUINO_WIFIMANAGER_H
#define WIFI_LAMP_ARDUINO_WIFIMANAGER_H

#define WIFI_SSID "WIFI-LAMP"
#define WIFI_PASSWORD "11223344"
#define EEPROM_WIFI_MODE_ADDRESS 0
#define EEPROM_PASSWORD_ADDRESS 1
#define EEPROM_SSID_ADDRESS 11
#define DEFAULT_IP 192,168,4,1
#define DEFAULT_GATEWAY 192,168,4,1
#define DEFAULT_MASK 255,255,255,0

#include <ESP8266WiFi.h>
#include <EEPROM.h>

enum WifiMode {
    Hotspot = 0,
    Client = 1
};

struct WifiCreadentials {
    String SSID;
    String Password;
};

class WifiManager {
public:
    static void Setup();
    static void SetMode(WifiMode mode);
    static void SetCredentials(WifiCreadentials credentials);
    static bool IsConnected();

    
    static WifiMode currentMode;
    static bool isConnected;
    static WifiCreadentials credentials;

    static void GetModeFromMemory();
    static void SaveModeInMemory();  

    static void ApplyMode();
    static void StartHotstop();
    static void ConnectAsClient();
    static void ListenToWifiEvents();
};


#endif //WIFI_LAMP_ARDUINO_WIFIMANAGER_H