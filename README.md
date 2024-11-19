# SerialCommand Library

## Overview
The SerialCommand library provides a simple way to parse commands over serial communication in Arduino sketches. It supports:
- Commands without values (e.g., `T;`).
- Commands with values (e.g., `S:40;`).

## Features
- Handles multiple commands in a single line (e.g., `T;S:40;H;`).
- Easy-to-use API with `.listen()` and callback mechanisms.
- Optional integration with SerialLogger for debugging.

## Installation
1. Copy the `SerialCommand` folder into your Arduino libraries directory.
2. Restart the Arduino IDE.

## Usage
### Basic Example
```cpp
#include <SerialCommand.h>

SerialCommand command;

void setup() {
    command.begin(115200);
}

void loop() {
    command.listen();
}
```

### Adding Callbacks
```cpp
command.onCommand([](const char* cmd) {
    if (strcmp(cmd, "T") == 0) {
        // Handle T command
    }
});

command.onCommandWithValue([](const char* cmd, int value) {
    if (strcmp(cmd, "S") == 0) {
        // Handle S command with value
    }
});
```

## License
This library is licensed under the MIT License.