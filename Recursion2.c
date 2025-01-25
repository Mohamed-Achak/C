#include <stdio.h>
#include <string.h>
int palindrome(char* arr, int start, int end) {
    
    if (start >= end)
    {
        return 1;
    }
    
    
    if (arr[start] != arr[end]) {
            return 0;

    }else{
        start++;
        end--;
        palindrome(arr, start, end);
         
    }
    
    
}

int main() {
    char arr[]= "level";
    int start = 0;
    int end = strlen(arr)-1;

    if (palindrome(arr, start, end) == 1)
    {
        printf("It is a palindrome");
    }else{
        printf("it is not");
    }
    



}
