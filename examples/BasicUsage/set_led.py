import sys
import serial
import time
import argparse
from serial.tools import list_ports

def detect_port():
    """Automatically detect an Arduino-connected port."""
    ports = list_ports.comports()
    for port in ports:
        if "Arduino" in port.description or "ttyUSB" in port.device or "ttyACM" in port.device:
            return port.device
    return None

def send_command(port, baud, command):
    """Send the specified command to the given serial port."""
    try:
        with serial.Serial(port, baud, timeout=1) as ser:
            time.sleep(2)  # Allow time for Arduino to reset
            ser.write(command.encode('utf-8'))
            ser.flush()
            print(f"Sent command: {command.strip()} to {port} at {baud} baud")
    except serial.SerialException as e:
        print(f"Error: Could not open serial port {port}: {e}")
        sys.exit(1)

def main():
    parser = argparse.ArgumentParser(description="Control an Arduino LED via serial commands.")
    parser.add_argument("value", type=int, choices=[0, 1], help="LED state: 1 for ON, 0 for OFF.")
    parser.add_argument("--port", type=str, help="Serial port to use (e.g., COM3 or /dev/ttyUSB0).")
    parser.add_argument("--baud", type=int, default=115200, help="Baud rate for the serial connection (default: 115200).")

    args = parser.parse_args()

    port = args.port
    if not port:
        port = detect_port()
        if not port:
            print("Error: Could not auto-detect an Arduino. Please specify a port using --port.")
            sys.exit(1)
        print(f"Auto-detected Arduino on port: {port}")

    command = f"L:{args.value};\n"
    send_command(port, args.baud, command)

if __name__ == "__main__":
    main()