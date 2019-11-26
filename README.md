# RGB LED Controller

Bibliothek für MOSFET Ansteuerung über PWM

## Allgemein

**Board und Software**

- Arduino Mega 2560 R3 (Nachbau von Elegoo für 14,99€ auf [Amazon](https://www.amazon.de/gp/product/B01MA5BLQI/ref=ppx_yo_dt_b_asin_title_o00_s00))
- [Arduino IDE](https://www.arduino.cc/en/Main/Software)

## Einstellungen

**setInvert**(<_boolean_> invert) - default: false
- Invertiert alle LED Pins

**setUpdateInterval**(<_int_> interval) - default: (1000 / 60)
- Aktualisierungsinterval der LED Animationen.
- (1000 / <_updates_per_second_> )

**setNonBlocking**(<_boolean_> nonBlocking) - default: true
- (nicht) blockierender Modus (siehe Abschnitt "(Nicht) blockierender Modus")

## Farbe setzen

**setColor**(<_int_> red, <_int_> green, <_int_> blue, <_int_> fade_duration);
- red, green, blue: 0 - 255

## (Nicht) blockierender Modus

**setNonBlocking(true)**
- Kann verwendet werden, wenn neben der LED Steuerung noch andere Module ausgeführt werden müssen (z.B. WLAN beim ESP8266) oder die Befehle über den seriellen Port eingehen.

```c
void setup() {
   /* ... */
   
   led.setColor(255, 127, 12, 2000);
}

void loop() {
  led.execute(); // ohne diese Zeile werden die Fade-Anweisungen nicht ausgeführt
  
  /* oder über serielle Schnittstelle */
  if (Serial.available() > 0) {
  
    if (Serial.read() == '1') {
      led.setColor(255, 127, 12, 2000);
    }

    if (Serial.read() == '0') {
      led.setColor(255, 127, 12, 2000);
    }
    
  }
}
```
(Dauer von **einem** Loop-Durchlauf: < 1ms)

**setNonBlocking(false)**
- Kann verwendet werden, wenn nur das LED Modul alleine verwendet wird.

```c
void setup() {
   /* ... */
}

void loop() {
  led.setColor(255, 127, 12, 2000);
  delay(1000);
  led.setColor(0, 0, 0, 2000);
  delay(1000);
}
```
(Dauer von **einem** Loop-Durchlauf: 6000ms)

## Flackern beheben

Wenn die PWM Pins auf zu **niedrigen** oder **unterschiedlichen** Frequenzen betrieben werden, können die LED Leisten optisch flackern.

- Tipps für [Arduino Mega 2560 R3](http://sobisource.com/arduino-mega-pwm-pin-and-frequency-timer-control/)
- Informationen aus [offizieller Quelle](https://www.arduino.cc/en/Tutorial/SecretsOfArduinoPWM)
