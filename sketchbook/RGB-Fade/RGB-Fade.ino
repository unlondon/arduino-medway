/*
  RGB Fade-in, Fade-out
  
  Alternates R, G and B LED on for one second, then off for one second, repeatedly.
  Fading in and out

  This example code is in the public domain.

  modified 20 May 2016
  by Shawn Nock
 */

#define RED 6
#define GREEN 5
#define BLUE 3

#define STEPS 8
#define MAX_BRIGHTNESS 255
#define BRIGHTNESS_INCREMENT (MAX_BRIGHTNESS / STEPS)
#define DELAY 100
#define DELAY_INCREMENT (DELAY / STEPS)

int leds[3] = {RED, GREEN, BLUE};

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  for (int i = 0; i < 3; i++) {
    int cur_led = leds[i];
    for (int x = 1; x <= STEPS; x++) {
      int cur_brightness = BRIGHTNESS_INCREMENT * x;
      analogWrite(cur_led, cur_brightness);
      delay(DELAY_INCREMENT * x);
    }
    for (int x = STEPS; x > 0; x--) {
      int cur_brightness = BRIGHTNESS_INCREMENT * x;
      analogWrite(cur_led, cur_brightness);
      delay(DELAY_INCREMENT * x);
    }
  }
  delay(DELAY);
}

