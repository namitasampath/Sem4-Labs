/*2. Write a program to compute nth Fibonacci number recursively and analyze its time efficiency*/

#include <stdio.h>

int opCount = 0;

int fib(int n) {
    opCount++;

    if (n == 0||n==1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("The %dth Fibonacci number is: %d\n", n, fib(n));
    printf("Number of recursive calls made: %d\n", opCount);

    return 0;
}
