#pragma once
#include <Arduino.h>
#include <config.h>

namespace valve
{
    void init()
    {
        for (int currentPin = 1; currentPin <= RELAY_COUNT; currentPin++)
        {
            pinMode(RELAY_PINS[currentPin], OUTPUT);
            digitalWrite(RELAY_PINS[currentPin], HIGH);
        }
    }

    void open(int valveNumber) 
    {
        digitalWrite(valveNumber, LOW);
    }

    void close(int valveNumber) 
    {
        digitalWrite(valveNumber, HIGH);
    }
} // namespace valve
