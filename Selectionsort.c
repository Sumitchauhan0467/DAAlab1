#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in the unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to measure time in milliseconds
double getExecutionTime(clock_t start, clock_t end) {
    return ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;
}

int main() {
    int arr[1000];
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Fill the array with random integers
    srand(time(0)); // Seed the random number generator
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Random integers between 0 and 999
    }

    printf("Unsorted array: \n");
    printArray(arr, n);
    
    // Record the starting time
    clock_t start = clock();
    
    // Perform Selection Sort
    selectionSort(arr, n);
    
    // Record the ending time
    clock_t end = clock();
    
    // Calculate the time taken in milliseconds
    double time_taken = getExecutionTime(start, end);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    
    printf("Selection Sort took %.2f milliseconds to sort the array.\n", time_taken);
    
    return 0;
}
