#ifndef _SERIALCOMMAND_H
#define _SERIALCOMMAND_H

#include <Arduino.h>

class SerialCommand {
private:
    Stream* serialPort;
    String buffer;
    void (*commandCallback)(char command, int value);

public:
    SerialCommand() : serialPort(nullptr), buffer(""), commandCallback(nullptr) {}

    void begin(Stream& port) {
        this->serialPort = &port;
    }

    void listen() {
        if (!serialPort) return;

        while (serialPort->available()) {
            char c = serialPort->read();
            if (c == ';') {
                processCommand(buffer);
                buffer = "";
            } else {
                buffer += c;
            }
        }
    }

    void onCommand(void (*callback)(char command, int value)) {
        commandCallback = callback;
    }

private:
    void processCommand(const String& command) {
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

};

#endif