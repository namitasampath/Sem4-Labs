/*3) Write a program to delete strong numbers from an array using recursion [A strong
number is such that the sum of it's factorial is the number itself]*/

#include <stdio.h>

// Function to compute factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

// Function to check if a number is strong
int isStrong(int num) {
    int sum = 0, temp = num;
    while (temp > 0) {
        sum += factorial(temp % 10);  // Sum of factorial of digits
        temp /= 10;
    }
    return (sum == num);
}

// Recursive function to delete strong numbers from the array
int removeStrongNumbers(int arr[], int size, int index) {
    if (index == size)
        return size;

    if (isStrong(arr[index])) {
        // Shift elements to remove the strong number
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        return removeStrongNumbers(arr, size - 1, index);  // Recur without incrementing index
    }
    return removeStrongNumbers(arr, size, index + 1);
}

// Function to display the array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {145, 2, 10, 40585, 120, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    displayArray(arr, size);

    size = removeStrongNumbers(arr, size, 0);  // Remove strong numbers

    printf("Array after removing strong numbers: ");
    displayArray(arr, size);

    return 0;
}
