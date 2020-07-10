#include <Arduino.h>
#include "../lib/motor/motor.h"
#include "../lib/sonar/sonar.h"
#include "../lib/buzzer/buzzer.h"

void setup() {  
  Serial.begin(9600);
  setupMotor();
  setupSonar();
  setupBuzzer();
  delay(2000);
  Serial.println("Hello World!");
  playTheme();
}

void loop() {
    float distance = getDistance();
    Serial.println(distance);

    // if(distance > 100) {
    //   go(255,255);
    // } else {
    //   go(255,-255);
    // }
    // tone(BUZZER_PIN, 1000, 70);
    delay(500);
}
