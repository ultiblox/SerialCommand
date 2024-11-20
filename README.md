# SerialCommands Library

[UltiBlox on GitHub](https://github.com/UltiBlox/SerialCommands) | [UltiBlox Home](https://ultiblox.org)

## Overview

`SerialCommands` is an open-source Arduino library for parsing and handling serial commands. It simplifies serial communication by supporting commands with or without values, enabling user-defined callbacks for easy integration into your project.

Core features:
- Detects and parses serial commands ending with `;`.
- Handles commands with or without values (e.g., `T;` or `S:40;`).
- Supports user-defined callbacks for flexible command handling.

---

## Quick Start

### Installation
Run the installation script to set up the library:
```bash
bash install.sh
```

For development use:
```bash
bash install-symlink.sh
```

### Example Sketch
The `SerialCommands` library comes with example sketches to help you get started.

#### Basic Usage
The `BasicUsage` example demonstrates how to use the library to control an LED via serial commands:

1. Open `examples/BasicUsage/BasicUsage.ino` in the Arduino IDE.
2. Upload it to your Arduino.
3. Use the Serial Monitor or the included `set_led.py` Python script to send commands.

Example command:
- `L:1;` turns the LED on.
- `L:0;` turns the LED off.

---

## API Reference

### Core Methods
- `void begin(Stream& port)`: Initialize the library with a serial port.
- `void listen()`: Continuously process incoming serial data.
- `void onCommand(void (*callback)(char command, int value))`: Register a callback to handle commands.

### How It Works
1. The `listen()` method reads incoming serial data and parses commands ending with `;`.
2. The parsed command and its optional value are passed to the user-defined callback.

---

## Python Integration

Use the `set_led.py` script to control your Arduino via serial commands:
```bash
python set_led.py --value 1
```

For auto-detection of the Arduino port:
```bash
python set_led.py 0
```

---

## License

[This project is licensed under the UltiBlox License.](https://ultiblox.org/license)
