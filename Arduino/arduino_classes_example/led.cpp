#include "Led.h"

Led::Led() {} // Do not use

Led::Led(byte pin)
{
    this->_pin = pin;
}

void Led::init()
{
    pinMode(this->_pin, OUTPUT);
}

void Led::init(byte defaultState)
{
    this->init();
    if (defaultState == HIGH)
        this->on();
    else
        this->off();
}

void Led::on()
{
    this->_state = HIGH;
    this->controller();
}

void Led::off()
{
    this->_state = false;
    this->controller();
}

void Led::toggle()
{
    if (this->_state == LOW)
        this->on();
    else
        this->off();
}

void Led::controller()
{
    digitalWrite(this->_pin, this->_state);
}