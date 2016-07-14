      /*
  RGB Blink
  Alternates R, G and B LED; vary the frequncy by the position of the potentiometer

  Only activate the lights if the tilt switch is latched.

  This example code is in the public domain.

  modified 20 May 2016
  by Shawn Nock
 */

#define RED 3
#define GREEN 4
#define BLUE 5
#define IN 8
 
int delay_ms = 1000; // How long to keep LEDs on and off in milliseconds (sec/1000)

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(IN, INPUT_PULLUP);
}

// the loop function runs over and over again forever
void loop() {
  if (digitalRead(IN) == LOW) {
    delay_ms = analogRead(A0);
    digitalWrite(RED, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(delay_ms);           // wait for a second
    digitalWrite(RED, LOW);    // turn the LED off by making the voltage LOW
    delay(delay_ms);           // wait for a second
    digitalWrite(GREEN, HIGH);   
    delay(delay_ms);
    digitalWrite(GREEN, LOW);
    delay(delay_ms);
    digitalWrite(BLUE, HIGH);
    delay(delay_ms);
    digitalWrite(BLUE, LOW);
    delay(delay_ms);
  } else {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
  }
}


