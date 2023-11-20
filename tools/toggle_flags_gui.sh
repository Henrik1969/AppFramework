#!/bin/bash

POSSIBLE_FLAGS_FILE="config/possible_flags.conf"
ACTIVE_FLAGS_FILE="config/active_flags.conf"
TEMP_FILE=$(mktemp)

# Function to create zenity list format
create_zenity_list() {
    while IFS= read -r flag; do
        # Check if the flag is active
        if grep -Fxq "$flag" "$ACTIVE_FLAGS_FILE" 2>/dev/null; then
            echo "$flag TRUE"
        else
            echo "$flag FALSE"
        fi
    done < "$POSSIBLE_FLAGS_FILE" > "$TEMP_FILE"
}

# Create the zenity list format
create_zenity_list

# Display zenity dialog and get selected options
SELECTED=$(zenity --list --title "Toggle Compiler Flags" --text "Select compiler flags:" \
--checklist --column "Pick" --column "Flag" --separator="\n" --hide-header < "$TEMP_FILE")

# Check the return status of zenity
ret=$?
rm "$TEMP_FILE" # Clean up the temp file
if [ $ret -ne 0 ]; then
    echo "No changes made."
    exit 1
fi

# Clear the active flags file before updating
> "$ACTIVE_FLAGS_FILE"

# Update the active flags file based on selections
echo "$SELECTED" | while read -r flag; do
    if [[ "$flag" ]]; then
        echo "$flag" >> "$ACTIVE_FLAGS_FILE"
    fi
done

echo "Compiler flags updated."
