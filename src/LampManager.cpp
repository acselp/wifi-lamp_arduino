#include "LampManager.h"

CRGB LampManager::leds[NUM_LEDS];

void LampManager::SetColor(CRGB color) {
    for (uint8_t i = 0; i < NUM_LEDS; i++) {
        leds[i] = color;
    }
    FastLED.show();
}

void LampManager::Setup() {
    pinMode(LED_STRIP_PIN, OUTPUT);
    pinMode(RESET_BUTTON_PIN, INPUT);

    FastLED.addLeds<NEOPIXEL, LED_STRIP_PIN>(leds, NUM_LEDS);
    SetColor(CRGB::Magenta);
    TurnOn();
}

void LampManager::TurnOff() {
    FastLED.setBrightness(0);
    FastLED.show();
}

void LampManager::TurnOn() {
    FastLED.setBrightness(255);
    FastLED.show();
}