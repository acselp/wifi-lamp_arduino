#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "WIFI_LAMP";
const char* password = "11223344";    // Create an instance of the ESP8266WiFiMulti class, called 'wifiMulti'

ESP8266WebServer server(80);

void handleOn();
void handleOff();
void handleSetColor();

void setup(void){
  pinMode(LEDSTRIP_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);

  FastLED.addLeds<NEOPIXEL, LEDSTRIP_PIN>(leds, NUM_LEDS);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = currentColor;
  }

  Serial.begin(115200);
  WiFi.softAP(ssid, password);

  Serial.println();
  Serial.print("Hotspot SSID: ");
  Serial.println(ssid);
  Serial.print("Hotspot Password: ");
  Serial.println(password);
  
  // Get and display the IP address of the ESP8266
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());

  // Define routes
  server.on("/turnOn", handleOn);
  server.on("/turnOff", handleOff);
  server.on("/setColor", handleSetColor);


  // Start the web server
  server.begin();
  Serial.println("HTTP server started");
}


void loop(void){
  server.handleClient();
}

void turnOnLamp() {
  for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Black;
  }
  FastLED.show();
}

void turnOffLamp() {
  for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = currentColor;
  }
  FastLED.show();
}

void setColor(int color[]) {
  CRGB colorToSet = CRGB(color[0], color[1], color[2]);
  for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = colorToSet;
  }
  FastLED.show();
}

void addCORSHeaders() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.sendHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
  server.sendHeader("Access-Control-Allow-Headers", "Content-Type");
}

void handleOn() {
  turnOnLamp();

  addCORSHeaders();
  server.send(200, "*/*", "");   // Send HTTP status 200 (Ok) and send some text to the browser/client
}

void handleOff() {
  turnOffLamp();

  addCORSHeaders();
  server.send(200, "*/*", "");   // Send HTTP status 200 (Ok) and send some text to the browser/client
}

void handleSetColor() {
  // int color[4] = { 0, 0, 0, 0 };

  // sscanf(server.arg(0), "rgba(%d,%d,%d,%d)", &color[0], &color[1], &color[2], &color[3]);

  // setColor(color);
  addCORSHeaders();
  server.send(200, "*/*", "");   // Send HTTP status 200 (Ok) and send some text to the browser/client
}