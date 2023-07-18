#include <SoftwareSerial.h>
#include <TinyGPS++.h>

SoftwareSerial gpsSerial(10, 11);
TinyGPSPlus gps;

void setup()
{
  Serial.begin(9600);
  gpsSerial.begin(9600);
  Serial.println("Start: ");
}

void loop()
{
  if (gpsSerial.available() > 0)
  {
    char c = gpsSerial.read();
    if (gps.encode(c))
    {
      if (gps.location.isUpdated())
      {
        Serial.print(F("Location: "));
        Serial.print(gps.location.lat(), 6);
        Serial.print(F(","));
        Serial.print(gps.location.lng(), 6);
        Serial.println();

        Serial.print(F("Date/Time: "));
        Serial.print(gps.date.year());
        Serial.print(F("/"));
        Serial.print(gps.date.month());
        Serial.print(F("/"));
        Serial.print(gps.date.day());
        Serial.print(F(" "));

        long  hour = gps.time.hour();
        if((hour-6) < 0){
          Serial.print(24+(hour-6));
        }else{
          Serial.print(hour-6);
        }
        
        Serial.print(F(":"));
        Serial.print(gps.time.minute());
        Serial.print(F(":"));
        Serial.print(gps.time.second());
        Serial.println();
      }
      delay(300);

      }
    }
  }

