#include <Arduino.h>
#include "Led.h"

void setup() {
  Led* led = new Led(13);
  led->switchOn();
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}