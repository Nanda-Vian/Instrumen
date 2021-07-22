#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include "ThingSpeak.h"

const char* ssid     = "ITS_MSBT";
const char* pass     = "jalapatih5juara";
char thingSpeakAddress[] = "api.thingspeak.com";


unsigned long channelID = 1327693;
char* writeAPIKey = "CTFRAPTGXXWCGM6I";

String myStatus = "";


// your network key index number (needed only for WEP)
WiFiClient  client;

void setup() {
  Serial.begin(9600);

  WiFi.mode(WIFI_STA);

  WiFi.begin(ssid, pass);

  ThingSpeak.begin(client);

}

void loop() {
  
  //Baca dokumen
  StaticJsonDocument<300> doc;
  
  Serial.write(100);
  DeserializationError error = deserializeJson(doc, Serial);

  JsonArray data = doc["data"];
   float tegangan = data[0]; 
   float arus = data[1]; 
   float suhu = data[2]; 
   float kecepatan = data[3];
   float power = data[4];
   
  // Connect or reconnect to WiFi
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      delay(5000);     
    } 
 ThingSpeak.setField(1, tegangan);
 ThingSpeak.setField(2, arus);
 ThingSpeak.setField(3, suhu);
 ThingSpeak.setField(4, kecepatan);
 ThingSpeak.setField(5, power);

  ThingSpeak.setStatus(myStatus);
  
  // write to the ThingSpeak channel
  int x = ThingSpeak.writeFields(channelID, writeAPIKey);
  delay(14999);
 
}
