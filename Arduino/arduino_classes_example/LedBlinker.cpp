#include "LedBlinker.h"
#include "Led.h"

LedBlinker::LedBlinker() {} // donot

LedBlinker::LedBlinker(Led &led)
{
    this->led = led;
    this->lastLedBlinked = millis();
    this->blinkDelay = 500;
}

LedBlinker::LedBlinker(Led &led, unsigned long ledBlinkDelay)
{
    this->led = led;
    this->lastLedBlinked = millis();
    this->blinkDelay = ledBlinkDelay;
}

void LedBlinker::initLed()
{
    this->led.init();
}

void LedBlinker::__toggleLed()
{
    this->led.toggle();
}

void LedBlinker::updateTime()
{
    unsigned long timeNow = millis();
    if (timeNow - this->lastLedBlinked > this->blinkDelay)
    {
        this->lastLedBlinked = timeNow;
        this->__toggleLed();
    }
}

unsigned long LedBlinker::getBlinkDelay()
{
    return this->lastLedBlinked;
}

void LedBlinker::setBlinkDelay(unsigned long blinkDelay)
{
    this->blinkDelay = blinkDelay;
}

LedBlinker::~LedBlinker()
{
}