#include <NMEAGPS.h>
#include <Streamers.h>
#include <AltSoftSerial.h>

AltSoftSerial gpsPort;
static NMEAGPS gps;
static gps_fix fix;


static void GPSloop()
{
  while (gps.available( gpsPort )) {
    fix = gps.read();
    Serial.print(F("Location: "));
    Serial.print(fix.latitude(), 6);
    Serial.print(F(","));
    Serial.print(fix.longitude(), 6);
    Serial.print(F("  Kecepatan: "));
    Serial.print(fix.speed_kph());
    Serial.print(F(" Satelit: "));
    Serial.println(fix.satellites);
  }

}



void setup() {
  // put your setup code here, to run once:
  gpsPort.begin(9600);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  GPSloop();
}
