#pragma once
#include <Arduino.h>

const int ALARM_PIN = 12; //SQW pin op de clock module
// const int RAIN_METER_PIN = A0; //Output analoog signaal regenmeter, ik heb dit gekoppeld aan een potentiometer
// const int BUTTON_PIN = 2; // gekoppeld met een knop via een 100Nf (104) keramische condensator, zie foto1
// const int LED_PIN = 3; //gekoppeld via 1KOhm weerstand aan een led (indicator die aangeeft of de relais 2x zo lang aan moeten), zie foto2

// const int RELAY_PINS[] = {5, 6, 7, 8, 9, 10}; //Relais pins
// const int RELAY_COUNT = 5; //Niet gekoppeld aan de Arduino
// const int RAIN_METER = RELAY_PINS[5]; //Niet gekoppeld aan de Arduino, dit betekend dat pin 10 van het relais de klep opent om de regenmeter te legen.
// const int PUMP = RELAY_PINS[0]; //Niet gekoppeld aan de Arduino, geeft aan dat pin 5 van het relais de pomp is
// const int INITIAL_VALVE_PIN = RELAY_PINS[1]; //Niet gekoppeld aan de Arduino
// const int FINAL_VALVE_PIN = RELAY_PINS[4]; //Niet gekoppeld aan de Arduino