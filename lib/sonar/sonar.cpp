#include <Arduino.h>
#include "sonar.h"

#define USONIC_DIV 58.0
#define MEASURE_SAMPLE_DELAY 5
#define MEASURE_SAMPLES 25
#define MEASURE_DELAY 250


long singleMeasurement(); 

void setupSonar()
{
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(500);
}

float getDistance()
{
    long measureSum = 0;
    for (int i = 0; i < MEASURE_SAMPLES; i++)
    {
        delay(MEASURE_SAMPLE_DELAY);
        measureSum += singleMeasurement();
    }
    return measureSum / MEASURE_SAMPLES;
}

long singleMeasurement()
{
    long duration = 0;
    // Measure: Put up Trigger...
    digitalWrite(TRIGGER_PIN, HIGH);
    // ... wait for 11 µs ...
    delayMicroseconds(11);
    // ... put the trigger down ...
    digitalWrite(TRIGGER_PIN, LOW);
    // ... and wait for the echo ...
    duration = pulseIn(ECHO_PIN, HIGH);
    return (long)(((float)duration / USONIC_DIV) * 10.0);
}