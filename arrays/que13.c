#include <stdio.h>
#include <limits.h>
//Write a program using pointers to interchange the second biggest and the second smallest number in the array.

int main() {
    int n;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Array needs at least 2 elements.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Find 1st and 2nd max/min values
    int max = INT_MIN, sec_max = INT_MIN;
    int min = INT_MAX, sec_min = INT_MAX;

    for (int i = 0; i < n; i++) {
        // Max tracking
        if (arr[i] > max) {
            sec_max = max;
            max = arr[i];
        } else if (arr[i] > sec_max && arr[i] != max) {
            sec_max = arr[i];
        }

        // Min tracking
        if (arr[i] < min) {
            sec_min = min;
            min = arr[i];
        } else if (arr[i] < sec_min && arr[i] != min) {
            sec_min = arr[i];
        }
    }

    // Check if valid 2nd elements were found
    if (sec_max == INT_MIN || sec_min == INT_MAX) {
        printf("Not enough distinct elements to swap.\n");
        return 1;
    }

    // Step 2: Assign pointers to these target values
    int *p_sec_max = NULL;
    int *p_sec_min = NULL;

    for (int i = 0; i < n; i++) {
        if (arr[i] == sec_max) p_sec_max = &arr[i];
        if (arr[i] == sec_min) p_sec_min = &arr[i];
    }

    // Step 3: Interchange using pointers
    int temp = *p_sec_max;
    *p_sec_max = *p_sec_min;
    *p_sec_min = temp;

    // Output results
    printf("\nSuccessfully swapped %d and %d.\n", *p_sec_min, *p_sec_max);
    printf("Modified array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}