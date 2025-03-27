#include <stdio.h>

// Recursive function to check if there exists a subset with given sum
int isSubsetSum(int arr[], int n, int sum) {
    // Base Cases
    if (sum == 0) 
        return 1;  // Found a subset with required sum
    if (n == 0 && sum != 0) 
        return 0;  // No elements left but sum is not zero

    // If last element is greater than sum, ignore it
    if (arr[n - 1] > sum) 
        return isSubsetSum(arr, n - 1, sum);

    // Check if sum can be obtained by including or excluding the last element
    return isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}

// Function to check if array can be partitioned into two subsets of equal sum
int canPartition(int arr[], int n) {
    int totalSum = 0;

    // Calculate total sum of the array
    for (int i = 0; i < n; i++) 
        totalSum += arr[i];

    // If total sum is odd, partitioning is not possible
    if (totalSum % 2 != 0) 
        return 0;

    // Check if subset with sum = totalSum / 2 exists
    return isSubsetSum(arr, n, totalSum / 2);
}

// Driver function
int main() {
    int arr[] = {1, 5, 11, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (canPartition(arr, n)) 
        printf("YES, the array can be partitioned into two subsets with equal sum.\n");
    else 
        printf("NO, partitioning is not possible.\n");

    return 0;
}
