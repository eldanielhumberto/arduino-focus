# 🍅 Arduino Pomodoro Timer ⏰

A simple and efficient Arduino Pomodoro Timer that cycles through **Focus** (25 min), **Break** (5 min), and **Long Break** (15 min) sessions. It uses a 16x2 LCD to display the current mode and remaining time, and a piezoelectric buzzer to notify mode changes with distinct tones (523 Hz, 659 Hz, 784 Hz). Perfect for boosting productivity with the Pomodoro Technique. 🚀

## ✨ Features

- **Pomodoro Modes**: Focus (25 min), Break (5 min), Long Break (15 min, after 4 Pomodoros). 🔄
- **LCD Display**: Shows the mode (`lcdModeTitle`) and time remaining (MM:SS). 📟
- **Audio Notifications**: 800 ms tones with unique frequencies (C5: 523 Hz, E5: 659 Hz, G5: 784 Hz). 🎵
- **Non-blocking Timing**: Uses `millis()` for smooth operation. ⏱️
- **Pomodoro Counter**: Displays completed sessions on the LCD (e.g., "2/4"). 📊
- **Modular Code**: Organized with clear functions (`updateTimer`, `updateBuzzer`, `showPomodorosCount`, `changeMode`). 🛠️

## 🛠️ Requirements

### Hardware

- **Arduino Board** (e.g., Arduino Uno) 🖥️
- **16x2 LCD** with parallel interface (compatible with LiquidCrystal) 📺
- **Piezoelectric Buzzer** connected to pin 9 🔊
- Wires and breadboard for connections 🔌

### Software

- **Arduino IDE** (version 2.0 or higher recommended) 💻
- **LiquidCrystal Library** (included with Arduino IDE) 📚

## 🔌 Hardware Setup

1. **Connect LCD**:

   - `rs` → Pin 12 (Register Select)
   - `en` → Pin 11 (Enable)
   - `d4` → Pin 5, `d5` → Pin 4, `d6` → Pin 3, `d7` → Pin 2
   - `VSS` → GND, `VDD` → 5V, connect a potentiometer to `V0` for contrast adjustment

2. **Connect Buzzer**:

   - Positive terminal → Pin 9 (`buzzerPin`), negative terminal → GND

3. **Verify Connections**:
   - Ensure the buzzer supports the frequencies (523 Hz, 659 Hz, 784 Hz).

## 📦 Installation

1. **Download the Code**:

   - Copy `pomodoro_timer.ino` to the Arduino IDE.

2. **Install LiquidCrystal Library**:

   - In the Arduino IDE, go to `Tools > Manage Libraries` and search for `LiquidCrystal`.

3. **Upload the Code**:
   - Connect your Arduino to the computer, select the board and port, and upload the code.

## 🚀 Usage

1. **Start**:

   - On power-up, the timer starts in **Focus** mode (25 minutes), displaying "Focus" on the first LCD line and the remaining time (MM:SS) on the second. 🧠

2. **Pomodoro Cycle**:

   - **Focus**: 25 minutes (`FOCUS_SESSION_MINUTES`), C5 tone (659 Hz).
   - **Break**: 5 minutes (`BREAK_SESSION_MINUTES`), E5 tone (523 Hz).
   - **Long Break**: 15 minutes (`LONG_BREAK_SESSION_MINUTES`), G5 tone (784 Hz), after 4 Pomodoros (`LONG_BREAK_INTERVAL`).
   - Mode changes trigger an 800 ms tone (`BUZZER_TONE_DURATION_MS`). 🎶

3. **Pomodoro Counter**:

   - The top-right corner of the LCD shows completed Pomodoros (`pomodoroCount`, e.g., "2/4").

4. **Customization**:
   - Adjust timings in the code:
     ```cpp
     const int FOCUS_SESSION_MINUTES = 25;
     const int BREAK_SESSION_MINUTES = 5;
     const int LONG_BREAK_SESSION_MINUTES = 15;
     ```
   - Modify frequencies in `changeMode` (e.g., `buzzerFrecuency = 523` for Focus).

## 📝 Code Structure

- **Constants**:

  - `rs`, `en`, `d4`, `d5`, `d6`, `d7`: LCD pins.
  - `buzzerPin`: Pin 9 for the buzzer.
  - `FOCUS_SESSION_MINUTES`, `BREAK_SESSION_MINUTES`, `LONG_BREAK_SESSION_MINUTES`: Mode durations.
  - `LONG_BREAK_INTERVAL`: 4 Pomodoros for a Long Break.
  - `TIMER_INTERVAL_MS`: 1000 ms (timer interval).
  - `BUZZER_TONE_DURATION_MS`: 800 ms (tone duration).

- **Variables**:

  - `lcdModeTitle`: Mode title displayed on the LCD (e.g., "Focus").
  - `timerMinutes`, `timerSeconds`: Remaining time.
  - `isBuzzerActive`: Indicates if the buzzer is active.
  - `buzzerFrecuency`: Tone frequency (523 Hz, 659 Hz, 784 Hz).
  - `pomodoroCount`: Count of completed Focus sessions.
  - `previousTimerMillis`, `previousBuzzerMillis`: Previous times for `millis()`.
  - `currentMode`: Current mode (`FOCUS`, `BREAK`, `LONG_BREAK`).

- **Functions**:
  - `setup()`: Initializes the LCD and starts in Focus mode.
  - `loop()`: Manages the timer, buzzer, and counter.
  - `updateTimer()`: Updates `timerMinutes` and `timerSeconds` every `TIMER_INTERVAL_MS`.
  - `updateBuzzer()`: Controls the buzzer based on `isBuzzerActive` and `buzzerFrecuency`.
  - `showPomodorosCount()`: Displays `pomodoroCount` on the LCD.
  - `changeMode()`: Switches modes, updates `lcdModeTitle`, timings, and frequency.

## 🌟 Future Improvements

- **Buttons**: Add buttons to pause, reset, or switch modes manually. 🖱️
- **Sound Patterns**: Implement pulses or melodies for buzzer tones (e.g., short pulses for Break). 🎶
- **EEPROM**: Store `pomodoroCount` for persistence across resets. 💾
- **Serial Communication**: Send timer status to a computer or app via Serial. 📡
- **Additional Modes**: Add a pause mode or dynamic time configuration.

## 🤝 Contributing

1. Fork the repository.
2. Create a branch (`git checkout -b feature/new-feature`).
3. Commit changes (`git commit -m "Add new feature"`).
4. Submit a pull request with a clear description.

## 📜 License

MIT License. Use, modify, and share freely! 📄

## 🙌 Acknowledgments

- To you, for using this timer to enhance your productivity! 💪

---

**Boost Your Productivity with Pomodoro!** 🍅⏰
