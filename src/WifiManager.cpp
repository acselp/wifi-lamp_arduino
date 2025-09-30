#include "WifiManager.h"

IPAddress local_IP(DEFAULT_IP);
IPAddress gateway(DEFAULT_GATEWAY);
IPAddress subnet(DEFAULT_MASK);


void WifiManager::Setup() {
    WiFi.softAPConfig(local_IP, gateway, subnet);
    WiFi.softAP(WIFI_SSID, WIFI_PASSWORD);
}

void WifiManager::SwitchMode(WifiMode mode) {
    if (mode == Hotspot) {

    }
    else if (mode == Client) {

    }
}
