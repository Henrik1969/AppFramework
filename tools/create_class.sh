#!/bin/bash

# Function to prompt for overwrite permission
prompt_overwrite() {
    while true; do
        read -p "File $1 exists. Overwrite existing files (y/N)? " yn
        case $yn in
            [Yy]* ) return 0;;  # Yes, proceed with overwrite
            [Nn]* | "" ) return 1;;  # No or empty response, do not overwrite
            * ) echo "Please answer yes or no.";;
        esac
    done
}

# Check if a classname was provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 classname"
    exit 1
fi

# Assign the classname to a variable
classname=$1

# Create capitalized version of the classname
capitalized_classname=$(echo "$classname" | tr '[:lower:]' '[:upper:]')

# Paths to skeleton files and target files
skel_hpp="config/skel.hpp"
skel_cpp="config/skel.cpp"
new_hpp="include/${classname}.hpp"
new_cpp="src/${classname}.cpp"
doc_tex="docs/${classname}.tex"
main_doc="docs/documentation.tex"
cmake_lists="CMakeLists.txt"

# Check if .hpp, .cpp, or .tex files already exist and prompt for overwrite
overwrite_needed=false
for file in "$new_hpp" "$new_cpp" "$doc_tex"; do
    if [ -f "$file" ]; then
        if ! prompt_overwrite "$file"; then
            echo "Operation cancelled."
            exit 1
        fi
        overwrite_needed=true
        break
    fi
done

# Proceed with file creation only if overwrite is confirmed or files don't exist
if [ "$overwrite_needed" = false ]; then
    # Create .hpp and .cpp from skeleton files
    sed "s/<classname>/${classname}/g; s/<CAPITALIZED CLASSNAME>/${capitalized_classname}/g" "$skel_hpp" > "$new_hpp"
    echo "${classname}.hpp file created from skeleton."
    sed "s/<classname>/${classname}/g" "$skel_cpp" > "$new_cpp"
    echo "${classname}.cpp file created from skeleton."

    # Check if docs directory exists
    if [ ! -d "docs" ]; then
        echo "Creating docs directory."
        mkdir -p docs
    fi

    # Create .tex file for class documentation
    if ! cat <<EOF > "$doc_tex"
\section{${classname}}
\label{sec:l${classname}}

% Detailed documentation for the ${classname} class here.

% Include the source code
\subsection{Source Code}
\subsubsection{${classname}.hpp}
\lstinputlisting[language=C++]{../include/${classname}.hpp}\pagebreak
\subsubsection{${classname}.cpp}
\lstinputlisting[language=C++]{../src/${classname}.cpp}\pagebreak
EOF
    then
        echo "Failed to create ${classname}.tex file."
        exit 1
    fi
    echo "${classname}.tex documentation file created in docs directory."

    # Update main documentation file
	sed -i "/%insertclasshere/{s//\\\\\\input{${classname}.tex}\n%insertclasshere/;:a;n;ba}" "$main_doc"
	echo "Updated main documentation to include ${classname}.tex"

    # Update CMakeLists.txt only if the classname is not already present
    if ! grep -q "$classname.cpp" "$cmake_lists"; then
        sed -i "/#INSERTCLASSPOINT/i \ \ \ \ src/${classname}.cpp" "$cmake_lists"
        echo "Updated CMakeLists.txt to include ${classname}.cpp"
    else
        echo "$classname.cpp already exists in CMakeLists.txt"
    fi
fi
