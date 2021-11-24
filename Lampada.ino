#define BLYNK_PRINT Serial

#include "ESP8266_Lib.h"
#include "BlynkSimpleShieldEsp8266.h"

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "zf-9_a-Pa0K3oX2g7W81aiNN9yTvh719";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "M A R T I N S";
char pass[] = "AsenhaéCarlinha";

void Lampada()
{

  int rele = digitalRead(9); 
  if (rele == 1) 
  {
    Serial.println("Testando..."); //Imprime por el monitor serial
    Blynk.email("carmartins04@hotmail.com", "LAMPADA FOI ACESA", "AVISO: Lampada do ambiente foi acesa nesse instante");
    delay(1000);
  }
}


// or Software Serial on Uno, Nano...
#include "SoftwareSerial.h"
SoftwareSerial EspSerial(10,11); // RX, TX

// Your ESP8266 baud rate:
#define ESP8266_BAUD 9600

ESP8266 wifi(&EspSerial);

void setup()
{
  // Debug console
  Serial.begin(9600);
  
  delay(10);
  
  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);
  
  Blynk.begin(auth, wifi, ssid, pass);
  
  
}

void loop(){
  Lampada();
  Blynk.run();
}