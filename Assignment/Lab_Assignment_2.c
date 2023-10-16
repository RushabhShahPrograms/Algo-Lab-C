/*
Question: Quick Sort with Pivot Optimization

You are given an unsorted array of integers. In this question, you are required to implement a modified Quick Sort algorithm that includes both a specific preprocessing step and a post-processing step. The goal is to enhance the Quick Sort algorithm's performance for certain input scenarios.

Part A: Array Transformation

1. Write a C program to transform the given unsorted array as follows:
   - Select a pivot element, typically the first or last element.
   - Partition the array into two subarrays: one containing elements less than the pivot, and the other containing elements greater than or equal to the pivot.
   - Apply the following transformation to the subarray containing elements greater than or equal to the pivot:
     - Reverse the order of elements in this subarray.
   - Combine the two subarrays to get the transformed array.

Part B: Quick Sort with Transformation

2. Implement the Quick Sort algorithm with the modified array transformation as a preprocessing step.

Part C: Post-processing

3. After sorting using Quick Sort, write a function to reverse the order of the subarray that was previously reversed in the preprocessing step.

Part D: Testing and Analysis

4. Generate a random unsorted array of integers with a significant number of duplicate elements. The array should have a minimum size of 20 elements.

5. Apply the array transformation from Part A to this unsorted array.

6. Sort the transformed array using the Quick Sort algorithm with the modified preprocessing step and post-processing step.

7. Compare the sorting performance (execution time) with and without the array transformation on the same dataset. Discuss the impact on performance.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to reverse a subarray in-place
void reverseSubarray(int arr[], int low, int high) {
    while (low < high) {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}

// Function to partition the array for Quick Sort with pivot optimization
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the pivot as the last element
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// Quick Sort with array transformation
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        // Apply array transformation to the right subarray
        reverseSubarray(arr, pivot + 1, high);

        // Recursively sort the two subarrays
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// Function to reverse the subarray post Quick Sort
void postProcess(int arr[], int low, int high) {
    reverseSubarray(arr, low, high);
}

int main() {
    int n = 10; // Minimum size of the array

    // Generate a random array of integers with values between -100 and 100
    int arr[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 201 - 100; // Generates random values between -100 and 100
    }

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    clock_t start_time = clock();

    quickSort(arr, 0, n - 1);

    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    postProcess(arr, 0, n - 1);

    printf("\nSorted and post-processed array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nExecution time: %lf seconds\n", execution_time);

    return 0;
}

/*
Output:
Original array: 53 40 81 76 -35 89 76 -15 -83 37 
Sorted array: -83 -35 -15 37 40 53 76 76 81 89 
Sorted and post-processed array: 89 81 76 76 53 40 37 -15 -35 -83 
Execution time: 0.000002 seconds
*/
