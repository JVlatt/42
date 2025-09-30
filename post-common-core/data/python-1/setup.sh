#!/bin/bash

# Exit on error
set -e

# Create virtual environment in venv folder
python3 -m venv .env

# Activate virtual environment
source .env/bin/activate

# Upgrade pip
pip install --upgrade pip

# Install required packages
pip install Pillow numpy flake8

echo "✅ Virtual environment setup complete!"
echo "To activate it in the future, run: source venv/bin/activate"
