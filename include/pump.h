#pragma once

#include <Arduino.h>
#include <config.h>

namespace pump
{
    void init(){
        pinMode(PUMP_PIN, OUTPUT);
        digitalWrite(PUMP_PIN, HIGH);
    };
    void start()
    {
        digitalWrite(PUMP_PIN, LOW);
    };

    void stop()
    {
        digitalWrite(PUMP_PIN, HIGH);
    }
} // namespace pump
