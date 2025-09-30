#!/bin/bash

# Exit on error
set -e

# Create virtual environment in venv folder
python -m venv .env
./.env/bin/pip install --upgrade pip
./.env/bin/pip install Pillow numpy flake8


echo "✅ Virtual environment setup complete!"
echo "To activate it in the future, run: source venv/bin/activate"
