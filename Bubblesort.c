#include <stdio.h>
#include <stdlib.h> // For rand() and srand()
#include <time.h>   // For clock() and CLOCKS_PER_SEC

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
double getExecutionTime(clock_t start, clock_t end) {
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
}

int main() {
    int arr[1000];
    int n = sizeof(arr) / sizeof(arr[0]);

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the array with random integers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Random integers between 0 and 999
    }

    // Optionally print the unsorted array
    printf("Unsorted array:\n");
    printArray(arr, n);

    // Record the start time
    clock_t start = clock();
    
    // Sort the array
    bubbleSort(arr, n);

    // Record the end time
    clock_t end = clock();

    // Calculate the elapsed time
    double time_taken = getExecutionTime(start, end);

    // Optionally print the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    printf("Time taken: %f miliseconds\n", time_taken);

    return 0;
}
