//Insertion Sort for int values
#include <stdio.h>

void insertionSortInt(int arr[], int n) {
    int i, j, key;     

    for (i = 1; i < n; i++) {
        key = arr[i];   // Store the current element as the key
        j = i - 1;      // Set the comparison index to the previous element

        // Move elements that are greater than the key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Shift element to the right
            j = j - 1;            // Move one position back
        }
        arr[j + 1] = key;         // Insert the key in its correct position
    }
}

// Function to print the array
void printArrayInt(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);    
    printf("\n");
}

int main() {
    int n; 
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n]; 
    printf("Enter %d integer elements:\n", n);
    // Input the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    insertionSortInt(arr, n);  
    printf("Sorted array: \n");
    printArrayInt(arr, n);     
    return 0;
}


/*
//Insertion Sort for float values
#include <stdio.h>

void insertionSort(float arr[], int n) {
    int i, j;          
    float key;         

    // Loop through elements, starting from the second element (index 1)
    for (i = 1; i < n; i++) {
        key = arr[i];   // Store the current element as the key
        j = i - 1;      // Set the comparison index to the previous element

        // Move elements that are greater than the key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Shift element to the right
            j = j - 1;            // Move one position back
        }
        arr[j + 1] = key;
    }
}

// Function to print the array
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
    // Input the array elements
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }
    insertionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
*/