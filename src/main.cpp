#include <Arduino.h>
#include "main.h"
#include "Led.h"
#include "header.h"

void setup() {
  Led* led = new Led(13);
  led->switchOn();
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}