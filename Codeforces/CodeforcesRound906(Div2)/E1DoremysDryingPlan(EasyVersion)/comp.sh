#!/bin/bash

file1="out1"
file2="gout1"

# Function to modify files
modify_files() {
    python3 gen.py > rin1
    ./main < rin1 > out1
    ./good < rin1 > gout1
}

# Initial diff
while diff "$file1" "$file2" >/dev/null; do
    # Modify the files while the diff is empty
    modify_files
done

diff "$file1" "$file2"

