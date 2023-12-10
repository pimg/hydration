#pragma once
#include <Arduino.h>

namespace state
{
    enum class hydration : uint8_t
    {
        IDLE,         // defaults to 0
        GETTING_DATA, // defaults to 1
        PUMP_ON,      // defaults to 2
        OPEN_VALVE_1,   // defaults to 3
        OPEN_VALVE_2,   // defaults to 4
        OPEN_VALVE_3,   // defaults to 5
        OPEN_VALVE_4,   // defaults to 6
        PUMP_OFF,     // defaults to 7
    };

    void display(String currState)
    {
        static String prevState = "";

        if (currState != prevState)
        {
            Serial.println(currState);
            prevState = currState;
        }
    }

}