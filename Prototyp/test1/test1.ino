#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB};
IPAddress ip(192, 168, 2, 99);

EthernetServer server(80);

int L1B1 = 2;
int L1B2 = 3;
int L1B3 = 4;
int L1B4 = 5;
int L1B5 = 6;
int L1B6 = 7;
int L1B7 = 8;
int L1B8 = 9;

void setup() 

{
Ethernet.begin(mac, ip);
server.begin();

pinMode(L1B1,OUTPUT);
pinMode(L1B2,OUTPUT);

}

void loop() 
{

/*
digitalWrite(L1B1,HIGH);
digitalWrite(L1B2,LOW);

delay(1000);

digitalWrite(L1B1,LOW);
digitalWrite(L1B2,HIGH);

delay(1000);

*/
//digitalWrite(2,HIGH); digitalWrite(3,HIGH);

EthernetClient client = server.available();
if (client)
{
  while (client.connected())
  {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Typ: text/html");
    client.println("Connection: close");
    client.println();
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<meta http-equiv=\"refresh\" content=\"5\">");
    for (int analogChannel = 0; analogChannel < 6; analogChannel++)
    {
      int sensorReading = analogRead(analogChannel);
      client.println("Analogeingang ");
      client.println(analogChannel);
      client.println(" ist: ");
      client.println(sensorReading);
      client.println("<br />");
    }
    client.println("</html>");
    break;
    }
  client.stop();
  } 
}

//String prepareHtmlPage()
//{
//String html ="<!DOCTYPE html> <html> <head> <title>Titel unserer Webseite</title> <!-- kommentar --> </head> <body> <p>Inhalt der Webseite</p> </body> </html>";

//}
