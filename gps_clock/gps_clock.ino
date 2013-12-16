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

int utc_year;
byte utc_month; 
byte utc_day; 
byte utc_hour; 
byte utc_minutes; 
byte utc_second;
byte  utc_hundredths;
unsigned long utc_fix_age;

TinyGPS gps; //Initialize library
SoftwareSerial nss(RXPIN, TXPIN); //Initialize library and define I/O pins

void setup() {

	//nss.begin();
	nss.begin(GPSBAUD);

	GLCD.Init(NON_INVERTED); //initialize library
	GLCD.ClearScreen();

//Set time zone: offset = direction * longitude * (24 / 360), where direction = 1 for east, -1 for west, and longitude is [-180,180]
}

void loop() {
	// Date/time cracking ?
	gps.crack_datetime(&utc_year, &utc_month, &utc_day, &utc_hour, &utc_minutes, &utc_second, &utc_hundredths, &utc_fix_age);

	// Parse time from GPS signal 
	// Send to display
	GLCD.Puts(utc_second);
}
