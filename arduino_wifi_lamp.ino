#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>   // Include the WebServer library

const char* ssid = "WIFI_LAMP";
const char* password = "11223344";    // Create an instance of the ESP8266WiFiMulti class, called 'wifiMulti'

ESP8266WebServer server(80); 


void handleRoot();              // function prototypes for HTTP handlers
void handleNotFound();

void setup(void){
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
  server.on("/turnOn", handleRoot);

  // Start the web server
  server.begin();
  Serial.println("HTTP server started");
}

void addCORSHeaders() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.sendHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
  server.sendHeader("Access-Control-Allow-Headers", "Content-Type");
}

void loop(void){
  server.handleClient();
}

void handleTurnOn() {
  addCORSHeaders();
  server.send(200, "*/*", "Hello world!");   // Send HTTP status 200 (Ok) and send some text to the browser/client
  Serial.println("root");
}