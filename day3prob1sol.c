#include <stdio.h>

// Function to calculate factorial recursively
long long factorial(int n) {
    // Base case: factorial of 0 is 1
    if (n == 0) {
        return 1;
    } else {
        // Recursive step: n! = n * (n-1)!
        return n * factorial(n - 1);
    }
}

int main() {
    int num;

    // Prompt the user to enter a number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Handle negative input (factorial is not defined for negative numbers)
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        // Calculate and print the factorial
        long long fact = factorial(num);
        printf("Factorial of %d is %lld\n", num, fact);
    }

    return 0;
}
