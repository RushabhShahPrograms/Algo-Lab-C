#include <stdio.h>

// Function to heapify a subtree with a root at a given index
void maxHeapify(int arr[], int n, int i) {
    int largest = i;    // Initialize the largest element as the root
    int left = 2 * i + 1;  // Index of the left child
    int right = 2 * i + 2; // Index of the right child

    // If the left child is larger than the root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If the right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest element is not the root
    if (largest != i) {
        // Swap the root with the largest element
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        maxHeapify(arr, n, largest);
    }
}

// Function to build a max-heap from an array
void buildMaxHeap(int arr[], int n) {
    // Start from the last non-leaf node and heapify all nodes
    for (int i = (n / 2) - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
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

    // Build a max-heap from the input array
    buildMaxHeap(arr, n);

    printf("Max-Heapified array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

/*
Enter the number of elements: 8
Enter the elements: 1
2
5
4
7
8
3
9
Max-Heapified array: 9 7 8 4 1 5 3 2
*/
