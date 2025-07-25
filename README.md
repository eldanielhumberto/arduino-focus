# 🍎 Pomodoro Timer for Arduino with LCD
This Arduino project implements a simple Pomodoro timer with three modes: Focus, Break and Long break. It uses a 16x2 LCD display to show the current mode and the remaining time for each session. The timer alternates between a 25-minute focus session, a 5-minute break session and a 15-minute long break session.

## Features
- Displays the current mode ("Focus mode", "Break mode", "Long break mode") on the LCD's first row.
- Shows a countdown timer in the format MM:SS on the LCD's second row.
- Automatically switches between Focus (25 minutes), Break (5 minutes) and Long break (15 minutes) modes when the timer reaches zero.
- Uses an enum to manage modes, ensuring efficient memory usage and clear code.

## Hardware Requirements
- Arduino board (e.g., Arduino Uno)
- 16x2 LCD display compatible with the LiquidCrystal library
- Wiring:
    - LCD RS pin to Arduino digital pin 12
    - LCD Enable pin to Arduino digital pin 11
    - LCD D4 pin to Arduino digital pin 5
    - LCD D5 pin to Arduino digital pin 4
    - LCD D6 pin to Arduino digital pin 3
    - LCD D7 pin to Arduino digital pin 2
- Appropriate resistors and power connections for the LCD

## Software Requirements

- Arduino IDE
- LiquidCrystal library (included with the Arduino IDE)

## Installation

1. Connect the LCD to the Arduino as described in the hardware requirements.
2. Open the Arduino IDE and install the LiquidCrystal library if not already present.
3. Copy the provided code into a new Arduino sketch.
4. Upload the sketch to your Arduino board.

## Code Overview

- **LCD Setup**: Initializes a 16x2 LCD using the LiquidCrystal library with the specified pin configuration.

- **Modes**: Uses an `enum Mode { FOCUS, BREAK, LONG_BREAK }` to manage the application state.

- **Timer Configuration**:
    - **Focus session**: 25 minutes (configurable via `FOCUS_SESSION_MINUTES` and `FOCUS_SESSION_SECONDS`).

    - **Break session**: 5 minutes (configurable via `BREAK_SESSION_MINUTES` and `BREAK_SESSION_SECONDS`).

    - **Long break session**: 15 minutes (configurable via `LONG_BREAK_SESSION_MINUTES` and `LONG_BREAK_SESSION_SECONDS`)

    - **Pomodoro interval for taking a break**: 4 pomodoros (configurable via `LONG_BREAK_INTERVAL`)

- **Functions**:
    - `setup()`: Initializes the LCD and sets the initial mode to FOCUS.
    
    - `loop()`: Runs the timer and switches modes when the timer reaches zero.

    - `timer()`: Updates the countdown timer every second and displays the time on the LCD.

    - `changeMode(Mode mode)`: Updates the mode, resets the timer, and displays the mode title on the LCD.

    - `showPomodorosCount()`: Shows the number of pomodoros you have completed and those remaining before a long break.

## Usage

1. Power on the Arduino with the LCD connected.
2. The LCD will display "Focus mode" and start a 25-minute countdown.
3. When the focus session ends, it automatically switches to "Break mode" for 5 minutes.
4. The cycle repeats indefinitely, alternating between Focus and Break modes.

## Customization

- Adjust `FOCUS_SESSION_MINUTES`, `BREAK_SESSION_MINUTES` and `LONG_BREAK_SESSION_MINUTES` to change the duration of each session.

- Adjust `LONG_BREAK_INTERVAL` to change the number of pomodoros that must be completed in order to take a long break.

- Modify `titleText` in the `changeMode` function to customize the displayed mode names.

- Add buttons or other inputs to manually switch modes by calling `changeMode(FOCUS)` or `changeMode(BREAK)`.

## Notes

- Ensure the LCD contrast is properly adjusted for visibility (may require a potentiometer).

- The code is designed to be memory-efficient, using an `enum` instead of strings for mode management.

## License
This project is open-source and available under the MIT License.