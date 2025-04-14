#include <stdio.h>

typedef struct {
    int value;
    int weight;
} Item;

// Function to calculate the bound (maximum value we can achieve)
float calculateBound(int currentValue, int currentWeight, int remainingWeight, int index, int n, Item items[]) {
    float bound = currentValue;
    int weight = currentWeight;
int i;
    for ( i = index; i < n; i++) {
        if (weight + items[i].weight <= remainingWeight) {
            weight += items[i].weight;
            bound += items[i].value;
        } else {
            // Add fraction of the next item's value to fit remaining capacity
            bound += (float)(remainingWeight - weight) * items[i].value / items[i].weight;
            break;
        }
    }
    return bound;
}

// Function to solve the knapsack problem
void branchAndBoundKnapsack(int W, Item items[], int n) {
    int maxValue = 0;
int i;
    // Branch and Bound exploration
    for ( i = 0; i < n; i++) {
        int currentValue = items[i].value;
        int currentWeight = items[i].weight;

        if (currentWeight <= W && currentValue > maxValue) {
            maxValue = currentValue;
        }

        float bound = calculateBound(currentValue, currentWeight, W, i + 1, n, items);
        if (bound > maxValue) {
            continue; // Continue exploring feasible items
        }
    }

    printf("Maximum value in the knapsack is: %d\n", maxValue);
}

int main() {
    int n = 4; // Number of items
    int W = 16; // Capacity of knapsack
    Item items[] = {{40, 2}, {30, 5}, {50, 10}, {10, 5}}; // Value, Weight

    branchAndBoundKnapsack(W, items, n);

    return 0;
}
