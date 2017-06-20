/*
   Meteorológiai állomás - Külső egység
   
   Egy DHT11-es szenzor, egy MH-RD esőérzékelő küldi a belső egységnek a mért adatokat.

   Készítette: Kotán Tamás Balázs - Magyar Arduino Labor
*/

#include <dht.h>

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); //RX, TX

int hom_adatlab = A1; // a dataPin nevű változó definiálása (a 9-es lábra kötöttük)
int eso_adatlab = A0;

dht DHT; // Létrehozzuk a DHT szenzorunkat


void setup()
{
  Serial.begin(115200);
  mySerial.begin(115200);


}
void loop()
{
  int readData = DHT.read11(hom_adatlab); // Kiolvassuk a szenzorból az értéket
  float t = DHT.temperature; // Megkapjuk a hőmérséklet értékét
  float h = DHT.humidity; // Megkapjuk a páratartalom értékét

  // A soros monitorra kiíratjuk az értékeket
  Serial.print("Homerseklet = ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("    Paratartalom = ");
  Serial.print(h);
  Serial.println(" % ");

  mySerial.print("Homerseklet = ");
  delay(1000);
  mySerial.print(t);
  delay(1000);
  mySerial.print(" *C ");
  delay(1000);
  mySerial.print("    Paratartalom = ");
  delay(1000);
  mySerial.print(h);
  delay(1000);
  mySerial.println(" % ");

  delay(1000);

  int esoszenzor = analogRead(eso_adatlab);
  Serial.print("Esoszenzor ertek = ");
  mySerial.print("Esoszenzor ertek = ");
  delay(1000);
  Serial.println(esoszenzor);
  mySerial.println(esoszenzor);
  delay(1000);

  if (1010 <= esoszenzor && esoszenzor <= 1023)
  {
    Serial.println("Nem esik");
    mySerial.println("Nem esik");
    Serial.println(" ");
    mySerial.println(" ");
  }
  else if (750 <= esoszenzor && esoszenzor <= 1009)
  {
    Serial.println("Csepereg");
    mySerial.println("Csepereg");
    Serial.println(" ");
    mySerial.println(" ");
  }
  else if (350 <= esoszenzor && esoszenzor <= 749)
  {
    Serial.println("Esik");
    mySerial.println("Esik");
    Serial.println(" ");
    mySerial.println(" ");
  }
  else
  {
    Serial.println("Szakad");
    mySerial.println("Szakad");
    Serial.println(" ");
    mySerial.println(" ");
  }

  delay(1000); // 1 mp-et késleltetünk, hogy mp-ként mérjen.

}





