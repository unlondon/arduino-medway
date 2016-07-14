/*
  RGB Blink
  Alternates R, G and B LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.

  modified 20 May 2016
  by Shawn Nock
 */

#include <IRremote.h>
#include "medway-remote.h" // Button definitions for medway kit remote

#define RED 6
#define GREEN 5
#define BLUE 3
#define IR_PIN 2
#define BUZZER 10

bool power = false; // Variable to store power on/off state

/* Initialize the irrecv part of the IRremote  library */
IRrecv irrecv(IR_PIN);
decode_results results; // This will store our IR received codes

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    uint16_t resultCode = (results.value & 0xFFFF);
    switch (resultCode) {
      case POWER:
        power ^= 1; // Toggle power
        if (!power) {
          digitalWrite(RED, LOW);
          digitalWrite(GREEN, LOW);
          digitalWrite(BLUE, LOW);
        } else {
          digitalWrite(RED, HIGH);
          digitalWrite(GREEN, HIGH);
          digitalWrite(BLUE, HIGH);
        }
        break;
      case ONE:
        digitalWrite(RED, !digitalRead(RED));
        break;
      case TWO:
        digitalWrite(GREEN, !digitalRead(GREEN));
        break;
      case THREE:
        digitalWrite(BLUE, !digitalRead(BLUE));
        break;
      case MUTE:
        digitalWrite(BUZZER, !digitalRead(BUZZER));
        break;
      default:
        break;
    }
    irrecv.resume();
  }
}



