#!/bin/bash

# Path to the root of the AppEssentials project
root_dir="/path/to/AppEssentials"

# Path to the disclaimer file in the config directory
disclaimer_file="$root_dir/config/filedisclaimer.txt"

# Function to check if the disclaimer already exists in the file
disclaimer_exists() {
    file=$1

    # Use grep to search for a unique part of the disclaimer in the file
    # Adjust the search string according to your disclaimer's unique content
    grep -q "This file is part of the AppEssential project." "$file"
}

# Function to prepend the disclaimer to a file
prepend_disclaimer() {
    file=$1
    temp_file=$(mktemp)

    # Combine disclaimer, two blank lines, and the original file
    cat "$disclaimer_file" > "$temp_file"
    echo -e "\n\n" >> "$temp_file"
    cat "$file" >> "$temp_file"

    # Move the temporary file to original file
    mv "$temp_file" "$file"
}

# Loop over .hpp files in the include directory and .cpp files in the src directory
for file in "$root_dir/include/"*.hpp "$root_dir/src/"*.cpp; do
    if ! disclaimer_exists "$file"; then
        echo "Prepending disclaimer to $file"
        prepend_disclaimer "$file"
    else
        echo "Disclaimer already exists in $file"
    fi
done

echo "Disclaimer processed for all files."
