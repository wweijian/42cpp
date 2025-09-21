#!/bin/zsh

echo "test 1: "
./RPN "1 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 +"
echo "test 2: "
./RPN "1 2 3 4 5 + - * /"
echo "test 3: "
./RPN "1 2 * 3 * 4 * 5 *"
echo "test 4: "
./RPN "1 2 3 4 5 * * * *"
echo "test 5: "
./RPN "1 2 - 3 - 4 - 5 -"
echo "test 6: "
./RPN "1 2 3 4 5 / / / /" # truncation

#invalid
echo "invalid test 1: "
./RPN "1 2 3 4 5 * * *" # too many operands
echo "invalid test 2: "
./RPN "1 2 3 4 5 * * * * *" # too many operators
echo "invalid test 3: "
./RPN "12 2 3 4 5 * * * * *" # double digits
echo "invalid test 4: "
./RPN "1a 2 3 4 5 * * * *" # letters
echo "invalid test 5: "
./RPN "a2 2 3 4 5 * * * *" # letters
echo "invalid test 6: "
./RPN "a 2 3 4 5 * * * *" # letters
echo "invalid test 7: "
./RPN "(1 + 2)" # brackets
echo "invalid test 8: "
./RPN "* 1 2" # starting with operator / also insufficient operand when required