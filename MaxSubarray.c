#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxCrossingSubarray(int arr[], int low, int mid, int high) {
    int leftSum = INT_MIN;
    int sum = 0;
    int i;

    for (i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }

    int rightSum = INT_MIN;
    sum = 0;

    for (i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }

    return leftSum + rightSum;
}

int maxSubarray(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    }

    int mid = (low + high) / 2;

    int leftSum = maxSubarray(arr, low, mid);
    int rightSum = maxSubarray(arr, mid + 1, high);
    int crossSum = maxCrossingSubarray(arr, low, mid, high);

    return max(max(leftSum, rightSum), crossSum);
}

int main() {
    int arr[] = {-2, -5, 6, -2, 3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxSubArray = maxSubarray(arr, 0, n - 1);

    printf("Maximum subarray sum is: %d\n", maxSubArray);

    return 0;
}

/*
Maximum subarray sum is: 13
*/
