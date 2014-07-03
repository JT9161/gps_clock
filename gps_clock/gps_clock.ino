/* 
GPS clock: https://github.com/JT9161/gps_clock
TODO: Identify altitude, course errors. Start time sync.
*/

#include <TinyGPS.h> 		//Parse NMEA input from GPS module
#include <Time.h> 		//Time sync control
#include <SoftwareSerial.h> 	//Serial input control
#include <glcd.h> 		//LCD control
//#include <glcd_Buildinfo.h> 	//LCD control
//#include <glcd_Config.h> 	//LCD control
#include "fonts/SystemFont5x7.h"

#define RXPIN 2 		//Recieve GPS module on digital pin 3
#define TXPIN 3 		//Transmit GPS module on digital pin 2
#define GPSBAUD 9600 		//GPS baud rate

int utc_year;
byte utc_month; 
byte utc_day; 
byte utc_hour; 
byte utc_minutes; 
byte utc_second;
byte utc_hundredths;
float fix_age;
float latitude;
float longitude;
float course;
int direction;
signed int offset;
//int altitude;
//int sats;

TinyGPS gps; 			//Initialize library
SoftwareSerial uart = SoftwareSerial(RXPIN, TXPIN); //Initialize library and define GPS module I/O pins

void setup() {
        GLCD.Init(NON_INVERTED); 		//initialize library
	GLCD.SelectFont(SystemFont5x7);
        GLCD.print("Acquiring GPS fix. This may take some time.");
  	
        uart.begin(GPSBAUD); 	// Start up library and begin communicating at GPSBAUD rate
        //Serial.begin(115200); 	// Start up library and begin communicating with computer serial monitor at 115200 bps
}

void loop() {  
  while ( uart.available() )	// if serail comm is available
  {
    if ( gps.encode( uart.read() ) ) //If serial comm is delivering and TinyGPS can understand it
    {
	GLCD.CursorTo(0,-32);    
        //Set time zone: offset = direction * longitude * (24 / 360), where direction = 1 for east, -1 for west, and longitude is [-180,180]
	gps.f_get_position(&latitude, &longitude); //Get latitude and longitude, in degrees

	//Determine if direction is east or west for timezone formula
	course = gps.course(); 
	if (course >= 0) 	 
		direction = 1;
	else
		direction = -1;
	offset = direction * longitude * (24 / 360); //Set timezone
  
        gps.crack_datetime(&utc_year, &utc_month, &utc_day, &utc_hour, &utc_minutes, &utc_second, &utc_hundredths); //get time from GPS
	
	//altitude = gps.altitude(); 	//Get altitude
	//sats = gps.satellites(); 	//Get satellites in view

	setTime(utc_hour, utc_minutes, utc_second, utc_day, utc_month, utc_year); //pass time from GPS to time control
        adjustTime(-7*3600); 		//Set time zone (manually)

	// Send to display
        GLCD.print("UTC: ");
        GLCD.print(hourFormat12());
        GLCD.print(':');
        GLCD.print(minute());
        GLCD.print(':');
        GLCD.print( second() );
        GLCD.println();
        
	setTime(utc_hour, utc_minutes, utc_second, utc_day, utc_month, utc_year); //pass time from GPS to time control
        GLCD.print("Local: ");
        GLCD.print(hourFormat12());
        GLCD.print(':');
        GLCD.print(minute());
        GLCD.print(':');
        GLCD.print( second() );
        GLCD.println();
		
	GLCD.print("Latitude: ");
        GLCD.print(latitude);
        GLCD.println();
        GLCD.print("Longitude: ");
        GLCD.print(longitude);
	GLCD.println();
	/*
	GLCD.println( altitude);
	GLCD.println( sats );
	*/
     }
  }  
}
