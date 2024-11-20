#!/bin/bash

# Set the system-wide installation directory
BINDIR="/usr/local/bin"
CLI_VERSION="latest"  # Change to a specific version if needed

# Function to check and install Arduino CLI
install_arduino_cli() {
    if command -v arduino-cli &> /dev/null; then
        echo "Arduino CLI is already installed."
    else
        echo "Installing Arduino CLI system-wide to $BINDIR..."

        # Download and install Arduino CLI with sudo permissions
        curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sudo BINDIR=$BINDIR sh -s $CLI_VERSION

        # Check if the installation was successful
        if [ $? -ne 0 ]; then
            echo "Error: Arduino CLI installation failed."
            exit 1
        else
            echo "Arduino CLI installed successfully in $BINDIR."
        fi
    fi

    # Verify the installation
    arduino-cli version
}

# Function to check and install Python
install_python() {
    if command -v python3 &> /dev/null; then
        echo "Python 3 is already installed."
    else
        echo "Error: Python 3 is not installed. Please install Python 3 and rerun this script."
        exit 1
    fi
}

# Function to check and install Python libraries
install_python_libraries() {
    REQUIRED_MODULES=("flask" "pyserial")
    for module in "${REQUIRED_MODULES[@]}"; do
        if ! python3 -c "import $module" &> /dev/null; then
            echo "Installing Python module: $module..."
            pip3 install $module
            if [ $? -ne 0 ]; then
                echo "Error: Failed to install $module. Check your pip configuration."
                exit 1
            fi
        else
            echo "Python module $module is already installed."
        fi
    done
}

# Main setup steps
echo "Setting up the development environment..."

# Install Arduino CLI
install_arduino_cli

# Check for Python and install required libraries
install_python
install_python_libraries

echo "Development environment setup complete!"