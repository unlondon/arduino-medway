/*
  RGB Dimmer
  Alternates R, G and B LED on for one second, then off for one second, repeatedly.
  The brightness depends on the position of the attached potentiometer

  This example code is in the public domain.

  modified 20 May 2016
  by Shawn Nock
 */

#define RED 6
#define GREEN 5
#define BLUE 3
 
int delay_ms = 100; // How long to keep LEDs on and off in milliseconds (sec/1000)
int brightness = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  brightness = analogRead(A0) >> 2;
  analogWrite(RED, brightness);
  delay(delay_ms);
  digitalWrite(RED, LOW);
  delay(delay_ms);
  analogWrite(GREEN, brightness);   
  delay(delay_ms);
  digitalWrite(BLUE, LOW);
  delay(delay_ms);
}
