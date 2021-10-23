#include <Arduino.h>
#include "Led.h"
#include "LedBlinker.h"

#define LED1_PIN 5
#define LED1_BLINK_DELAY 500
#define LED2_PIN 5
#define LED2_BLINK_DELAY 700
#define LED3_PIN 5
#define LED3_BLINK_DELAY 900

Led led1(LED1_PIN);
Led led2(LED2_PIN);
Led led3(LED3_PIN);
LedBlinker blinker1(led1, LED1_BLINK_DELAY);
LedBlinker blinker2(led2, LED2_BLINK_DELAY);
LedBlinker blinker3(led3, LED3_BLINK_DELAY);

void setup()
{
    blinker1.initLed();
    blinker2.initLed();
    blinker3.initLed();
}

void loop()
{
    blinker1.updateTime();
    blinker2.updateTime();
    blinker3.updateTime();
}