#include "ledcontroller.h"

// Neue LEDController Instanz ueber die Pins (r, g, b) => (8, 9, 10) erzeugen
LEDController led(8, 9, 10);

void setup() {

  // Flackern verhindern: alle PWM Frequenzen für Arduino Mega auf 31.374 Hz setzen (ausser Pin 4 und 13)
  TCCR1B = (TCCR1B & 0xF8) | 0x01; // Pin 11, 12
  TCCR2B = (TCCR2B & 0xF8) | 0x01; // Pin 9, 10
  TCCR3B = (TCCR3B & 0xF8) | 0x01; // Pin 2, 3, 5
  TCCR4B = (TCCR4B & 0xF8) | 0x01; // Pin 6, 7, 8

  // OPTIONAL: Invertiere alle LED Pins (default: false)
  led.setInvert(false);

  // OPTIONAL: Aktualisierungsinterval (default: 1000 / 60)
  led.setUpdateInterval(1000 / 60);

  // OPTIONAL: nicht-blockierender Modus (default: true)
  led.setNonBlocking(true);

  // Farbe auf rgb(255, 127, 12) setzen, dabei 1 Sekunde faden
  led.setColor(255, 127, 12, 1000);
  
}

void loop() {

  // BENOETIGT (nur wenn setNonBlocking => true): führt alle Fading-Befehle aus
  led.execute();
  
}
