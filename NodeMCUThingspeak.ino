
#include <ESP8266WiFi.h>

#include <ThingSpeak.h>

int  i;
WiFiClient client;

void setup()
{
  i = 0;
  Serial.begin(9600);
  ThingSpeak.begin(client);

  pinMode(2, OUTPUT);
    WiFi.disconnect();
  delay(300);
   WiFi.begin("your ssid wifi","your wifi password");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);

  }
  Serial.println("Connected!!");
pinMode(D4, OUTPUT);
pinMode(D3, OUTPUT);
}


void loop()
{

    i = (ThingSpeak.readIntField(123456,1,"EHSBADJAHBS123123"));//(your number channel, tabel number,"your API READ")
    if (i == 1) {
      digitalWrite(D4,LOW);
      digitalWrite(D3,LOW);

    }
    if (i == 0) {
      digitalWrite(D4,HIGH);
      digitalWrite(D3,HIGH);

    }
    delay(10000);

}
