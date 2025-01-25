#include <stdio.h>

void min_max(int* arr, int size, int* min, int* max) {
    if (size == 1) {
        // Base case: if there's only one element, it is both min and max
        *min = arr[0];
        *max = arr[0];
    } else {
        // Recursive case: get min and max of the first `size - 1` elements
        min_max(arr, size - 1, min, max);

        // Update min and max with the last element in the array
        if (arr[size - 1] > *max) {
            *max = arr[size - 1];
        }
        if (arr[size - 1] < *min) {
            *min = arr[size - 1];
        }
    }
}

int main() {
    int arr[4] = {1, 2, 5, 6};
    int min, max;
    min_max(arr, 4, &min, &max);
    printf("min: %d, max: %d\n", min, max);

    return 0;
}
