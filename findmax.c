#include <stdio.h>

int max(int* arr, int n){
    
    if (n == 1)
    {
        return arr[n-1];
    }
    


    int Max = max(arr, n-1);


    if (Max > arr[n-1]) return Max;
    else return arr[n-1];
    

    
  
}


        

    













void main(){
    int n = 5;
    int arr[] = {1,4,8,5,7};

    
    





}