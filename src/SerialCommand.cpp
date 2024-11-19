#include "SerialCommand.h"

SerialCommand::SerialCommand() : serialPort(nullptr), buffer(""), commandCallback(nullptr) {}

void SerialCommand::begin(Stream& port) {
    this->serialPort = &port;
}

void SerialCommand::listen() {
    if (!serialPort) return;

    while (serialPort->available()) {
        char c = serialPort->read();
        //Serial.print("Received: ");
        //Serial.println(c); // Debug raw input

        if (c == ';') {
            processCommand(buffer);
            buffer = ""; // Clear buffer after processing
        } else if (!isControlCharacter(c)) {
            buffer += c; // Ignore control characters
        }
    }
}

void SerialCommand::onCommand(void (*callback)(char command, int value)) {
    commandCallback = callback;
}

void SerialCommand::processCommand(const String& command) {
    // Remove whitespace and non-printable characters
    String trimmedCommand = command;
    trimmedCommand.trim();

    // Ignore empty commands
    if (trimmedCommand.length() == 0 || !commandCallback) return;

    // Parse the command
    int colonIndex = trimmedCommand.indexOf(':');
    char cmd = trimmedCommand[0];
    int value = (colonIndex == -1) ? -1 : trimmedCommand.substring(colonIndex + 1).toInt();

    // Call the registered callback
    commandCallback(cmd, value);
}

bool SerialCommand::isControlCharacter(char c) {
    return c == '\n' || c == '\r';
}