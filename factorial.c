#include <stdio.h>
#include <string.h>


void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}


int power(int base, int exp){
    
    if (exp == 0)
    {
        return 1;
    }else{
        return base * power( base, exp-1);
    }
    
}








int main(){
    printf("%d",power(2, 4));
    





    return 0;
}