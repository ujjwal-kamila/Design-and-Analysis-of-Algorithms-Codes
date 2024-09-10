// fractional Knapsack Problem Using Greedy Algorithm
#include <stdio.h>
#include <stdlib.h>

struct Item {
    int profit;   
    int weight;  
    double ratio; 
};

// Comparison function for sorting items based on their profit-to-weight ratio (descending order)
int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    return (item2->ratio - item1->ratio) > 0 ? 1 : -1;  // Sort based on ratio
}

// Function to calculate the maximum profit using the greedy algorithm
double maxProfit(int capacity, struct Item items[], int n) {
    // Sort items based on profit-to-weight ratio in descending order
    qsort(items, n, sizeof(items[0]), compare);

    double totalProfit = 0.0;

    // Loop through all items
    for (int i = 0; i < n; i++) {
        if (capacity - items[i].weight >= 0) {  // If item can fit completely
            totalProfit += items[i].profit;     // Add full profit
            capacity -= items[i].weight;        // Reduce the capacity
        } else {  // If item cannot fit completely
            double fraction = (double)capacity / items[i].weight;  // Calculate fraction of the item that can fit
            totalProfit += fraction * items[i].profit;  // Add fractional profit
            break;  // Knapsack is full, exit the loop
        }
    }
    return totalProfit;
}

int main() {
    int numItems, capacity;
    // Input the number of items
    printf("Enter the number of items : ");
    scanf("%d", &numItems);
    struct Item items[numItems];  // Array to store items
    // Input profits and weights of each item
    printf("Enter the profits and weights of each item:\n");
    for (int i = 0; i < numItems; i++) {
        scanf("%d %d", &items[i].profit, &items[i].weight);
        items[i].ratio = (double)items[i].profit / items[i].weight;  // Calculate profit-to-weight ratio
    }
    // Input the capacity of the knapsack
    printf("Enter the capacity of knapsack : ");
    scanf("%d", &capacity);
    // Calculate the maximum profit
    double max = maxProfit(capacity, items, numItems);
    // Print the maximum profit
    printf("Maximum profit: %.2f\n", max);
    return 0;
}

/*
Sample Input and Output:

Enter the number of items : 3
Enter the profits and weights of each item:
25 18
24 15
15 10
Enter the capacity of knapsack : 20
Maximum profit: 31.50
*/
