#include <DHT.h>
#include <DHT_U.h>

#include "SoftwareSerial.h"

#define DHTPIN 2  
#define DHTTYPE DHT11 

float temperature;
float humidity;

DHT_Unified dht(DHTPIN, DHTTYPE);


#define rxPin 10
#define txPin 11
SoftwareSerial mySerial(rxPin, txPin);

void setup() 
{
  Serial.begin(9600);
  mySerial.begin(9600);
  dht.begin();  
}

void loop() {
  sensors_event_t event;
  dht.temperature().getEvent(&event);
 
  Serial.print("n0.val=");
  Serial.print(int(event.temperature));
  //Serial.print(14);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);

  /*
  mySerial.print(int(event.temperature));
  */
  
  dht.humidity().getEvent(&event);
  
  Serial.print("n1.val=");
  Serial.print(int(event.relative_humidity));
  //Serial.print(15);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
  
  /*
  mySerial.print(int(event.relative_humidity));
  */
  delay(1000);
  
}
