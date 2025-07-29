#include <LiquidCrystal.h>

// LCD pin
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Buzzer pin
const int buzzerPin = 9;

// App configuration
const int FOCUS_SESSION_MINUTES = 25;
const int FOCUS_SESSION_SECONDS = 0;

const int BREAK_SESSION_MINUTES = 5;
const int BREAK_SESSION_SECONDS = 0;

const int LONG_BREAK_SESSION_MINUTES = 15;
const int LONG_BREAK_SESSION_SECONDS = 0;
const int LONG_BREAK_INTERVAL = 4;

int pomodoroCount = 0;

// Time constants
const unsigned long TIMER_INTERVAL_MS = 1000;
const unsigned long BUZZER_TONE_DURATION_MS = 800;

// Timer variables
String lcdModeTitle = "";
int timerMinutes = FOCUS_SESSION_MINUTES;
int timerSeconds = FOCUS_SESSION_SECONDS;
bool isBuzzerActive = false;
int buzzerFrecuency = 0;

// Timer modes
enum Mode {
  FOCUS,
  BREAK,
  LONG_BREAK
};

// Timer states
unsigned long previousTimerMillis = 0;
unsigned long previousBuzzerMillis = 0;
Mode currentMode = FOCUS;

void setup() {
  lcd.begin(16, 2);
  changeMode(FOCUS);
}

void loop() {
  unsigned long currentTime = millis();

  updateTimer(currentTime);
  updateBuzzer(currentTime);
  showPomodorosCount();

  // Change timer mode 
  if (timerMinutes == 0 && timerSeconds == 0) {
    isBuzzerActive = true;
    previousBuzzerMillis = currentTime;

    if (currentMode == FOCUS) {
      pomodoroCount++;

      if (pomodoroCount > LONG_BREAK_INTERVAL - 1) {
        changeMode(LONG_BREAK);
      } else {
        changeMode(BREAK);
      }
    } else if (currentMode == BREAK) {
      changeMode(FOCUS);
    } else if (currentMode == LONG_BREAK) {
      pomodoroCount = 0;
      changeMode(FOCUS);
    }
  }
}

void updateTimer(unsigned long currentTime) {
  if (currentTime - previousTimerMillis >= TIMER_INTERVAL_MS) {
    timerSeconds--;
    if (timerSeconds < 0) {
      timerMinutes--;
      timerSeconds = 59;
    }

    previousTimerMillis = currentTime;
  }

  char timeText[6];
  sprintf(timeText, "%02d:%02d", timerMinutes, timerSeconds);

  lcd.setCursor(5, 1);
  lcd.print(timeText);
}

void updateBuzzer(unsigned long currentTime) {
  if (isBuzzerActive && (currentTime - previousBuzzerMillis <= BUZZER_TONE_DURATION_MS)) {
    tone(buzzerPin, buzzerFrecuency);
  } else {
    noTone(buzzerPin);
    isBuzzerActive = false;
  }
}

void showPomodorosCount() {
  lcd.setCursor(13, 0);
  lcd.print(String(pomodoroCount) + "/" + String(LONG_BREAK_INTERVAL));
}

void changeMode(Mode mode) {
  lcd.setCursor(0, 0);
  lcd.print("                "); 

  switch (mode) {
    case FOCUS:
      lcdModeTitle = "Focus";
      timerMinutes = FOCUS_SESSION_MINUTES;
      timerSeconds = FOCUS_SESSION_SECONDS;
      buzzerFrecuency = 659;

      currentMode = FOCUS;
      break;
    case BREAK:
      lcdModeTitle = "Break";
      timerMinutes = BREAK_SESSION_MINUTES;
      timerSeconds = BREAK_SESSION_SECONDS;
      buzzerFrecuency = 523;

      currentMode = BREAK;
      break;
    case LONG_BREAK:
      lcdModeTitle = "Long break";
      timerMinutes = LONG_BREAK_SESSION_MINUTES;
      timerSeconds = LONG_BREAK_SESSION_SECONDS;
      buzzerFrecuency = 784;

      currentMode = LONG_BREAK;
      break;
    default:
      lcdModeTitle = "UNKNOWN";
  }

  lcd.setCursor(0, 0);
  lcd.print(lcdModeTitle);
}
