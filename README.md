# Push_Swap

The goal is to sort stack of integers. You have at disposal two stacks of integer. Integers given as arguments will be in
first stack, second one is for sorting.

Checker is a program which takes integers arguments and read instructions om the standart input.

Commands:
    sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).
    sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).
    ss : sa and sb at the same time.
    pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
    pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
    ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
    rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.
    rr : ra and rb at the same time.
    rra : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.
    rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.
    rrr : rra and rrb at the same time
    
Push Swap is a program which calculates and displays on the standart output the smallest amount of commands to sort integers.

Usage:
    type "make" in terminal to compile programs

    ./checker [-v] [integers ...]
    ./push_swap [-v] [integers ...]
    
    -v  For visualization
    
 If arguments are not integers or bigger or smaller that integer, program will display "Error" on standart output.
