#!/bin/bash

# Check if two arguments are passed
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <directory_number> <file_number>"
    exit 1
fi

# Assign arguments to variables for better readability
dir_num="$1"
file_num="$2"

# Define the source file and executable names based on the input arguments
src_file="Zadania_${dir_num}/Zad_${file_num}.c"
exe_file="Zad_${file_num}"

rm -rf output/*

# Check if the source file exists
if [ ! -f "$src_file" ]; then
    echo "Error: Source file $src_file does not exist."
    exit 2
fi

# Compile the C file
gcc "$src_file" -o output/"$exe_file" -Wall -Werror

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."
    # Execute the compiled program
    ./output/"$exe_file"
else
    echo "Compilation failed."
    exit 3
fi