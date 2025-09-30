#include "WifiManager.h"

IPAddress local_IP(192,168,4,1);
IPAddress gateway(192,168,4,1);
IPAddress subnet(255,255,255,0);

void WifiManager::Setup() {
    WiFi.softAPConfig(local_IP, gateway, subnet);
    WiFi.softAP(WIFI_SSID, WIFI_PASSWORD);

}
