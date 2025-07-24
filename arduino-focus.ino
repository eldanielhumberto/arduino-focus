#include <LiquidCrystal.h>

// LCD variables
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Timer variables
int focusMinutes = 25;
int focusSeconds = 0;

void setup() {
  lcd.begin(16, 2);

  lcd.print("Focus time");
}

void loop() {
  lcd.setCursor(0, 1);

  delay(1000);
  focusSeconds--;
  if (focusSeconds < 0) {
    focusMinutes--;
    focusSeconds = 59;
  }

  char timeText[6];
  sprintf(timeText, "%02d:%02d", focusMinutes, focusSeconds);
  
  lcd.print(timeText);
}