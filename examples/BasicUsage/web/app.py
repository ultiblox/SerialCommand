from flask import Flask, render_template, request, jsonify
import serial
import time

app = Flask(__name__)

# Serial port configuration
SERIAL_PORT = "/dev/ttyUSB0"  # Update with your Arduino's port
BAUD_RATE = 115200

def send_command(value):
    """Send a command to the Arduino."""
    try:
        with serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1) as ser:
            time.sleep(2)  # Allow time for Arduino to reset
            command = f"L:{value};\n"
            ser.write(command.encode('utf-8'))
            ser.flush()
            return f"Command sent: {command.strip()}"
    except serial.SerialException as e:
        return f"Error: {e}"

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/toggle", methods=["POST"])
def toggle_led():
    action = request.json.get("action")
    if action == "on":
        result = send_command(1)
    elif action == "off":
        result = send_command(0)
    else:
        result = "Invalid action"
    return jsonify({"message": result})

if __name__ == "__main__":
    app.run(debug=True)