#ifndef _SERIALCOMMAND_H
#define _SERIALCOMMAND_H

#include <Arduino.h>

class SerialCommand {
private:
    Stream* serialPort;
    String buffer;
    void (*commandCallback)(char command, int value);

    void processCommand(const String& command);
    bool isControlCharacter(char c);

public:
    SerialCommand();

    void begin(Stream& port);
    void listen();
    void onCommand(void (*callback)(char command, int value));
};

#endif