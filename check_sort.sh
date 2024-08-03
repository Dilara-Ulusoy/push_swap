#!/bin/bash

# Names of the temporary files needed
OUTPUT_FILE="output.txt"
RESULT_FILE="result.txt"

# Count the number of initial arguments
initial_size=$#

# Run the push_swap program and check if the list is sorted
ARG="$@"
./push_swap $ARG > $OUTPUT_FILE
./checker_Mac $ARG < $OUTPUT_FILE > $RESULT_FILE

# Read the output of the checker program
RESULT=$(cat $RESULT_FILE)

# Arrays for stack A and stack B
stack_a=()
stack_b=()

# Initially, add all arguments to stack A
for num in "$@"; do
    stack_a+=("$num")
done

# Total operations counter
total_operations=0

# Read the output of push_swap to determine the final state of stacks A and B
while IFS= read -r line; do
    case $line in
        pb|pa|sa|sb|ra|rb|rra|rrb|ss|rr|rrr)
            total_operations=$((total_operations + 1))
            ;;
        *)
            echo "Unknown operation: $line"
            ;;
    esac
done < $OUTPUT_FILE

# Print the total number of operations
echo "---------------"
echo "Initial size of arguments: $initial_size"
echo "Total number of operations: $total_operations"

# Check if stack B is empty
echo "---------------"
if [ ${#stack_b[@]} -eq 0 ]; then
    echo "B stack is empty"
else
    echo "B stack is not empty"
fi

# Check if the list is sorted
if [ "$RESULT" == "OK" ]; then
    echo "List is sorted: ---------------OK"
else
    echo "KO: List is not sorted--------------KO"
fi

# Clean up temporary files
rm -f $OUTPUT_FILE $RESULT_FILE
