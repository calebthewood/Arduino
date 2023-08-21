/*
  Lesson 5 - Digital Input
  Notes - I would call this my first C program. It's a simple program for
  an arduino. with an LED and two btn inputs. Press btn A for one effect,
  press btn B for a different effect.
 */

int ledPin = 5;
int buttonApin = 9;
int buttonBpin = 8;

byte leds = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
}

void loop()
{
  if (digitalRead(buttonApin) == LOW)
  {
    for (int i = 0; i < 3; i += 1)
    {
      digitalWrite(ledPin, HIGH);
      delay(250);
      digitalWrite(ledPin, LOW);
      delay(250);
    }
  }
  if (digitalRead(buttonBpin) == LOW)
  {
    for (int i = 0; i < 3; i += 1)
    {
      digitalWrite(ledPin, HIGH);
      delay(500);
      digitalWrite(ledPin, LOW);
      delay(500);
    }
  }
}


/*
Lesson 7
Notes - I combined the lesson on buttons with the lesson on the passive buzzer.
the result is a 4 note keyboard. The code is simple, but works for 4 static btns
Would be intersting to see how dynamic I can get with 4 btns
*/

#include "pitches.h"

int ledPin = 5;
int buttonApin = 9;
int buttonBpin = 8;
int buttonCpin = 10;
int buttonDpin = 11;
int buzzerPin = 12;

byte leds = 0;

// notes in the melody:
int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
int duration = 50;  // 500 miliseconds

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
  pinMode(buttonCpin, INPUT_PULLUP);
  pinMode(buttonDpin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(buttonApin) == LOW)
  {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, melody[0], duration);
    digitalWrite(ledPin, LOW);
  }
  else if (digitalRead(buttonBpin) == LOW)
  {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, melody[2], duration);
    digitalWrite(ledPin, LOW);
  }
  else if (digitalRead(buttonCpin) == LOW)
  {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, melody[3], duration);
    digitalWrite(ledPin, LOW);
  }
    else if (digitalRead(buttonDpin) == LOW)
  {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, melody[4], duration);
    digitalWrite(ledPin, LOW);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}