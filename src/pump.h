#pragma once

#include <Arduino.h>

namespace pump
{
    int calculateRuntime()
    {
        int pumpDelay = random(3, 8) * 1000;
        Serial.print("Pump delay:");
        Serial.println(pumpDelay);
        return pumpDelay;
    }
} // namespace pump
