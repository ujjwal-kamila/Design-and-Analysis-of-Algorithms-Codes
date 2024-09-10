//Quick sort alogorithm in c

float value
#include <stdio.h>
// Function to swap two float values
void interch(float *a, float *b) {
    float temp = *a;  // Store the value of *a in temp
    *a = *b;          // Assign the value of *b to *a
    *b = temp;        // Assign the stored value from temp to *b
}
// Quick Sort function to sort an array of floats
void Quick_sort(float a[], int m, int n) {
    if (m < n) {  // Check if there are more than one element to sort
        int i = m;    // Initialize left index
        int j = n + 1; // Initialize right index
        float key = a[m]; // Pivot element (first element of the partition)
        // Partitioning process
        while (1) {
            do {
                i++;  // Move i to the right until an element greater than key is found
            } while (a[i] < key);
            do {
                j--;  // Move j to the left until an element smaller than key is found
            } while (a[j] > key);
            if (i < j) {  // If indices have not crossed
                interch(&a[i], &a[j]);  // Swap elements
            } else {
                break;  // Exit loop if indices have crossed
            }
        }
        interch(&a[m], &a[j]); // Place the pivot element in its correct position
        Quick_sort(a, m, j - 1);  // Recursively sort the left partition
        Quick_sort(a, j + 1, n);  // Recursively sort the right partition
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    float arr[n];
    printf("Enter Array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    Quick_sort(arr, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
    return 0;
}


//for int 
/*
#include <stdio.h>
// Function to swap two integer values
void interch(int *a, int *b) {
    int temp = *a;  // Store the value of *a in temp
    *a = *b;        // Assign the value of *b to *a
    *b = temp;      // Assign the stored value from temp to *b
}

// Quick Sort function to sort an array of integers
void Quick_sort(int a[], int m, int n) {
    if (m < n) {  // Check if there are more than one element to sort
        int i = m;    // Initialize left index
        int j = n + 1; // Initialize right index
        int key = a[m]; // Pivot element (first element of the partition)
        // Partitioning process
        while (1) {
            do {
                i++;  // Move i to the right until an element greater than key is found
            } while (a[i] < key);
            do {
                j--;  // Move j to the left until an element smaller than key is found
            } while (a[j] > key);
            if (i < j) {  // If indices have not crossed
                interch(&a[i], &a[j]);  // Swap elements
            } else {
                break;  // Exit loop if indices have crossed
            }
        }
        interch(&a[m], &a[j]); // Place the pivot element in its correct position
        Quick_sort(a, m, j - 1);  // Recursively sort the left partition
        Quick_sort(a, j + 1, n);  // Recursively sort the right partition
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter Array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    Quick_sort(arr, 0, n - 1);  // Call Quick_sort to sort the array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

*/