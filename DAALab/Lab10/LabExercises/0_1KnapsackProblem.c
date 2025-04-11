#include <stdio.h>

// Function to find the maximum value in the knapsack
int knapsack(int W, int weights[], int values[], int n) {
    int dp[n + 1][W + 1]; // DP table
int i,w;
    // Build the table in a bottom-up manner
    for ( i = 0; i <= n; i++) {
        for ( w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0; // Base case
            } else if (weights[i - 1] <= w) {
                dp[i][w] = (values[i - 1] + dp[i - 1][w - weights[i - 1]]) > dp[i - 1][w]
                           ? (values[i - 1] + dp[i - 1][w - weights[i - 1]])
                           : dp[i - 1][w];
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W]; // Maximum value in the knapsack
}

int main() {
    int n = 4; // Number of items
    int values[] = {60, 100, 120, 80}; // Values of the items
    int weights[] = {10, 20, 30, 25}; // Weights of the items
    int W = 50; // Capacity of the knapsack

    printf("Maximum value in the knapsack: %d\n", knapsack(W, weights, values, n));
    return 0;
}
