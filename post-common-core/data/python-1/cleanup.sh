find . -name "__pycache__" -type d -exec rm -r {} +
rm -rf .env
find . -name "*_filter.png" -type f -exec rm -f {} +


