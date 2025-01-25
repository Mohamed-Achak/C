#include <stdio.h>

void printReverse(int arr[], int size, int index) {
    
    if (index < 0) {
        return;
    }else{

    
    printf("%d\n", arr[index]);

    
    printReverse(arr, size, index - 1);
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);

    
    printReverse(array, size, size - 1);

    return 0;
}
