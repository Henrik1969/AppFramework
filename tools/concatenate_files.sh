#!/bin/bash

# Define the project directory and output file
PROJECT_DIR="/home/henrik/Projekter/AppFramework"
OUTPUT_FILE="largefile.txt"

# Clear the output file or create it if it doesn't exist
> "$OUTPUT_FILE"

# Function to append a file to the output with a header
append_file() {
    local file=$1
    echo "---- START OF FILE: $file ----" >> "$OUTPUT_FILE"
    cat "$file" >> "$OUTPUT_FILE" 2>> error.log
    if [ $? -ne 0 ]; then
        echo "Error occurred while processing $file. See error.log for details."
    fi
    echo "---- END OF FILE: $file ----" >> "$OUTPUT_FILE"
    echo "" >> "$OUTPUT_FILE"
}

# Export the function for use in find -exec
export -f append_file
export OUTPUT_FILE

# Find and process files
find "$PROJECT_DIR" -type f \( -name "*.cpp" -o -name "*.hpp" -o -name "CMakeLists.txt" -o -name "Makefile" \) -exec bash -c 'append_file "$0"' {} \;

echo "Processing complete. Output in $OUTPUT_FILE"
