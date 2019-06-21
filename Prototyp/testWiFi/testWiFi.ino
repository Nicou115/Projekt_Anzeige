#include <ArduinoHttpClient.h>
#include <WiFiNINA.h>
#include "arduino_secrets.h"

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;

char serverAddress[] = "192.168.2.114"; //Server Address
int port = 8080;

WiFiClient wifi;
WebSocketClient client = WebSocketClient(wifi, serverAddress, port);
int status = WL_IDLE_STATUS;
int count = 0; 

void setup() {

  Serial.begin(9600);
  while(status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);

    status = WiFi.begin(ssid, pass);
  }

  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}

void loop() {
  Serial.println("starting WebSocket clint");
  client.begin();

  while(client.connected()) {
    Serial.print("Sending hello ");
    Serial.println(count);

    client.beginMessage(TYPE_TEXT);
    client.print("hello ");
    client.print(count);
    client.endMessage();

    count++;

    int messageSize = client.parseMessage();

    if (messageSize > 0) {
      Serial.println("Received a message:");
      
    }
  }
}
