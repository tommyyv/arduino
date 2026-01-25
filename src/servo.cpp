#include "Servo.h"
#include "Arduino.h"
#include "pins_arduino.h"

Servo servo;

void setup() {
  // pin mode
  // port
  // pin
  servo.attach(3);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int8_t rand_angle = random(0, 181);
  int16_t delayed_time = 500;
  digitalWrite(LED_BUILTIN,
               HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(delayed_time); // wait for a second
  // for every delay, execute the randomizer to get a random value from 0 - 180.
  // write this value to servo.write(rand_angle)
  servo.write(rand_angle);
  digitalWrite(LED_BUILTIN, LOW);
  delay(delayed_time); // wait for a second
}
