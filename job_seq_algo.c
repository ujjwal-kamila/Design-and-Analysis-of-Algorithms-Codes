// Job Sequencing Algo with runtime input 
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Job {
    char id[3]; 
    int dead; 
    int profit; 				
} Job;
int compare(const void* a, const void* b) {
    Job* temp1 = (Job*)a;
    Job* temp2 = (Job*)b;
    return (temp2->profit - temp1->profit);
}
int min(int num1, int num2) {
    return (num1 > num2) ? num2 : num1;
}
void printJobScheduling(Job arr[], int n) {
    qsort(arr, n, sizeof(Job), compare);
    int result[n]; 
    bool slot[n];  
    for (int i = 0; i < n; i++)
        slot[i] = false;
    for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = i; 
                slot[j] = true; 
                break;}
        }
    }
    for (int i = 0; i < n; i++)
        if (slot[i])
            printf("%s ", arr[result[i]].id);
}
int main() {
    Job arr[] = {
        {"j1", 2, 85},
        {"j2", 1, 36},
        {"j3", 2, 69},
        {"j4", 3, 52},
        {"j5", 1, 105}
    };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Following is the maximum profit sequence of jobs are :\n");
    printJobScheduling(arr, n);
    return 0;
}
