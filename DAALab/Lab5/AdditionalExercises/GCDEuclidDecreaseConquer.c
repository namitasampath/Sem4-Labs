/*3) Write a program in C to find gcd of two numbers using Euclid’s algorithm
employing the Decrease and Conquer strategy.
*/

#include <stdio.h>

// Function to compute GCD using Euclid's Algorithm (Recursive Approach)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);  // Reduce problem size (Decrease and Conquer)
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int result = gcd(num1, num2);
    printf("GCD of %d and %d is: %d\n", num1, num2, result);

    return 0;
}
