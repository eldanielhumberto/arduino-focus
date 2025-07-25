#include <LiquidCrystal.h>

// LCD variables
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// App configuration
const int FOCUS_SESSION_MINUTES = 25;
const int FOCUS_SESSION_SECONDS = 0;

const int BREAK_SESSION_MINUTES = 5;
const int BREAK_SESSION_SECONDS = 0;

const int LONG_BREAK_SESSION_MINUTES = 15;
const int LONG_BREAK_SESSION_SECONDS = 0;

const int LONG_BREAK_INTERVAL = 4;
int pomodoroCount = 0;

// Timer variables
String titleText = "";
int minutes = FOCUS_SESSION_MINUTES;
int seconds = FOCUS_SESSION_SECONDS;
unsigned long previousMillis = 0;

enum Mode {
  FOCUS,
  BREAK,
  LONG_BREAK
};

Mode currentMode = FOCUS;

void setup() {
  lcd.begin(16, 2);
  changeMode(FOCUS);
}

void loop() {
  timer();
  showPomodorosCount();

  if (minutes == 0 && seconds == 0) {
    if (currentMode == FOCUS) {
      pomodoroCount++;

      if (pomodoroCount > LONG_BREAK_INTERVAL - 1) {
        changeMode(LONG_BREAK);
      } else {
        changeMode(BREAK);
      }
    } else if (currentMode == BREAK) {
      changeMode(FOCUS);
    } else if (currentMode = LONG_BREAK) {
      pomodoroCount = 0;
      changeMode(FOCUS);
    }
  }
}

void timer() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > 1000) {
    seconds--;
    if (seconds < 0) {
      minutes--;
      seconds = 59;
    }

    previousMillis = currentMillis;
  }

  char timeText[6];
  sprintf(timeText, "%02d:%02d", minutes, seconds);

  lcd.setCursor(5, 1);
  lcd.print(timeText);
}

void showPomodorosCount() {
  lcd.setCursor(13, 0);
  lcd.print(String(pomodoroCount) + "/" + String(LONG_BREAK_INTERVAL));
}

void changeMode(Mode mode) {
  switch (mode) {
    case FOCUS:
      lcd.setCursor(5, 0);
      lcd.print("     ");

      titleText = "Focus";
      minutes = FOCUS_SESSION_MINUTES;
      seconds = FOCUS_SESSION_SECONDS;

      currentMode = FOCUS;
      break;
    case BREAK:
      titleText = "Break";
      minutes = BREAK_SESSION_MINUTES;
      seconds = BREAK_SESSION_SECONDS;

      currentMode = BREAK;
      break;
    case LONG_BREAK:
      titleText = "Long break";
      minutes = LONG_BREAK_SESSION_MINUTES;
      seconds = LONG_BREAK_SESSION_SECONDS;

      currentMode = LONG_BREAK;
      break;
    default:
      titleText = "UNKNOWN";
  }

  lcd.setCursor(0, 0);
  lcd.print(titleText);
}