
// include the library code:
#include <LiquidCrystal.h>
#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6
};

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// the board
int left_bound = 1;
int right_bound = 14;
int top = 0;
int bottom = 1;
int chance = 0;
// ball coords, dir: 0 == moving l-r, 1 == moving r-l
int dir = 0;
int x = 1;
int y = 0;
// paddle coords
int p1_x = 0;
int p1_y = 0;
int p1_btn = 3;
int p2_x = 15;
int p2_y = 0;
int p2_btn = 5;
// Audio
int buzzerPin = 13;
int buzzerDuration = 50;

bool isPlaying = true;

void setup() {
  Serial.begin(9600);
  pinMode(p1_btn, INPUT_PULLUP);
  pinMode(p2_btn, INPUT_PULLUP);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Start!");
  // Play intro tune
  for (int i = 0; i < 8; i += 1) {
    tone(buzzerPin, melody[i], 250);
    delay(250);
  }

  delay(1000);
  lcd.clear();

  lcd.setCursor(x, y);
  lcd.print('o');
  lcd.setCursor(p1_x, p1_y);
  lcd.print('|');
  lcd.setCursor(p2_x, p2_y);
  lcd.print('|');
}

static bool time_to_paint_frame() {
  static unsigned long measurement_timestamp = millis();

  if (millis() - measurement_timestamp > 200ul) {
    measurement_timestamp = millis();
    return (true);
  }
  return (false);
}

void reset_board() {
  // the board
  left_bound = 1;
  right_bound = 14;
  top = 0;
  bottom = 1;
  // ball direction, 0 == moving l-r, 1 == moving r-l
  dir = 0;
  // ball coords
  x = 1;
  y = 0;
  // paddle coords
  p1_x = 0;
  p1_y = 0;
  p1_btn = 3;
  p2_x = 15;
  p2_y = 0;
  p2_btn = 5;
}

void loop() {
  while (isPlaying) {
    // paddle movement
    if (digitalRead(p1_btn) == LOW) {
      tone(buzzerPin, melody[0], buzzerDuration);
      if (p1_y == 0) {
        p1_y = 1;
      } else {
        p1_y = 0;
      }
    }
    if (digitalRead(p2_btn) == LOW) {
      tone(buzzerPin, melody[3], buzzerDuration);
      if (p2_y == 0) {
        p2_y = 1;
      } else {
        p2_y = 0;
      }
    }
    if (time_to_paint_frame()) {
      // ball movement
      if (x >= right_bound) {
        if (p2_y != y) {
          lcd.clear();
          lcd.print("Left Wins!");
          delay(2000);
          isPlaying = false;
          lcd.clear();
          break;
        } else {
          dir = 1;  // return ball
          tone(buzzerPin, melody[7], 20);
        }
      }
      if (x <= left_bound)
        if (p1_y != y) {
          lcd.clear();
          lcd.print("Right Wins!");
          delay(2000);
          isPlaying = false;
          lcd.clear();
          break;
        } else {
          dir = 0;
          tone(buzzerPin, melody[6], 20);
        }
      if (dir == 0) {
        x++;
      }
      if (dir == 1) {
        x--;
      }
      chance++;
      if (chance % 7 == 0) {
        if (y == 0) {
          y = 1;
        } else {
          y = 0;
        }
      }
      lcd.clear();
      lcd.setCursor(p1_x, p1_y);
      lcd.print('|');
      lcd.setCursor(p2_x, p2_y);
      lcd.print('|');
      lcd.setCursor(x, y);
      lcd.print('o');
      tone(buzzerPin, melody[0], 10);
    }
  }

  while (!isPlaying) {
    lcd.setCursor(0, 0);
    lcd.print("Play again?");
    lcd.setCursor(0, 1);
    lcd.print("Yes?");
    lcd.setCursor(12, 1);
    lcd.print("No?");
    if (digitalRead(p1_btn) == LOW) {
      reset_board();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Start!");
      delay(1000);
      isPlaying = true;
      break;
    }
    if (digitalRead(p2_btn) == LOW) {
      reset_board();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Goodbye!");
      delay(5000);
      lcd.clear();
    }
  }
}
