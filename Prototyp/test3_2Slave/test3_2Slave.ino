#include <Wire.h>

byte eingabeDaten[8];
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
  pinMode(L1B1,OUTPUT);
  pinMode(L1B2,OUTPUT);
  pinMode(L1B3,OUTPUT);
  pinMode(L1B4,OUTPUT);
  pinMode(L1B5,OUTPUT);
  pinMode(L1B6,OUTPUT);
  pinMode(L1B7,OUTPUT);
  pinMode(L1B8,OUTPUT);
  
  Wire.onReceive(receiveEvent);
  Wire.begin(4); //Slaveadresse
  }

void loop()
{
  delay(50);
}

void receiveEvent(int howMany1)
{
  for(int i = 0; i<8;i++)
  {
  eingabeDaten[i] = Wire.read();
  }
  digitalWrite(L1B1,eingabeDaten[0]);
  digitalWrite(L1B2,eingabeDaten[1]);
  digitalWrite(L1B3,eingabeDaten[2]);
  digitalWrite(L1B4,eingabeDaten[3]);
  digitalWrite(L1B5,eingabeDaten[4]);
  digitalWrite(L1B6,eingabeDaten[5]);
  digitalWrite(L1B7,eingabeDaten[6]);
  digitalWrite(L1B8,eingabeDaten[7]);
}
