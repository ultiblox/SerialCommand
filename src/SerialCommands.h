#ifndef _SerialCommands_H
#define _SerialCommands_H

#include <Arduino.h>

class SerialCommands {
private:
    Stream* serialPort;
    String buffer;
    void (*commandCallback)(char command, int value);

    void processCommand(const String& command);
    bool isControlCharacter(char c);

public:
    SerialCommands();

    void begin(Stream& port);
    void listen();
    void onCommand(void (*callback)(char command, int value));
};

#endif