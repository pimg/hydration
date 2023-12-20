#pragma once
#include "RTClib.h"
#include <config.h>

namespace alarm
{

    RTC_DS3231 rtc;

    void setAlarm()
    {

        // Disable and clear both alarms
        rtc.disableAlarm(1);
        rtc.disableAlarm(2);
        rtc.clearAlarm(1);
        rtc.clearAlarm(2);

        DateTime alarmSetAt = rtc.now() + TimeSpan(0, ALARM_HOURS, ALARM_MINUTES, 0); // Zet de tijd over vijf minuten TimeSpan(days, hours, minutes,seconds)
        // Print current time and date
        char buff[] = "Alarm set at: hh:mm:ss DDD, DD MMM YYYY";
        Serial.println(alarmSetAt.toString(buff));
        // Set alarm time
        rtc.setAlarm1(alarmSetAt, DS3231_A1_Minute); // zet het alarm op de eerder bepaalde tijd en zet de alarm modus. Uitleg hier https://garrysblog.com/2020/07/05/using-the-ds3231-real-time-clock-alarm-with-the-adafruit-rtclib-library/
    };

    void init()
    {
        pinMode(ALARM_PIN, INPUT_PULLUP);
        if (!rtc.begin())
        {
            Serial.println("Couldn't find RTC");
            Serial.flush();
            abort();
        }

        // Onderstaande kan je gebruiken om de Clock in te stellen. Het stelt de datum/tijd is op het tijdstip dat deze Arduino code is gecompileerd.
        // Wat betekend dat als je op de Upload knop klikt de clock van de arduino hooguit enkele seconden achterloopt op de datum/tijd van de computer.
        // Hoeft maar 1x worden uitgevoerd om de clock in te stellen, of als de batterij leeg is.
        // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

        rtc.writeSqwPinMode(DS3231_OFF); // Place SQW pin into alarm interrupt mode

        setAlarm();
    };

    

}