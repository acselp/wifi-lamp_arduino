#include "WifiManager.h"

IPAddress local_IP(DEFAULT_IP);
IPAddress gateway(DEFAULT_GATEWAY);
IPAddress subnet(DEFAULT_MASK);

WifiCreadentials WifiManager::credentials;
WifiMode WifiManager::currentMode;
bool WifiManager::isConnected;

void WifiManager::Setup() {
    EEPROM.begin(1);
    SetMode(Hotspot);
    ListenToWifiEvents();
    WiFi.mode(WIFI_AP_STA);
    currentMode = GetModeFromMemory();
    ApplyMode();
}

void WifiManager::SetMode(WifiMode mode) {
    currentMode = mode;
    SaveModeInMemory();
    ApplyMode();
}

void WifiManager::SetCredentials(WifiCreadentials _credentials)
{
    credentials = _credentials;
}


bool WifiManager::IsConnected()
{
    return isConnected;
}

WifiMode WifiManager::GetModeFromMemory()
{
    WifiMode mode;
    EEPROM.get(EEPROM_WIFI_MODE_ADDRESS, mode);

    return mode;
}

void WifiManager::SaveModeInMemory()
{
    EEPROM.put(EEPROM_WIFI_MODE_ADDRESS, currentMode);
    EEPROM.commit();
}

void WifiManager::ApplyMode()
{
    if (currentMode == Client) {
        ConnectAsClient();
    }
    else if (currentMode == Hotspot) {
        StartHotstop();
    }
}

void WifiManager::StartHotstop()
{
    WiFi.softAPConfig(local_IP, gateway, subnet);
    WiFi.softAP(WIFI_SSID, WIFI_PASSWORD);
}

void WifiManager::ConnectAsClient()
{
    WiFi.begin(credentials.SSID, credentials.Password);
}

void WifiManager::ListenToWifiEvents()
{
    // WiFi.onStationModeGotIP([](const WiFiEventStationModeGotIP& event) {
    //     isConnected = true;
    // });

    // WiFi.onStationModeDisconnected([](const WiFiEventStationModeDisconnected& event) {
    //     isConnected = false;
    // });
}
