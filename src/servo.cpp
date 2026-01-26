#include "Servo.h"
#include "Arduino.h"

Servo servo;

void setup() {
  servo.attach(3);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int8_t rand_angle = random(0, 181);
  int16_t delayed_time = 500;
  digitalWrite(LED_BUILTIN, HIGH);
  delay(delayed_time);
  servo.write(rand_angle);
  digitalWrite(LED_BUILTIN, LOW);
  delay(delayed_time);
}
