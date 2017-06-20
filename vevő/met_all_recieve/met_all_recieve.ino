/*
   Meteorológiai állomás - Belső egység

   A külső egység által küldött adatokat elmenti egySD kártyára.

   Készítette: Kotán Tamás Balázs - Magyar Arduino Labor
*/

#include <SPI.h>
#include <SD.h>

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

File myFile;

const int CS_PIN = 10;


void setup()
{
  Serial.begin(115200);
  mySerial.begin(115200);

  Serial.print("SD kartya inicializalasa...");

  pinMode(SS, OUTPUT);

  if (!SD.begin(CS_PIN)) {
    Serial.println("Inicializalas nem sikerult!");
    return;
  }
  Serial.println("Inicializalas sikeres!.");

  Serial.println("mertadat.txt letrehozasa...");

  myFile = SD.open("mertadat.txt", FILE_WRITE);
}
void loop()
{



  myFile = SD.open("mertadat.txt", FILE_WRITE);
  if (myFile)
  {

    //int input = mySerial.parseInt();
    String input = mySerial.readString();
    myFile.print(input);
    Serial.println(input);
    delay(20);
    myFile.close();
  }
  else
  {
    Serial.println("nem sikerult megnyitni a mertadat.txt-t");
  }
}





