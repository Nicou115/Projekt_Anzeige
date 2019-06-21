#include <Wire.h> //Um über Schnittstelle mit anderen zu kommunizieren
#include <WiFiNINA.h> //WLAN (Name im Netzwerk "espressif")

//Wifi
const char* ssid = "WLAN-8JCREQ";
const char* password = "9094182670536042";

//Licht
int portPin = 1; //Pinbelegung
int sendeDaten[8];//Senden; was wird an den anderen gesendet

void setup()
{
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() !=WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to the WiFi network");
  Serial.println(WiFi.localIP());
  Wire.begin();
}


void loop()

{
 for(int j = 0; j < 8;j++) 
 {
  sendeDaten[j] = HIGH;
  
  Wire.beginTransmission(4); //0,1,2,3,120-127 reserviert
  
  for(int i = 0; i < 8; i++)
  {
    Wire.write(sendeDaten[i]);
  }
 
  Wire.endTransmission();
  delay(1000);
  sendeDaten[j] = LOW;
  Wire.beginTransmission(4);

 
  for(int i = 0; i < 8; i++)
  {
    Wire.write(sendeDaten[i]);
  }
  Wire.endTransmission();
  delay(1000);
 }
}
