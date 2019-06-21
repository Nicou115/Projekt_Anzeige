#include <SPI.h>
#include <WiFiNINA.h>
#include <WiFiUdp.h>


//Variablen

char wert;
int led = 13;

String read_string;
int string_size;
int status = WL_IDLE_STATUS;
char ssid[] = "WLAN-8JCREQ"; //  your network SSID (name)
char pass[] = "9094182670536042";    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;            // your network key Index number (needed only for WEP)

unsigned int localPort = 5001;      // local port to listen on

char packetBuffer[255]; //buffer to hold incoming packet
char  ReplyBuffer[] = "acknowledged";       // a string to send back

WiFiUDP Udp;

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);    
  }

  String fv = WiFi.firmwareVersion();
  if (fv != "1.1.0") {
    Serial.println("Please upgrade the firmware");
  }

  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(2000);
  }
  Serial.println("Connected to wifi");
  Serial.println(WiFi.localIP());

  Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial:
  Udp.begin(localPort);


pinMode(led,OUTPUT);

  
}

void loop() {
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    Serial.println(WiFi.localIP());}
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(2000);

  while (Serial.available()) {       // Wenn serielle Daten kommen, dann lesen
    wert = Serial.read();            // Daten in wert speichern
    if (wert== '1') {                // 1 heisst einschalten
      digitalWrite(led, HIGH);       // LED einschalten
      Serial.println("LED ist an");  // Rückgabe
    }
    else {
      digitalWrite(led, LOW);        // LED ausschalten
      Serial.println("LED ist aus"); // Rückgabe
    }
  }
 
}
