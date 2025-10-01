#ifndef WIFI_LAMP_ARDUINO_LAMPMANAGER_H
#define WIFI_LAMP_ARDUINO_LAMPMANAGER_H

#define NUM_LEDS 29
#define LED_STRIP_PIN 14
#define RESET_BUTTON_PIN 4

#include <cstdint>
#include <FastLED.h>

class LampManager {
public:
    static void TurnOn();
    static void TurnOff();
    static void SetColor(CRGB color);
    static void Setup();
    static void Blink(const fl::function<bool()>& predicate);

private:
    static CRGB leds[NUM_LEDS];
};


#endif //WIFI_LAMP_ARDUINO_LAMPMANAGER_H