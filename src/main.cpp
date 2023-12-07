#include <Arduino.h>
#include <pump.h>
#include <valves.h>
#include <states.h>
#include <alarm.h>

// put function declarations here:
void manageStates();

void setup()
{
  Serial.begin(9600);
  delay(1500);

  alarm::init();
  pump::init();
  valve::init();
}

void loop()
{
  // put your main code here, to run repeatedly:
  manageStates();
}

void manageStates()
{
  static unsigned long stateMillis = millis();

  static uint16_t valveDelay;

  static state::hydration currState = state::hydration::IDLE;

  switch (currState)
  {

  // Initial state (or final returned state)
  case state::hydration::IDLE:
    state::display("IDLE state");

    if (digitalRead(ALARM_PIN) == LOW)
    {
      // Move to next state
      Serial.println("Alarm fired moving to next state..");

      stateMillis = millis();
      currState = state::hydration::GETTING_DATA;
      alarm::setAlarmInFiveMins();
      break;
    }

    break;

  case state::hydration::GETTING_DATA:
    state::display("Getting data state");

    valveDelay = valve::calculateRuntime();
    if (valveDelay <= 4000)
    {
      Serial.println("no need to run the hydration system");
      stateMillis = millis();
      currState = state::hydration::IDLE;
      break;
    }

    stateMillis = millis();
    currState = state::hydration::PUMP_ON;
    break;

  case state::hydration::PUMP_ON:
    state::display("Starting Pump state");

    pump::start();

    if (millis() - stateMillis >= PUMP_DELAY)
    {
      stateMillis = millis();

      currState = state::hydration::OPEN_VALVE_1;
    }

    break;

  case state::hydration::OPEN_VALVE_1:
    state::display("Open valve 1 State");

    if (millis() - stateMillis >= valveDelay)
    {
      // Move to next state
      stateMillis = millis();
      currState = state::hydration::OPEN_VALVE_2;
    }

    break;

  case state::hydration::OPEN_VALVE_2:
    state::display("Open valve 2 state");
    // close previous valve

    if (millis() - stateMillis >= valveDelay)
    {

      // Move to next state
      stateMillis = millis();
      currState = state::hydration::OPEN_VALVE_3;
    }
    break;

  case state::hydration::OPEN_VALVE_3:
    state::display("Open valve 3 state");
    // close previous valve

    if (millis() - stateMillis >= valveDelay)
    {

      // Move to next state
      stateMillis = millis();
      currState = state::hydration::OPEN_VALVE_4;
    }
    break;

  case state::hydration::OPEN_VALVE_4:
    state::display("Open valve 4 state");
    // close previous valve

    if (millis() - stateMillis >= valveDelay)
    {

      // Move to next state
      stateMillis = millis();
      currState = state::hydration::PUMP_OFF;
    }
    break;

  case state::hydration::PUMP_OFF:
    state::display("Stopping Pump state");

    pump::stop();

    if (millis() - stateMillis >= PUMP_DELAY)
    {
      stateMillis = millis();

      currState = state::hydration::IDLE;
    }

    break;

  default:
    // Nothing to do here
    Serial.println("'Default' Switch Case reached - Error");
  }
}
