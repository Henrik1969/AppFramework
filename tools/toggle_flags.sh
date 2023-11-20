#!/bin/bash

CONFIG_FILE="config/compiler_flags.conf"

# Function to toggle a flag
toggle_flag() {
    local flag=$1
    if grep -q "^#*${flag}" "$CONFIG_FILE"; then
        # Toggle the flag
        sed -i "/^#*${flag}/s/^#*/#/" "$CONFIG_FILE"
        sed -i "/^#${flag}/s/^#//" "$CONFIG_FILE"
        echo "Toggled $flag"
    else
        echo "$flag not found in $CONFIG_FILE"
    fi
}

# Check if a flag was provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 flag_name"
    exit 1
fi

toggle_flag "$1"
