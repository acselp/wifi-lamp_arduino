#include <Arduino.h>
#include "LampManager.h"
#include "WifiManager.h"
#include "ApiManager.h"

void setup() {
  LampManager::Setup();
  WifiManager::Setup();
  ApiManager::Setup();
}

void loop() {
  ApiManager::HandleClient();
}