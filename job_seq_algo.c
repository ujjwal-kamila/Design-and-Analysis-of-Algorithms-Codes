// Job Sequencing Algo with runtime input 
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Job {
    char id[3]; 
    int dead;
    int profit;
} Job;

// Comparator function to sort jobs in decreasing order of profit
int compare(const void* a, const void* b) {
    Job* temp1 = (Job*)a;
    Job* temp2 = (Job*)b;
    // Sort in descending order based on profit
    return (temp2->profit - temp1->profit);
}

// Function to return the minimum of two numbers
int min(int num1, int num2) {
    return (num1 > num2) ? num2 : num1;
}

// Function to perform job scheduling for maximum profit
void printJobScheduling(Job arr[], int n) {
    qsort(arr, n, sizeof(Job), compare);
    int result[n];  // Array to store the job sequence
    bool slot[n];   // Boolean array to track if a time slot is occupied
    // Initialize all time slots to false (i.e., all are free)
    for (int i = 0; i < n; i++)
        slot[i] = false;

    // Iterate through all jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (starting from the job's deadline)
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
            // If the slot is free, assign this job to that slot
            if (slot[j] == false) {
                result[j] = i;  // Store the job index in the result
                slot[j] = true; // Mark the slot as occupied
                break;          // Break the loop once the job is placed
            }
        }
    }
    // Print the jobs that were scheduled in the result array
    printf("Job sequence for maximum profit: ");
    for (int i = 0; i < n; i++) {
        if (slot[i])  // If a job was assigned to this slot
            printf("%s ", arr[result[i]].id);  // Print the job ID
    }
    printf("\n");
}

int main() {
    //job ID, deadline, and profit
    Job arr[] = {
        {"j1", 2, 85}, 
        {"j2", 1, 36}, 
        {"j3", 2, 69}, 
        {"j4", 3, 52},  
        {"j5", 1, 105}  
    };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Following is the maximum profit sequence of jobs:\n");
    printJobScheduling(arr, n);
    return 0;
}
