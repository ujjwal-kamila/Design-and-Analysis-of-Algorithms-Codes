// Knapsack Problem Using Greedy Algorithm

#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int profit;
    int weight;
    double ratio;
};

int compare(const void *a, const void *b)
{
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    return (item2->ratio - item1->ratio) > 0 ? 1 : -1;
}

double maxProfit(int capacity, struct Item items[], int n)
{

    qsort(items, n, sizeof(items[0]), compare);

    double totalProfit = 0.0;

    for (int i = 0; i < n; i++)
    {

        if (capacity - items[i].weight >= 0)
        {
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        }
        else
        {
            double fraction = (double)capacity / items[i].weight;
            totalProfit += fraction * items[i].profit;
            break;
        }
    }

    return totalProfit;
}

int main()
{
    int numItems, capacity;
    printf("Enter the number of items : ");
    scanf("%d", &numItems);

    struct Item items[numItems];
    printf("Enter the profits and weights of each item:\n");
    for (int i = 0; i < numItems; i++)
    {
        scanf("%d %d", &items[i].profit, &items[i].weight);
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }

    printf("Enter the capacity of knapsack : ");
    scanf("%d", &capacity);

    double max = maxProfit(capacity, items, numItems);
    printf("Maximum profit: %.2f\n", max);

    return 0;
}

// sample Run

/*
Enter the number of items : 3
Enter the profits and weights of each item:
25 18
24 15
15 10
Enter the capacity of knapsack : 20
Maximum profit: 31.50
*/