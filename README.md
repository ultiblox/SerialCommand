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

### BasicUsage
This example demonstrates controlling an LED via serial commands. It includes:
- A [CLI script (`set_led.py`)](examples/BasicUsage/set_led.py) for sending commands to the Arduino.
- A [Web App](examples/BasicUsage/web) for a user-friendly interface.

#### How to Run
1. Open the [BasicUsage.ino](examples/BasicUsage/BasicUsage.ino) sketch in the Arduino IDE.
2. Upload it to your Arduino.

#### Controlling the LED
Choose one of the following methods to interact with the Arduino:

1. **Serial Monitor**:
   - Open the Serial Monitor in the Arduino IDE.
   - Send the following commands:
     - `L:1;` - Turn the LED ON.
     - `L:0;` - Turn the LED OFF.

2. **CLI Script (`set_led.py`)**:
   - Navigate to the **BasicUsage** folder:
     ```bash
     cd examples/BasicUsage
     ```
   - Run the Python script to control the LED:
     ```bash
     python set_led.py 1  # Turn ON
     python set_led.py 0  # Turn OFF
     ```
   - If the port is not auto-detected, specify it manually:
     ```bash
     python set_led.py --port /dev/ttyUSB0 1
     ```

3. **Web App**:
   - Navigate to the [web](examples/BasicUsage/web) folder:
     ```bash
     cd examples/BasicUsage/web
     ```
   - Launch the Flask app:
     ```bash
     bash run.sh
     ```
   - Open your browser and go to:
     ```
     http://127.0.0.1:5000
     ```
   - Use the toggle icon in the web interface to control the LED.

---

## Using SerialCommands in Your Projects

To use the library in your own Arduino projects:
1. Include the library header in your sketch:
   ```cpp
   #include "SerialCommands.h"
   ```
2. Initialize the library in your setup function:
   ```cpp
   SerialCommands commands;
   void setup() {
       Serial.begin(115200);
       commands.begin(Serial);
   }
   ```
3. Register a callback to handle commands:
   ```cpp
   commands.onCommand([](char command, int value) {
       if (command == 'L') {
           digitalWrite(13, value ? HIGH : LOW);
       }
   });
   ```
4. Call the `listen()` method in your loop:
   ```cpp
   void loop() {
       commands.listen();
   }
   ```

For detailed examples, refer to the included sketches in the [examples folder](examples).

---

## Troubleshooting

### Common Issues

1. **Arduino Serial Monitor is Blocking the Port**
   - If the CLI script or web app cannot connect to the Arduino, ensure the Serial Monitor in the Arduino IDE is closed. Only one tool can access the serial port at a time.

2. **Missing Python**
   - To use the CLI script or web app, Python must be installed on your system.
   - Check if Python is installed:
     ```bash
     python --version
     ```
     or
     ```bash
     python3 --version
     ```
   - If Python is not installed:
     - Download and install Python from the [official website](https://www.python.org/).
     - Ensure you add Python to your system's PATH during installation.

3. **Missing Python Libraries**
   - If you encounter an error like `ModuleNotFoundError: No module named 'flask'`, install the required libraries:
     ```bash
     pip install flask pyserial
     ```

4. **Serial Port Not Detected**
   - If the CLI script cannot detect the Arduino:
     - Verify that your Arduino is connected and visible in your system's device manager (e.g., `/dev/ttyUSB0` or `COM3`).
     - Specify the port manually using the `--port` argument:
       ```bash
       python set_led.py --port /dev/ttyUSB0 1
       ```

5. **Web App Doesn't Start**
   - Ensure Flask is installed (`pip install flask`).
   - Launch the app using:
     ```bash
     bash run.sh
     ```
   - Open your browser at `http://127.0.0.1:5000`.

---