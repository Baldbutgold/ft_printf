#include "ft_printf.h"

#include <stdio.h>
#include <stdarg.h> // Required for variadic functions

// Function to calculate the sum of a variable number of integers
    int sum(int count, ...) {
    va_list args; // Declare a variable to access the arguments
    va_start(args, count); // Initialize the argument list
    
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int); // Retrieve each argument
    }
    
    va_end(args); // Clean up the argument list
    return total;
}

    int main() {
    // Calling the variadic function
    /*printf("%d\n", sum(2, 3, 5, 7, 12 ,22));*/
    /*printf("Sum of 10, 20, 30, and 40: %d\n", sum(4, 10, 20, 30, 40));*/
    printf("%x\n", -1);
    printf("this is upper\n");
    ft_puthex(-1, 1);
    printf("\nthis is lower\n");
    ft_puthex(-1, 0);
}

//printf("test %d", 32);
