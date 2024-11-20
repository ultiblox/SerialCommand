# SerialCommands Library

[UltiBlox on GitHub](https://github.com/UltiBlox/SerialCommands) | [UltiBlox Home](https://ultiblox.org)

## Overview

`SerialCommands` is an open-source Arduino library for parsing and handling serial commands. It simplifies serial communication by supporting commands with or without values, enabling user-defined callbacks for easy integration into your project.

Core features:
- Detects and parses serial commands ending with `;`.
- Handles commands with or without values (e.g., `T;` or `S:40;`).
- Supports user-defined callbacks for flexible command handling.

---

## Installation

### Option 1: Arduino Library Manager Installation (Recommended)

1. Open the **Arduino IDE**.
2. Go to **Tools > Manage Libraries**.
3. Search for **UltiBlox-SerialCommands** and click **Install**.
4. Access example sketches under **File > Examples > UltiBlox-SerialCommands**.

### Option 2: Manual Installation (for Development and Customization)

1. **Clone the Repository**:
   ```bash
   git clone git@github.com:UltiBlox/SerialCommands.git ~/workspace/SerialCommands
   cd ~/workspace/SerialCommands
   ```

2. **Prepare the Environment**:
   Run the `prepare.sh` script to set up dependencies:
   ```bash
   bash prepare.sh
   ```

3. **Install the Library**:
   - **Copy Installation**:
     ```bash
     bash install.sh
     ```
   - **Symlink Installation** (for active development):
     ```bash
     bash install-symlink.sh
     ```

4. **Build Examples**:
   Compile example sketches with:
   ```bash
   bash build.sh
   ```

---

## Examples

The library includes several examples to get you started:
- **BasicUsage**: Demonstrates controlling an LED via serial commands.

To run an example:
1. Open the example sketch in the Arduino IDE.
2. Upload it to your Arduino.
3. Use the Serial Monitor or the included `set_led.py` script to send commands.

Example command:
- `L:1;` turns the LED on.
- `L:0;` turns the LED off.

---

## Methods

### Initialize the Library
```cpp
void begin(Stream& port)
```
Sets the serial port to be used by the library.

### Listen for Commands
```cpp
void listen()
```
Processes incoming serial data and parses commands ending with `;`.

### Register Command Callback
```cpp
void onCommand(void (*callback)(char command, int value))
```
Registers a user-defined callback to handle commands. The callback receives:
- `command`: The command character.
- `value`: The parsed value, or `-1` if no value is provided.

---

## License

[This project is licensed under the UltiBlox License.](https://ultiblox.org/license)