#!/opt/homebrew/bin/bash

# List of input files
input_files=("data/random_numbers_100.txt" "data/random_numbers_1000.txt" "data/random_numbers_10000.txt" "data/random_numbers_100000.txt" data/random_numbers_500000.txt)

# List of tree types
tree_types=("AVL" "BST")

# Loop through each input file and tree type, and run the C++ executable
for file in "${input_files[@]}"; do
    for tree_type in "${tree_types[@]}"; do
        echo "Running with input file: $file, tree type: $tree_type"
        ./target/debug/final --tree "$tree_type" < "$file"
        echo "-------------------------------------"
    done
done