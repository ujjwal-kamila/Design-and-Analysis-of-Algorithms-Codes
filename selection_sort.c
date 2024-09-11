//Selection sort c Program 

// For float arrray
#include <stdio.h>
// Function to perform selection sort on a float array
void selectionSortFloat(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the first element is the minimum
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update minIndex if a smaller element is found
            }
        }// Swap the found minimum element with the first element
        float temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Function to print a float array
void printArrayFloat(float arr[], int n) {
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);  // Read the size of the array
    float arr[n];  // Declare the float array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);  // Read the float array elements
    }
    selectionSortFloat(arr, n);  // Sort the array
    printArrayFloat(arr, n);  // Print the sorted array
    return 0;
}

/*
//For int array 
#include <stdio.h>
// Function to perform selection sort on an int array
void selectionSortInt(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the first element is the minimum
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update minIndex if a smaller element is found
            }
        }// Swap the found minimum element with the first element
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
// Function to print an int array
void printArrayInt(int arr[], int n) {
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);  // Read the size of the array
    int arr[n];  // Declare the int array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);  // Read the int array elements
    }
    selectionSortInt(arr, n);  // Sort the array
    printArrayInt(arr, n);  // Print the sorted array
    return 0;
}
*/