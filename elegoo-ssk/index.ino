/*
  Lesson 5 - Digital Input
  I would call this my first C program. It's a simple program for
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
I combined the lesson on buttons with the lesson on the passive buzzer.
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

/*
Lesson 8+9
This is a simple script that combines lessons 8 and 9 to make a tilt-switch
controlled servo. I set up a red LED to be lit when the tilt swtich is upright,
and the built in led to be lit when the switch is off/down. Not sure what to do
with the servo yet, but it rotates one direction when the switch is on, and the
other way when the switch is off.
*/
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

const int ledPin = 8;//the led attach to

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);;//initialize the ledPin as an output
  pinMode(ledPin, OUTPUT);;//initialize the ledPin as an output
  pinMode(2,INPUT);
  digitalWrite(2, HIGH);
  Serial.begin(9600);
  myservo.attach(9);
}

void loop()
{
  int digitalVal = digitalRead(2);
  if(HIGH == digitalVal)
  {
    digitalWrite(LED_BUILTIN,HIGH);//turn builtin led on
    digitalWrite(ledPin,LOW);//turn the led off
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
                                        // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
  }
  }
  else
  {
    digitalWrite(LED_BUILTIN,LOW);//turn builtin led off
    digitalWrite(ledPin,HIGH);//turn the led on
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  }
}
/**********************************************/