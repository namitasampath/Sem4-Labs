/*Write a program in C to find a^n where n > 0 using divide and conquer strategy.*/


#include <stdio.h>

// Function to compute a^n using Divide and Conquer
double power(int a, int n) {
    if (n == 0) 
        return 1;  // Base case: a^0 = 1
    
    double halfPower = power(a, n / 2);  // Divide step

    if (n % 2 == 0) 
        return halfPower * halfPower;  // Even exponent case
    else 
        return a * halfPower * halfPower;  // Odd exponent case
}

int main() {
    int a, n;

    printf("Enter base (a): ");
    scanf("%d", &a);
    printf("Enter exponent (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Exponent should be greater than 0.\n");
        return 1;
    }

    double result = power(a, n);
    printf("%d^%d = %.0lf\n", a, n, result);

    return 0;
}
