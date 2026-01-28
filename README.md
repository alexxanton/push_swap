*This project has been created as part of the 42 curriculum by aanton-a*

## Description
This project teaches how to develop and optimize a complex logic using a limited set of instructions.
A sorting algorithm has to be implemented and managed meticulously with the following instructions:
* **sa**: Swap 1st and 2nd element of stack A
* **sb**: Swap 1st and 2nd element of stack B
* **ss**: Both sa and sb at the same time
* **pa**: Push the 1st number of stack B at the top of stack A
* **pb**: Push the 1st number of stack A at the top of stack B
* **ra**: Put the 1st number of stack A at the end
* **rb**: Put the 1st number of stack B at the end
* **rr**: Both ra and rb at the same time
* **rra**: Put the last number of stack A at the start
* **rrb**: Put the last number of stack B at the start
* **rrr**: Both rra and rrb at the same time
A stack, in this context, is a sort of list containing numbers that can get its elements rotated, swaped or interchanged between the other stack.

## Instructions
Clone the repository and compile the project:
```
git clone <repository> push_swap
cd push_swap
make
```
To execute the program:
```
./push_swap <numbers>
```
And to check if the program sorts the numbers:
```
./push_swap <numbers> | ./checker_<OS> <numbers>
```
You will see OK if the program sorts the numbers and KO if it doesn't.

## Resources
* https://medium.com/%40jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
* https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
* https://medium.com/@ayogun/push-swap-c1f5d2d41e97
