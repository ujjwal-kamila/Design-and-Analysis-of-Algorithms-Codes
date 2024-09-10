//0/1 knapsack using DP

#include <stdio.h>
// Function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    // Create a 2D array to store the maximum value that can be obtained
    // with the first i items and a maximum weight of w
    int K[n + 1][W + 1];
    // Build table K[][] in a bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                // Base case: if there are no items or the weight is 0
                K[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                // If the weight of the current item is less than or equal to the current weight capacity
                // Consider the maximum of including or excluding the current item
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            } else {
                // If the weight of the current item is more than the current weight capacity
                // Exclude the current item
                K[i][w] = K[i - 1][w];
            }
        }
    }
    // Return the maximum value that can be obtained with n items and weight capacity W
    return K[n][W];
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    // Arrays to store the values and weights of items
    int val[n], wt[n];
    printf("Enter the profits and weights of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &val[i], &wt[i]);  // Read value and weight of each item
    }
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &W);
    int maxValue = knapSack(W, wt, val, n);
    printf("Maximum value in Knapsack = %d\n", maxValue);
    return 0;
}
