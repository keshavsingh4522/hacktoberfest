#ifndef LED_BLINKER_H
#define LED_BLINKER_H

#include <Arduino.h>
#include "Led.h"

class LedBlinker
{
private:
    Led led;
    unsigned long lastLedBlinked;
    unsigned long blinkDelay;
    void __toggleLed();

public:
    LedBlinker();
    LedBlinker(Led &led);
    LedBlinker(Led &led, unsigned long ledBlinkDelay);
    void initLed();
    void updateTime();
    unsigned long getBlinkDelay();
    void setBlinkDelay(unsigned long blinkDelay);
    ~LedBlinker();
};

#endif