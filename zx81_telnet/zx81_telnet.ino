#include <ESP8266WiFi.h>

// Hardcode WiFi parameters as this isn't going to be moving around.
const char* ssid = "DUNES_AT_THE_WEST";
const char* password = "PetNnfvfuCW7";

// Start a TCP Server on port 5045
WiFiServer server(3000);

void setup() {
  Serial.begin(115200);
  WiFi.hostname("esp8266");
  WiFi.begin(ssid,password);
  Serial.println("");
  //Wait for connection
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("Connected to "); Serial.println(ssid);
  Serial.print("IP Address: "); Serial.println(WiFi.localIP());
  Serial.println(WiFi.localIP());
 
  // Start the TCP server
  server.begin();
}
void loop() {
  // listen for incoming clients
  WiFiClient  client = server.available();
  if (client){
    Serial.println("Client connected");
    while (client.connected()){
        // Read the incoming TCP command
        String command = client.readStringUntil('\r');
        // Debugging display command
        client.println("->"+command);
    }
  }
 }
   
