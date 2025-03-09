#!/bin/bash

# Change to the directory where the script is located
cd "$(dirname "$0")"

# Compile the C program
gcc "Assignment_2.c" -o "check_2"

# Run the C program with automatic input
./check_2 <<EOF
6
-2
11
-4
13
-5
-2
1
3
EOF