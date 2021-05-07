#define RED_LED 6
#define BLUE_LED 5
#define GREEN_LED 7

int brightness = 255;
int gBright = 0;
int rBright = 0;
int bBright = 0;
int fadeSpeed = 10;

void setup() {
    Serial.begin(9600);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
}

void loop() {
    _TurnOn(RED_LED);
    _TurnOn(BLUE_LED);
    _TurnOn(GREEN_LED);
    _TurnOff();
}

void _TurnOn(int pin) {
    for (int i = 0; i < 256; i++) {
        analogWrite(pin, i);
        delay(fadeSpeed);
    }
}

void _TurnOff() {
    for (int i = 0; i < 256; i++) {
        analogWrite(GREEN_LED, brightness);
        analogWrite(RED_LED, brightness);
        analogWrite(BLUE_LED, brightness);

        brightness -= 1;
        delay(fadeSpeed);
    }
}
