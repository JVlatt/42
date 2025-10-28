#!/bin/bash

# Exit on error
set -e

# Create virtual environment in venv folder
python -m venv .env
./.env/bin/pip install --upgrade pip
./.env/bin/pip install -r requirements.txt

echo "✅ Virtual environment setup complete!"
echo "To activate it in the future, run: source .env/bin/activate"
