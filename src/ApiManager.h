#ifndef WIFI_LAMP_ARDUINO_APIMANAGER_H
#define WIFI_LAMP_ARDUINO_APIMANAGER_H

#define SERVER_PORT 80

#include <fl/function.h>

#include <ESP8266WebServer.h>

class ApiManager {
public:
    static void Setup();
    static void HandleClient();
    static ESP8266WebServer server;

private:
    static void MapEndpoints();
    static void On(char* endpoint, const fl::function<void()>& handler);
    static void AddCors();
};


#endif //WIFI_LAMP_ARDUINO_APIMANAGER_H