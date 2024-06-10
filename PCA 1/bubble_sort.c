// // Bubble sort Program

#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

// #include <stdio.h>
// int main()
// {
//     int n, j, i, swap;
//     printf("Enter number of elements: \n");
//     scanf("%d", &n);
//     int array[n];
//     printf("Enter %d elements: \n", n);
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", &array[i]);
//     }
//     for (i = 0; i < n - 1; i++)
//     {
//         for (j = 0; j < n - i - 1; j++)
//         {
//             if (array[j] > array[j + 1])
//             {
//                 swap = array[j];
//                 array[j] = array[j + 1];
//                 array[j + 1] = swap;
//             }
//         }
//     }
//     printf("Sorted list in ascending order :\n");
//     for (i = 0; i < n; i++)
//         printf("%d\n", array[i]);
//     return 0;
// }
