#include <SoftwareSerial.h>

#define RED_LED 5
#define GREEN_LED 6
#define BLUE_LED 9

SoftwareSerial hc06(2,3);

int brightness = 255;
int gBright = 0;
int rBright = 0;
int bBright = 0;
int fadeSpeed = 10;

void setup() {
    Serial.begin(9600);
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
    
    hc06.begin(9600);
}

void loop() {
  if (hc06.available()){
    char input = hc06.read();
    
    switch (input) {
      case 'r':
        Serial.write("red");
        _TurnOn(RED_LED);
        break;
      case 'b':
        Serial.write("blue");
        _TurnOn(BLUE_LED);
        break;
      case 'g':
        Serial.write("green");
        _TurnOn(GREEN_LED);
        break;
    }
  }
  delay(10);
  _TurnOff();
  delay(10);
}

void _TurnOn(int pin) {
    for (int i = 0; i < 256; i++) {
        analogWrite(pin, i);
        delay(fadeSpeed);
    }
}

void _TurnOff() {
  analogWrite(GREEN_LED, 0);
  analogWrite(RED_LED, 0);
  analogWrite(BLUE_LED, 0);
}
