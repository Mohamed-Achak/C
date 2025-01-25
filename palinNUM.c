#include <stdio.h>








void main(){
    

    int x = 151;
    int original = x;
    int reverse= 0;

    for (int i = 0; i < 3; i++)
    {

        int rev = x%10;
        reverse = reverse *10 + rev;
        x = x/10;
        
    }
    
    if (original == reverse) {
        printf("%d is a palindrome.\n", original);
    } else {
        printf("%d is not a palindrome.\n", original);
    }
    
    
    
    


}