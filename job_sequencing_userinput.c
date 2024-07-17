// algo_js(d, s, n)
// {
//     // pi  = pi +1
//     //  d[ri] = d[j[i+1]]
//     d[0] = j[0] : = 0 j[1] : = 1;
// k:=1
//     for i = 2 to n do
//     {
//     r:
//         = k;
//         while (d[j[r]] > d[i] and d[j[r]] != r)
//         {
//         r:
//             = r - 1;
//         }
//         if (d[j[r]] <= d[i] and d[i] = r)
//         {
//             for
//             q:
//                 = k to r + 1 step1 do
//                 {
//                     j[q + 1] = j[q];
//                 }
//             j[r + 1] : = i;
//         k:
//             = k + 1
//         }
//     }
//     return (k);
// }

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;       // Job ID
    int deadline; // Deadline of job
    int profit;   // Profit of job
} Job;

// Function to compare two jobs according to their profit
int compare(const void *a, const void *b)
{
    Job *job1 = (Job *)a;
    Job *job2 = (Job *)b;
    return job2->profit - job1->profit; // Descending order
}

// Function to implement the Job Sequencing algorithm
void algo_js(Job jobs[], int n)
{
    int *result = (int *)malloc(n * sizeof(int)); // To store result (Sequence of jobs)
    int *slot = (int *)malloc(n * sizeof(int));   // To keep track of free time slots

    // Initialize all slots to be free
    for (int i = 0; i < n; i++)
    {
        slot[i] = 0;
    }

    // Iterate through all given jobs
    for (int i = 0; i < n; i++)
    {
        // Find a free slot for this job (we start from the last possible slot)
        for (int j = (jobs[i].deadline < n ? jobs[i].deadline - 1 : n - 1); j >= 0; j--)
        {
            // Free slot found
            if (slot[j] == 0)
            {
                result[j] = i; // Add this job to result
                slot[j] = 1;   // Mark this slot filled
                break;
            }
        }
    }

    // Print the result in the desired format
    printf("Job sequence to maximize profit: ");
    for (int i = 0; i < n; i++)
    {
        if (slot[i])
        {
            printf("job-%d ", jobs[result[i]].id);
        }
    }
    printf("\n");
    // Free allocated memory
    free(result);
    free(slot);
}

int main()
{
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    Job *jobs = (Job *)malloc(n * sizeof(Job));
    printf("Enter the deadlines and profits of the jobs:\n");
    for (int i = 0; i < n; i++)
    {
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
