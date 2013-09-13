/* GPS clock v0.2
   Last update: 2013-08-05
*/

#include <TinyGPS.h> //Parse NMEA input from GPS module
#include <Time.h> //Time sync control
#include <SoftwareSerial.h> //Serial input control
#include <glcd_Buildinfo.h> //LCD control
#include <glcd.h> //LCD control
#include <glcd_Config.h> //LCD control

#define RXPIN 0 //Recieve GPS module on digital pin 0
#define TXPIN 1 //Transmit GPS module on digital pin 1
#define GPSBAUD 9600 //GPS baud rate

signed int offset;
unsigned long date_utc 
unsigned long time_utc
unsigned long date_offset
unsigned long time_offset

TinyGPS gps; //Initialize library
SoftwareSerial nss(RXPIN, TXPIN); //Initialize library and define pins

void setup() {
Serial.begin();
nss.begin(GPSBAUD);

GLCD.Init(NON_INVERTED); //initialize library
GLCD.ClearScreen();

//Set time zone: offset = direction * longitude * 24 / 360, where direction = 1 for east, -1 for west, longitude is (-180,180)
}

void loop() {
// Date/time cracking ?
unsigned long date_utc = gps.get_datetime(&date);
unsigned long time_utc = gps.get_datetime(&time);
// Parse time from GPS signal
  

// Send to display
GLCD.Puts(time);
}
