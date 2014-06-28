/* 
   GPS clock: https://github.com/JT9161/gps_clock
*/

#include <TinyGPS.h> //Parse NMEA input from GPS module
//#include <Time.h> //Time sync control
#include <SoftwareSerial.h> //Serial input control
#include <glcd_Buildinfo.h> //LCD control
#include <glcd.h> //LCD control
#include <glcd_Config.h> //LCD control

<<<<<<< HEAD
#define RXPIN 3 //Recieve GPS module on digital pin 0
#define TXPIN 2 //Transmit GPS module on digital pin 1
=======
#define RXPIN 3 //Recieve GPS module on digital pin 3
#define TXPIN 2 //Transmit GPS module on digital pin 2
>>>>>>> b24b3484e7c5d196fce401e955c6c560bf32aa3f
#define GPSBAUD 9600 //GPS baud rate

int utc_year;
byte utc_month; 
byte utc_day; 
byte utc_hour; 
byte utc_minutes; 
byte utc_second;
byte utc_hundredths;
unsigned long fix_age;
float latitude;
float longitude;
float course;
int direction;
signed int offset;

TinyGPS gps; //Initialize library
SoftwareSerial uart = SoftwareSerial(RXPIN, TXPIN); //Initialize library and define GPS module I/O pins


void setup() {
<<<<<<< HEAD
	uart.begin(GPSBAUD);
        Serial.begin(115200); //initialize library and begin communicating with computer serial monitor at 115200 bps
        Serial.println("begin");
=======
	uart.begin(GPSBAUD); 	// Start up library and begin communicating at GPSBAUD rate
        Serial.begin(115200); 	// Start up library and begin communicating with computer serial monitor at 115200 bps

>>>>>>> b24b3484e7c5d196fce401e955c6c560bf32aa3f
	/* Commented out for serial monitor usage
	GLCD.Init(NON_INVERTED); //initialize library
	GLCD.ClearScreen();
	*/

	}

void loop() {

  while ( uart.available() ) // if serail comm is available
  {
<<<<<<< HEAD
    Serial.println("available");
    if ( gps.encode( uart.read() ) ) //If serial comm is delivering and GPS can understand it
    {
        Serial.println("read");
=======
    if ( gps.encode( uart.read() ) ) //If serial comm is delivering and TinyGPS can understand it
    {
>>>>>>> b24b3484e7c5d196fce401e955c6c560bf32aa3f
        //Set time zone: offset = direction * longitude * (24 / 360), where direction = 1 for east, -1 for west, and longitude is [-180,180]
	gps.f_get_position(&latitude, &longitude); //Get latitude and longitude, in degrees
	course = gps.f_course(); //Get course in degrees
	if (course >= 0) 	 //Determine if direction is east or west for timezone formula`
		direction = 1;
	else
		direction = -1;
	offset = direction * longitude * (24 / 360); //Set timezone
  
        gps.crack_datetime(&utc_year, &utc_month, &utc_day, &utc_hour, &utc_minutes, &utc_second, &utc_hundredths); //get time from GPS
	//setTime(utc_hour, utc_minutes, utc_second, utc_day, utc_month, utc_year); //pass time from GPS to time control
	// adjustTime(); //apply calculated time zone 

	// Send to display
<<<<<<< HEAD
	Serial.println(utc_minutes);
        Serial.println(utc_second);
        Serial.println("");
        delay(2000);
=======
	Serial.print("Time (UTC): ");
        Serial.print(utc_hour);
        Serial.print(":");
	Serial.print(utc_minutes);
        Serial.print(":");
        Serial.print(utc_second);
	Serial.println("");
        
	Serial.print("Date (UTC): ");
	Serial.print(utc_year); 
	Serial.print("-"); 
	Serial.print(utc_month);
	Serial.print("-");
	Serial.print(utc_day);
	Serial.println("");

	Serial.print("latitude: ");
	Serial.print(latitude);
	Serial.println("");
	Serial.print("longitude: ");
	Serial.print(longitude);
	Serial.println("");
	Serial.println("");

>>>>>>> b24b3484e7c5d196fce401e955c6c560bf32aa3f
    }
  }  
}
