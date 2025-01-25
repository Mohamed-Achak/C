#include <stdio.h>

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (arr[j] > arr[j - 1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {8, 5, 2, 3, 1, 6, 9, 4, 0, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Array before sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    bubble_sort(arr, n);

    printf("Array after sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
