#include <stdio.h>

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the rightmost element as the pivot
    int i = (low - 1);  // Initialize the index of the smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;  // Increment the index of the smaller element
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);  // Place the pivot element in its correct position
    return (i + 1);
}

// Function to implement the Quick Sort algorithm
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find the pivot element, such that element smaller than the pivot
        // are on the left and elements greater than the pivot are on the right
        int pi = partition(arr, low, high);

        // Recursively sort the elements before and after the pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);  // Call Quick Sort to sort the array

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

/*
Enter the number of elements: 8
Enter the elements: 4
5
8
9
-3
-7
1
3
Sorted array: -7 -3 1 3 4 5 8 9
*/
