// #include <stdio.h>
// int main()
// {
//     int n, i, j, temp;
//     int arr[64];
//     // Asking the user to input the number of elements
//     printf("Enter number of elements: \n");
//     scanf("%d", &n);
//     // Checking if the number of elements exceeds the size of the array
//     if (n > 64) {
//         printf("Number of elements exceeds the size of the array.\n");
//         return 0;
//     }
//     // Asking the user to input the elements
//     printf("Enter %d elements: \n", n);
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     // Printing the given array
//     printf("Given array: \n");
//     for (i = 0; i < n; i++)
//     {
//         printf("%d  ", arr[i]);
//     }
//     printf("\n");
//     // Sorting the array using insertion sort algorithm
//     for (i = 1; i < n; i++)
//     {
//         j = i;
//         // Shift elements of arr[0..i-1], that a4e greater than key, to one position ahead
//         // of their current position
//         while (j > 0 && arr[j - 1] > arr[j])
//         {
//             // Swapping the elements if they are in the wrong order
//             temp = arr[j];
//             arr[j] = arr[j - 1];
//             arr[j - 1] = temp;
//             j--;
//         }
//     }
//     // Printing the sorted array in ascending order
//     printf("Sorted list in ascending order:\n");
//     for (i = 0; i < n; i++)
//     {
//         printf("%d  ", arr[i]);
//     }
//     return 0;
// }




#include <stdio.h>

void insertionSort(float arr[], int n) {
    int i, j;
    float key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(float arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float arr[n];
    printf("Enter %d float elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    insertionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
