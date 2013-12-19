/* 
   GPS clock: https://github.com/JT9161/gps_clock
*/

#include <TinyGPS.h> //Parse NMEA input from GPS module
//#include <Time.h> //Time sync control
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
byte utc_hundredths;
//unsigned long fix_age;
//int ver = TinyGPS::library_version();
float latitude;
float longitude;
float course;
int direction;

TinyGPS gps; //Initialize library
SoftwareSerial hard_serial(RXPIN, TXPIN); //Initialize library and define I/O pins

void setup() {
	hard_serial.begin(GPSBAUD);
	
	/* Commented out for serial monitor usage
	GLCD.Init(NON_INVERTED); //initialize library
	GLCD.ClearScreen();
	*/

	//Set time zone: offset = direction * longitude * (24 / 360), where direction = 1 for east, -1 for west, and longitude is [-180,180]
	gps.f_get_position(&latitude, &longitude);
	course = gps.f_course();
	if course >= 0
		direction = 1;
	else
		direction = -1;
}

void loop() {
	gps.crack_datetime(&utc_year, &utc_month, &utc_day, &utc_hour, &utc_minutes, &utc_second, &utc_hundredths);

	// Send to display
	GLCD.print(utc_second);
}
