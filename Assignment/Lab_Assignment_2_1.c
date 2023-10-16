/*
Question: Maximum Subarray Problem with User-Defined Array Length

You are tasked with finding the maximum subarray sum in a randomly generated array of integers within the range of -100 to 100. Your goal is to design an algorithm using the Divide and Conquer approach.

1. Implement a C function that takes an array length as input from the user. Generate a random array of integers of the specified length within the range of -100 to 100.

2. Next, design a Divide and Conquer algorithm to find the maximum subarray sum within the generated array. Your function should return both the maximum sum and the starting and ending indices of the subarray.

3. Apply your algorithm to find the maximum subarray sum for a user-defined array length, such as 30, 50, or 100, with random integers generated within the specified range.

4. Discuss the time complexity of your algorithm.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<limits.h>

// Function to find the maximum of three integers
int max(int a, int b, int c) {
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

// Function to find the maximum subarray sum using the Divide and Conquer approach
int maxCrossingSum(int arr[], int low, int mid, int high, int* start, int* end) {
    int leftSum = INT_MIN;
    int sum = 0;
    *start = mid;

    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
            *start = i;
        }
    }

    int rightSum = INT_MIN;
    sum = 0;
    *end = mid + 1;

    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
            *end = i;
        }
    }

    return leftSum + rightSum;
}

int maxSubarraySum(int arr[], int low, int high, int* start, int* end) {
    if (low == high) {
        *start = *end = low;
        return arr[low];
    }

    int mid = (low + high) / 2;

    int leftStart, leftEnd, rightStart, rightEnd, crossStart, crossEnd;

    int leftMax = maxSubarraySum(arr, low, mid, &leftStart, &leftEnd);
    int rightMax = maxSubarraySum(arr, mid + 1, high, &rightStart, &rightEnd);
    int crossMax = maxCrossingSum(arr, low, mid, high, &crossStart, &crossEnd);

    if (leftMax >= rightMax && leftMax >= crossMax) {
        *start = leftStart;
        *end = leftEnd;
        return leftMax;
    } else if (rightMax >= leftMax && rightMax >= crossMax) {
        *start = rightStart;
        *end = rightEnd;
        return rightMax;
    } else {
        *start = crossStart;
        *end = crossEnd;
        return crossMax;
    }
}

void generateRandomArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 101) - 50;
    }
}

int main() {
    int n;
    printf("Enter the length of the array: ");
    scanf("%d", &n);

    int arr[n];
    generateRandomArray(arr, n);

    printf("Generated Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    int start, end;
    int maxSum = maxSubarraySum(arr, 0, n - 1, &start, &end);

    printf("\nMaximum Subarray Sum: %d\n", maxSum);
    printf("Starting Index: %d\n", start);
    printf("Ending Index: %d\n", end);

    return 0;
}

/*
Enter the length of the array: 7
Generated Array: -3 34 -17 42 -1 -42 -26 
Maximum Subarray Sum: 59
Starting Index: 1
Ending Index: 3
*/
