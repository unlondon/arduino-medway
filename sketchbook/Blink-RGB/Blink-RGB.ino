/*
  RGB Blink
  Alternates R, G and B LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.

  modified 20 May 2016
  by Shawn Nock
 */

#define RED 6
#define GREEN 5
#define BLUE 3
#define DELAY_MS 1000 // How long to keep LEDs on and off in milliseconds (sec/1000)

void setup() {
  // initialize digital pin 13 as an output.
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  digitalWrite(RED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(DELAY_MS);           // wait for a second
  digitalWrite(RED, LOW);    // turn the LED off by making the voltage LOW
  delay(DELAY_MS);           // wait for a second
  digitalWrite(GREEN, HIGH);   
  delay(DELAY_MS);
  digitalWrite(GREEN, LOW);
  delay(DELAY_MS);
  digitalWrite(BLUE, HIGH);
  delay(DELAY_MS);
  digitalWrite(BLUE, LOW);
  delay(DELAY_MS);
}
