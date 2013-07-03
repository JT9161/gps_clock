/* GPS clock v0.1
   Last update: 2013-06-27
*/

#include <TinyGPS.h> //Parse NMEA input from GPS module
#include <glcd_Buildinfo.h> //LCD control
#include <glcd.h> //LCD control
#include <glcd_Config.h> //LCD control
#include <SoftwareSerial.h> //Serial input control
#include <Time.h> //Time sync control

#define RXPIN 0 //Recieve GPS module on digital pin 0
#define TXPIN 1 //Transmit GPS module on digital pin 1
#define GPSBAUD 9600 //GPS baud rate
TinyGPS gps; //Initialize library

int offset;

void setup() {
SoftwareSerial nss(RXPIN, TXPIN); //Initialize library and define pins
// Define GPS module as serial input
// Define I/O wires
// Define LCD as output
}

void loop() {
// GPS module input
// PArse time from GPS signal
  //Set time zone: offset = direction * longitude * 24 / 360, direction = 1 for east, -1 for west, longitude is (-180,180)
// Send to display
}
