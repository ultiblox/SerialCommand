#include <SerialCommand.h>

SerialCommand command;

void handleCommand(char cmd, int value) {
    Serial.print("Command: ");
    Serial.println(cmd);
    Serial.print("Value: ");
    Serial.println(value);

    switch (cmd) {
        case 'L': // LED control
            digitalWrite(13, value == 1 ? HIGH : LOW);
            Serial.println(value == 1 ? "LED ON" : "LED OFF");
            break;

        default:
            Serial.print("Unknown command: ");
            Serial.println(cmd);
            break;
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(13, OUTPUT);

    command.begin(Serial);
    command.onCommand(handleCommand);

    Serial.println("SerialCommand ready. Use L:1; to turn LED on, L:0; to turn it off.");
}

void loop() {
    command.listen();
}