#include "LampManager.h"

CRGB LampManager::leds[NUM_LEDS];
CRGB LampManager::currentLampColor;

void LampManager::SetColor(CRGB color) {
    currentLampColor = color;
}

void LampManager::ApplyColor() {
    for (uint8_t i = 0; i < NUM_LEDS; i++) {
        leds[i] = currentLampColor;
    }
    FastLED.show();
}

bool LampManager::IsLampActive() {
    return isLampActive;
}

void LampManager::Setup() {
    currentLampColor = CRGB::Red;

    pinMode(LED_STRIP_PIN, OUTPUT);
    pinMode(RESET_BUTTON_PIN, INPUT);

    FastLED.addLeds<NEOPIXEL, LED_STRIP_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(255);
    TurnOn();
}

void LampManager::TurnOff() {
    SetColor(CRGB::Black);
    ApplyColor();
}

void LampManager::TurnOn() {
    SetColor(CRGB::Magenta);
    ApplyColor();
}