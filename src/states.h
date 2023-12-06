#pragma once
#include <Arduino.h>

namespace state
{
    enum class hydration : uint8_t
    {
        IDLE,         // defaults to 0
        GETTING_DATA, // defaults to 1
        RUN_PUMP_1,   // defaults to 2
        RUN_PUMP_2,   // defaults to 3
        RUN_PUMP_3,   // defaults to 4
        RUN_PUMP_4,   // defaults to 5
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