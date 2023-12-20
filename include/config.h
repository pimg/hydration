#pragma once
#include <Arduino.h>

// Om te configureren

// Alarm
const int ALARM_HOURS = 0;
const int ALARM_MINUTES = 3;

// Servo & regenmeter
const int SERVO_INITIAL_ANGLE = 15;
const int SERVO_OPEN_ANGLE = 180;
const int SERVO_DELAY = 1500; 

const int RAIN_METER_THRESHOLD = 0; // wel geregend

// kleppen en pompen
const int PUMP_DELAY = 500; // Hoeveel tijd in ms zit tussen het starten van de pomp en het openen van de eerste klep
const int VALVE_OPEN_TIME = 5000; // hoelang moeten de kleppen open blijven in ms


// Pin Aansluitingen Arduino Uno R3

const int ALARM_PIN = 12; //SQW pin op de clock module
const int RAIN_METER_PIN = A0; //Output analoog signaal regenmeter, ik heb dit gekoppeld aan een potentiometer
const int SERVO_PIN = 13;
const int RELAY_PINS[] = {5, 6, 7, 8, 9, 10}; //Relais pins
const int RELAY_COUNT = 5; //Niet gekoppeld aan de Arduino
const int PUMP_PIN = RELAY_PINS[0]; //Niet gekoppeld aan de Arduino, geeft aan dat pin 5 van het relais de pomp is
