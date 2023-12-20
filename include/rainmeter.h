#pragma once
#include <Arduino.h>
#include <config.h>
#include <Servo.h>

namespace rainmeter
{
    Servo servo;

    void init() 
    {
        servo.attach(SERVO_PIN);
        servo.write(SERVO_INITIAL_ANGLE);
    }

    void openServo() 
    {
        servo.write(SERVO_OPEN_ANGLE);
    }

    void closeServo()
    {
        servo.write(SERVO_INITIAL_ANGLE);
    }

    int shouldRunHydration()
    {
        int sensorValue = analogRead(RAIN_METER_PIN);
        Serial.print("Value from Rain sensor: ");
        Serial.println(sensorValue);

        int relayDelay = 0;
        if (sensorValue <= RAIN_METER_THRESHOLD + 100) {
            // heeft geregend, pomp niet draaien
            relayDelay = 0;
        } else {
            relayDelay = VALVE_OPEN_TIME;
        }

        return relayDelay;
    }
}