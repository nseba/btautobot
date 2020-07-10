#include <Arduino.h>
#include "buzzer.h"

const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;

int counter = 0;

void firstSection();
void secondSection();

void setupBuzzer()
{
    noTone(BUZZER_PIN);
}

void playTheme()
{
    //Play first section
    firstSection();

    //Play second section
    // secondSection();
}

void beep(int note, int duration)
{
    //Play tone on BUZZER_PIN
    tone(BUZZER_PIN, note, duration);

    //Play different LED depending on value of 'counter'
    if (counter % 2 == 0)
    {
        // digitalWrite(ledPin1, HIGH);
        delay(duration);
        // digitalWrite(ledPin1, LOW);
    }
    else
    {
        // digitalWrite(ledPin2, HIGH);
        delay(duration);
        // digitalWrite(ledPin2, LOW);
    }

    //Stop tone on BUZZER_PIN
    noTone(BUZZER_PIN);

    delay(50);

    //Increment counter
    counter++;
}

void firstSection()
{
    beep(a, 500);
    beep(a, 500);
    beep(a, 500);
    beep(f, 350);
    beep(cH, 150);
    beep(a, 500);
    beep(f, 350);
    beep(cH, 150);
    beep(a, 650);

    delay(500);

    beep(eH, 500);
    beep(eH, 500);
    beep(eH, 500);
    beep(fH, 350);
    beep(cH, 150);
    beep(gS, 500);
    beep(f, 350);
    beep(cH, 150);
    beep(a, 650);

    delay(500);
}

void secondSection()
{
    beep(aH, 500);
    beep(a, 300);
    beep(a, 150);
    beep(aH, 500);
    beep(gSH, 325);
    beep(gH, 175);
    beep(fSH, 125);
    beep(fH, 125);
    beep(fSH, 250);

    delay(325);

    beep(aS, 250);
    beep(dSH, 500);
    beep(dH, 325);
    beep(cSH, 175);
    beep(cH, 125);
    beep(b, 125);
    beep(cH, 250);

    delay(350);
}