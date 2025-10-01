#include "WifiManager.h"

IPAddress local_IP(DEFAULT_IP);
IPAddress gateway(DEFAULT_GATEWAY);
IPAddress subnet(DEFAULT_MASK);

WifiCreadentials WifiManager::credentials;
WifiMode WifiManager::currentMode;
bool WifiManager::isConnected;

void WifiManager::Setup() {
    EEPROM.begin(21);
    SetMode(Hotspot);
    ListenToWifiEvents();
    GetModeFromMemory();
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

void WifiManager::GetModeFromMemory()
{
    EEPROM.get(EEPROM_WIFI_MODE_ADDRESS, currentMode);
    EEPROM.get(EEPROM_PASSWORD_ADDRESS, credentials.Password);
    EEPROM.get(EEPROM_SSID_ADDRESS, credentials.SSID);
}

void WifiManager::SaveModeInMemory()
{
    EEPROM.put(EEPROM_WIFI_MODE_ADDRESS, currentMode);
    EEPROM.put(EEPROM_PASSWORD_ADDRESS, credentials.Password);
    EEPROM.put(EEPROM_SSID_ADDRESS, credentials.SSID);
    EEPROM.commit();
}

void WifiManager::ApplyMode()
{
    // if (currentMode == Client) {
        ConnectAsClient();
    // }
    // else if (currentMode == Hotspot) {
    //     StartHotstop();
    // }
}

void WifiManager::StartHotstop()
{
    WiFi.softAPConfig(local_IP, gateway, subnet);
    WiFi.softAP(WIFI_SSID, WIFI_PASSWORD);
}

void WifiManager::ConnectAsClient()
{
    WiFi.config(local_IP, gateway, subnet);
    WiFi.begin("Redmi 4x", "11223344");
}

void WifiManager::ListenToWifiEvents()
{
    while (!WiFi.isConnected()) {
        delay(100);
    }
    
    isConnected = true;
}
