#include <stdio.h>

void print_array(int *arr, int size) {  // Equivalent to 'int *arr'
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int numbers1[] = {1, 2, 3};
    int numbers2[] = {4, 5, 6, 7};

    print_array(numbers1, 3); // Works!
    print_array(numbers2, 4); // Also works!
    return 0;
}