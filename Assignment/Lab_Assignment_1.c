/*
Implement the following sorting problem using the Merge sort algorithm. Here we use a different ordering
<o between two integers. Let a1a2 . . . ak and b1b2 . . . bk be two integers of k digits. Here a1a2 . . . ak <o
b1b2 . . . bk if ai < bi for the last i where ai and bi differ. As per this newly defined ordering the following
follows: 12 <o 13 <o 23 <o 14 <o 24 <o 34 <o 15 <o 25 <o 35 <o 45.
1. Let n and m be two positive integers (input to your code). These two integers can be large (maybe of 20 bits).
2. Here n is the number of m digit integers which will be considered in your code. Thus n and m are
considered in such way that we can have valid computations.
3. Consider n many random m digit integers. This is generated randomly inside your code. Store
these n integers inside an array A and print the array.
4. Sort the array A using Merge sort algorithm where our new defined ordering <o will be used to
determine the ordering of the integers.
5. Print the final sorted array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Custom comparison function for the defined ordering <o
int customCompare(const void *a, const void *b) {
    int ai = *((int *)a);
    int bi = *((int *)b);
    int diff_pos = -1;  // Position of the last differing digit

    // Find the position of the last differing digit
    for (int i = 0; i < sizeof(int) * 8; i++) {
        int bit_a = (ai >> i) & 1;
        int bit_b = (bi >> i) & 1;
        if (bit_a != bit_b) {
            diff_pos = i;
        }
    }

    // Compare based on the last differing digit
    return ((ai >> diff_pos) & 1) - ((bi >> diff_pos) & 1);
}


// Merge function for Merge sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (customCompare(&L[i], &R[j]) < 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


// Merge sort function
void mergeSort(int arr[], int l, int r) {

    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


int main() {
    srand(time(NULL));

    int n, m;
    printf("Enter the number of integers (n): ");
    scanf("%d", &n);
    printf("Enter the number of digits per integer (m): ");
    scanf("%d", &m);

    int A[n];

    // Generate n random m-digit integers and store them in A
    for (int i = 0; i < n; i++) {
        int num = 0;
        for (int j = 0; j < m; j++) {
            if (j == 0) {
                num = num * 10 + rand() % 9 + 1; // Ensure the first digit is not 0
            } else {
                num = num * 10 + rand() % 10;
            }
        }
        A[i] = num;
    }

    printf("Unsorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Sort the array using Merge sort with custom comparison
    mergeSort(A, 0, n - 1);

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}


/*
Enter the number of integers (n): 6
Enter the number of digits per integer (m): 2
Unsorted Array:
28 35 76 63 61 71 
Sorted Array:
28 35 61 63 71 76 
*/
