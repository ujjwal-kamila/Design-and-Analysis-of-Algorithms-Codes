//Heap sort using int values
#include <stdio.h>

// Function to interchange (swap) two integer values
void interchInt(int *a, int *b) {
    int temp = *a;  // Temporary storage for *a
    *a = *b;        // Assign *b to *a
    *b = temp;      // Assign temp (original *a) to *b
}

// Function to maintain max heap property for an array of integers
void maxHeapifyInt(int A[], int i, int heap_size) {
    int l = 2 * i;            // Left child index
    int r = 2 * i + 1;        // Right child index
    int largest;

    // Find largest among root, left child, and right child
    if (l <= heap_size && A[l] > A[i])
        largest = l;
    else
        largest = i;

    if (r <= heap_size && A[r] > A[largest])
        largest = r;

    // If root is not the largest, swap with largest and heapify the affected sub-tree
    if (largest != i) {
        interchInt(&A[i], &A[largest]);
        maxHeapifyInt(A, largest, heap_size);  // Recursively heapify
    }
}

// Function to build a max heap from an array of integers
void buildMaxHeapInt(int A[], int length) {
    int heap_size = length - 1;
    // Perform max heapify from the middle of the array to the start
    for (int i = length / 2; i >= 0; i--) {
        maxHeapifyInt(A, i, heap_size);
    }
}

// Function to perform Heap Sort on an array of integers
void Heap_SortInt(int A[], int length) {
    int heap_size = length - 1;
    buildMaxHeapInt(A, length);  // Build the max heap
    // Extract elements from the heap one by one
    for (int i = length - 1; i >= 1; i--) {
        interchInt(&A[0], &A[i]);  // Move current root to the end
        heap_size--;               // Reduce heap size
        maxHeapifyInt(A, 0, heap_size);  // Heapify the reduced heap
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter Array elements: ");
    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print original array
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    Heap_SortInt(arr, n);  // Sort the array

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}





//Heap sort using float values 
/*
#include <stdio.h>

// Function to interchange (swap) two float values
void interch(float *a, float *b) {
    float temp = *a;  // Temporary storage for *a
    *a = *b;          // Assign *b to *a
    *b = temp;        // Assign temp (original *a) to *b
}

// Function to maintain max heap property for an array of floats
void maxHeapify(float A[], int i, int heap_size) {
    int l = 2 * i;            // Left child index
    int r = 2 * i + 1;        // Right child index
    int largest;

    // Find largest among root, left child, and right child
    if (l <= heap_size && A[l] > A[i])
        largest = l;
    else
        largest = i;

    if (r <= heap_size && A[r] > A[largest])
        largest = r;

    // If root is not the largest, swap with largest and heapify the affected sub-tree
    if (largest != i) {
        interch(&A[i], &A[largest]);
        maxHeapify(A, largest, heap_size);  // Recursively heapify
    }
}

// Function to build a max heap from an array of floats
void buildMaxHeap(float A[], int length) {
    int heap_size = length - 1;
    // Perform max heapify from the middle of the array to the start
    for (int i = length / 2; i >= 0; i--) {
        maxHeapify(A, i, heap_size);
    }
}

// Function to perform Heap Sort on an array of floats
void Heap_Sort(float A[], int length) {
    int heap_size = length - 1;
    buildMaxHeap(A, length);  // Build the max heap
    // Extract elements from the heap one by one
    for (int i = length - 1; i >= 1; i--) {
        interch(&A[0], &A[i]);  // Move current root to the end
        heap_size--;            // Reduce heap size
        maxHeapify(A, 0, heap_size);  // Heapify the reduced heap
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    float arr[n];
    printf("Enter Array elements: ");
    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // Print original array
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    Heap_Sort(arr, n);  // Sort the array

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}
*/