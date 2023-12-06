#include <Arduino.h>

// put function declarations here:
void displayState(String currState);
void manageStates();
int calculatePumpRuntime();

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

  enum class hydrationState : uint8_t
  {
    IDLE,         // defaults to 0
    GETTING_DATA, // defaults to 1
    RUN_PUMP_1,   // defaults to 2
    RUN_PUMP_2,   // defaults to 3
    RUN_PUMP_3,   // defaults to 4
    RUN_PUMP_4,   // defaults to 5
  };

  static hydrationState currState = hydrationState::IDLE;

  switch (currState)
  {

  // Initial state (or final returned state)
  case hydrationState::IDLE:
    displayState("IDLE state");

    // Move to next state
    currState = hydrationState::GETTING_DATA;

    break;

  case hydrationState::GETTING_DATA:
    displayState("Getting data state");

    pumpDelay = calculatePumpRuntime();
    if(pumpDelay <= 4000)
    {
      Serial.println("no need to run the hydration system");
      stateMillis = millis();
      currState = hydrationState::IDLE;
      break;
    }

    stateMillis = millis();
    currState = hydrationState::RUN_PUMP_1;
    break;

  case hydrationState::RUN_PUMP_1:
    displayState("Run Pump 1 State");

    if (millis() - stateMillis >= pumpDelay)
    {
      // Move to next state
      stateMillis = millis();
      currState = hydrationState::RUN_PUMP_2;
    }

    break;

  case hydrationState::RUN_PUMP_2:
    displayState("Run Pump 2 state");

    if (millis() - stateMillis >= pumpDelay)
    {

      // Move to next state
      currState = hydrationState::IDLE;
    }
    break;

  default:
    // Nothing to do here
    Serial.println("'Default' Switch Case reached - Error");
  }
}

int calculatePumpRuntime()
{
  int pumpDelay = random(3, 8) * 1000;
  Serial.print("Pump delay:");
  Serial.println(pumpDelay);
  return pumpDelay;
}

void displayState(String currState)
{
  static String prevState = "";

  if (currState != prevState)
  {
    Serial.println(currState);
    prevState = currState;
  }
}