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
