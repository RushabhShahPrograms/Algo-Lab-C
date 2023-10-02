#include <stdio.h>

int maxSubArray(int arr[], int size) {
    int max_sum = arr[0];
    int current_sum = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > current_sum + arr[i]) {
            current_sum = arr[i];
        } else {
            current_sum = current_sum + arr[i];
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    return max_sum;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, -1, -5, -4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = maxSubArray(arr, size);

    printf("Maximum subarray sum: %d\n", result); // Output: 6 (corresponding to the subarray [4, -1, 2, 1])

return 0;
}
