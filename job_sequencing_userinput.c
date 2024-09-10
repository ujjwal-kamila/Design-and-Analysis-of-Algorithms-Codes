// Job Sequencing Algo with User input 

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;       
    int deadline;
    int profit;
} Job;

// Function to compare two jobs according to their profit
int compare(const void *a, const void *b){
    Job *job1 = (Job *)a;
    Job *job2 = (Job *)b;
    return job2->profit - job1->profit; // Descending order
}

// Function to implement the Job Sequencing algorithm
void algo_js(Job jobs[], int n){
    int *result = (int *)malloc(n * sizeof(int)); // To store result (Sequence of jobs)
    int *slot = (int *)malloc(n * sizeof(int));   // To keep track of free time slots
    // Initialize all slots to be free
    for (int i = 0; i < n; i++){
        slot[i] = 0;
    }
    // Iterate through all given jobs
    for (int i = 0; i < n; i++){
        // Find a free slot for this job (we start from the last possible slot)
        for (int j = (jobs[i].deadline < n ? jobs[i].deadline - 1 : n - 1); j >= 0; j--){
            // Free slot found
            if (slot[j] == 0){
                result[j] = i; // Add this job to result
                slot[j] = 1;   // Mark this slot filled
                break;
            }
        }
    }

    // Print the result in the desired format
    printf("Job sequence to maximize profit: ");
    for (int i = 0; i < n; i++){
        if (slot[i]){
            printf("job-%d ", jobs[result[i]].id);
        }
    }
    printf("\n");
    // Free allocated memory
    free(result);
    free(slot);
}

int main(){
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    Job *jobs = (Job *)malloc(n * sizeof(Job));
    printf("Enter the deadlines and profits of the jobs:\n");
    for (int i = 0; i < n; i++){
        jobs[i].id = i + 1;
        printf("Job %d - Deadline: ", i + 1);
        scanf("%d", &jobs[i].deadline);
        printf("Job %d - Profit: ", i + 1);
        scanf("%d", &jobs[i].profit);
    }
    // Sort the jobs according to their profits in descending order
    qsort(jobs, n, sizeof(Job), compare);
    // Call the Job Sequencing function
    algo_js(jobs, n);
    // Free allocated memory
    free(jobs);
    return 0;
}
