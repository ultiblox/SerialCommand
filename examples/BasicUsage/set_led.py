import sys
import serial
import time

def send_command(port, command):
    try:
        with serial.Serial(port, 115200, timeout=1) as ser:
            time.sleep(2)  # Allow time for Arduino to reset
            ser.write(command.encode('utf-8'))
            ser.flush()  # Ensure the command is sent
            print(f"Sent command: {command.strip()}")
    except serial.SerialException as e:
        print(f"Error: Could not open serial port {port}: {e}")
        sys.exit(1)

def main():
    if len(sys.argv) != 3:
        print("Usage: python set_led.py <port> <1|0>")
        print("Example: python set_led.py COM3 1")
        sys.exit(1)

    port = sys.argv[1]
    value = sys.argv[2]

    if value not in ["0", "1"]:
        print("Error: Value must be 0 or 1.")
        sys.exit(1)

    command = f"L:{value};\n"
    send_command(port, command)

if __name__ == "__main__":
    main()