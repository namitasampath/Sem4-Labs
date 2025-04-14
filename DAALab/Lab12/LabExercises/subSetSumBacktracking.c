#include <stdio.h>

#define MAX 100

// Function to print a solution (subset that sums to the target)
void printSubset(int subset[], int size) {
    printf("{ ");
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

// Backtracking function to find subsets
void subsetSum(int set[], int subset[], int n, int index, int sum, int target) {
    if (sum == target) {
        // Print the subset when the sum equals the target
        printSubset(subset, index);
        return;
    }

    if (sum > target || n == 0) {
        // If the sum exceeds the target or no elements are left, backtrack
        return;
    }

    // Include the current element in the subset
    subset[index] = set[0];
    subsetSum(set + 1, subset, n - 1, index + 1, sum + set[0], target);

    // Exclude the current element and move to the next
    subsetSum(set + 1, subset, n - 1, index, sum, target);
}

int main() {
    int set[] = {1, 2, 5, 6, 8}; // The given set
    int n = 5;                   // Number of elements in the set
    int target = 9;              // The desired sum
    int subset[MAX];             // To store the current subset

    printf("Subsets of S that sum to %d:\n", target);
    subsetSum(set, subset, n, 0, 0, target);

    return 0;
}
