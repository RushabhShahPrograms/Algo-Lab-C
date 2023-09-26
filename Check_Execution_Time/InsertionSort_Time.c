#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n = 10000;  // Size of the array
    int arr[n];

    // Fill the array with random integers
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }

    clock_t start_time = clock();
    insertionSort(arr, n);
    clock_t end_time = clock();

    // Calculate execution time in milliseconds
    double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000;

    printf("Sorted array:\n");
    // Uncomment the following line if you want to print the sorted array
    // printArray(arr, n);
    
    printf("Execution Time: %lf ms\n", execution_time);

    return 0;
}
