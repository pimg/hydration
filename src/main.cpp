#include <Arduino.h>
#include <pump.h>
#include <states.h>

// put function declarations here:
void manageStates();

void setup()
{
  Serial.begin(9600);
  delay(1500);
}

void loop()
{
  // put your main code here, to run repeatedly:
  manageStates();
}

void manageStates()
{
  static unsigned long stateMillis = millis();

  static uint16_t pumpDelay;

  

  static state::hydration currState = state::hydration::IDLE;

  switch (currState)
  {

  // Initial state (or final returned state)
  case state::hydration::IDLE:
    state::display("IDLE state");

    // Move to next state
    currState = state::hydration::GETTING_DATA;

    break;

  case state::hydration::GETTING_DATA:
    state::display("Getting data state");

    pumpDelay = pump::calculateRuntime();
    if (pumpDelay <= 4000)
    {
      Serial.println("no need to run the hydration system");
      stateMillis = millis();
      currState = state::hydration::IDLE;
      break;
    }

    stateMillis = millis();
    currState = state::hydration::RUN_PUMP_1;
    break;

  case state::hydration::RUN_PUMP_1:
    state::display("Run Pump 1 State");

    if (millis() - stateMillis >= pumpDelay)
    {
      // Move to next state
      stateMillis = millis();
      currState = state::hydration::RUN_PUMP_2;
    }

    break;

  case state::hydration::RUN_PUMP_2:
    state::display("Run Pump 2 state");

    if (millis() - stateMillis >= pumpDelay)
    {

      // Move to next state
      stateMillis = millis();
      currState = state::hydration::IDLE;
    }
    break;

  default:
    // Nothing to do here
    Serial.println("'Default' Switch Case reached - Error");
  }
}
