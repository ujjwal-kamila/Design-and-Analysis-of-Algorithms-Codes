
//for int 
#include <stdio.h>
void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;  // Size of the first subarray
    int n2 = r - q;      // Size of the second subarray
    // Create temporary arrays
    int L[n1], R[n2];
    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    // Merge the temporary arrays back into arr[p..r]
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// Function to sort array using merge sort algorithm
void mergeSort(int arr[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;  // Find the middle point
        mergeSort(arr, p, q);  // Recursively sort the first half
        mergeSort(arr, q + 1, r);  // Recursively sort the second half
        merge(arr, p, q, r);  // Merge the sorted halves
    }
}
// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integer elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

/*
//for float  
#include <stdio.h>
void merge(float arr[], int p, int q, int r) {
    int n1 = q - p + 1;  // Size of the first subarray
    int n2 = r - q;      // Size of the second subarray
    // Create temporary arrays
    float L[n1], R[n2];
    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    // Merge the temporary arrays back into arr[p..r]
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// Function to sort array using merge sort algorithm
void mergeSort(float arr[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;  // Find the middle point
        mergeSort(arr, p, q);  // Recursively sort the first half
        mergeSort(arr, q + 1, r);  // Recursively sort the second half
        merge(arr, p, q, r);  // Merge the sorted halves
    }
}
// Function to print an array
void printArray(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
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
    mergeSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
*/