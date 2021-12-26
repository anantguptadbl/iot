#include <SD.h>

/*Laser module with Arduino.
 * https://srituhobby.com
 */
 
#define laser 2
#define sensor 0
#define LED 4
#define buzzer 5
File open_file;

void setup() {
  Serial.begin(9600);
  pinMode(laser, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(laser, HIGH);
  output = createWriter( "data.txt" );
  
}

void loop() {
  //bool value = digitalRead(sensor);
  float value = analogRead(sensor);
  Serial.println(value);
  //Serial.printf("%s # %s", value, "_PLAIN_AIR");
  //open_file = SD.open("/Users/anantgupta/Documents/Arduino/laser_transmitter_receiver_analog/data/plain_air.txt", FILE_WRITE);
  //open_file.write(value);
  //open_file.close();
  output.println(value);
  if (value < 50) {
    digitalWrite(LED, HIGH);
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(LED, LOW);
    digitalWrite(buzzer, LOW);
  }
  
}

void keyPressed() 
{
output.flush(); // Writes the remaining data to the file
output.close(); // Finishes the file
exit(); // Stops the program
}
