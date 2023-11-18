#!/bin/bash

# Check for correct argument count
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 old_project_name new_project_name"
    exit 1
fi

# Assign command line arguments to variables
old_name=$1
new_name=$2

# Path to the root of the project
root_dir="$(dirname "$(realpath "$0")")/.."

# Function to replace the project name in a file
replace_project_name() {
    local file=$1

    # Replace old project name with new project name using sed
    sed -i "s/$old_name/$new_name/g" "$file"
}

# Loop over all relevant files, excluding the build directory
while IFS= read -r -d '' file; do
    replace_project_name "$file"
done < <(find "$root_dir" -path "$root_dir/build" -prune -o \( -name '*.cpp' -o -name '*.hpp' -o -name 'CMakeLists.txt' -o -name 'control' -o -name '*.txt' \) -print0)

echo "Project name changed from $old_name to $new_name in all files."
