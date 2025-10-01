#include "ApiManager.h"
#include "LampManager.h"
#include "WifiManager.h"

ESP8266WebServer ApiManager::server(SERVER_PORT);

void ApiManager::Setup() {
    MapEndpoints();
    server.begin();
}

void ApiManager::HandleClient() {
    server.handleClient();
}

void ApiManager::MapEndpoints() {
    On((char*)"/setColor", []() {
        if (!server.hasArg("color")) {
            server.send(400, "text/plain", "Missing color argument");
            return;
        }

        int r = 0, g = 0, b = 0, a = 0;
        int parsed = sscanf(server.arg(0).c_str(), "rgba(%d,%d,%d,%d)", &r, &g, &b, &a);

        if (parsed != 4) {
            server.send(400, "*/*", "Invalid format. Expected [r,g,b,a]");
            return;
        }

        CRGB color(r, g, b);
        LampManager::SetColor(color);

        server.send(200, "*/*", "");
    });

    On((char*)"/turnOn", [] {
        LampManager::TurnOn();
        server.send(200, "*/*", "");
    });

    On((char*)"/turnOff", [] {
        LampManager::TurnOff();
        server.send(200, "*/*", "");
    });

    On((char*)"/switchWifiMode", [] {
        if (!server.hasArg("wifiMode")) {
            server.send(400, "text/plain", "Missing wifiMode param");
            return;
        }

        WifiMode mode;
        sscanf(server.arg(0).c_str(), "%d", &mode);

        WifiManager::SetMode(mode);

        if (mode == Client) {
            LampManager::Blink([] { return WifiManager::IsConnected(); });
        }
    });
}

void ApiManager::On(char* endpoint, const fl::function<void()>& handler) {
    server.on(endpoint, [handler]() {
        handler();
        AddCors();
    });
}

void ApiManager::AddCors() {
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.sendHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
    server.sendHeader("Access-Control-Allow-Headers", "Content-Type");
}
