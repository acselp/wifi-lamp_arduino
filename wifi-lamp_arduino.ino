#include "src/LampManager.h"
#include "src/WifiManager.h"
#include "src/ApiManager.h"

void setup(){
  LampManager::Setup();
  WifiManager::Setup();
  ApiManager::Setup();
}

void loop(){
  ApiManager::HandleClient();
}