#include <stdio.h>
#include <string.h>

void password(char *arr, char *expression, int size, int level, int current_length) {
    if (level == current_length) {
        expression[level] = '\0'; //terminate the cuurect expression
        printf("%s\n", expression); // keep printitng
        return;
    } 


   
    for (int i = 0; i < size; i++) {
        expression[level] = arr[i]; 
        password(arr, expression, size, level + 1, current_length); 


    }
}

int main() {
    char arr[] = "ab";
    int size = strlen(arr); 
    char expression[size+1]; 

   for (int current_length = 1; current_length <= size; current_length++) {
        password(arr, expression, size, 0, current_length);
    }

    return 0;
}