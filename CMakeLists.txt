cmake_minimum_required(VERSION 4.0)
project(wifi_lamp_arduino)

set(CMAKE_CXX_STANDARD 14)

include_directories(
        src
        "C:/Users/Dumirtita/Documents/Arduino/libraries/FastLED/src"
        "C:/Users/Dumirtita/Documents/Arduino/libraries/ESP8266Wifi/src"
        "C:/Users/Dumirtita/Documents/Arduino/libraries/ESP8266WebServer/src"
)

add_executable(wifi_lamp_arduino
        src/LampManager.cpp
        src/LampManager.h
        src/WifiManager.cpp
        src/WifiManager.h
        src/ApiManager.cpp
        src/ApiManager.h)
