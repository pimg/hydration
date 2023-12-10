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
    int calculateRuntime()
    {
        int pumpDelay = random(3, 8) * 1000;
        Serial.print("Pump delay:");
        Serial.println(pumpDelay);
        return pumpDelay;
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
