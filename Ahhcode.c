#include <stdio.h>


void IDclone(int n, int arr[]){
    for (int i = 1; i < n; i++)
    {
        int id = arr[i];
        
             for (int j = 0; j < i; j++)
             {
                if (arr[j] == id)
                {
                    printf("dublicate id detected please enter a new id");
                    scanf("%d", &id);
                    arr[i]= id;
                    j= -1;
                }
                
             }
             
        }
        
    }
    
    


void checkid(int* id) {
     
        while (*id > 9999 || *id < 1000)
        {
            printf("ID can't be a non 4 degit number, please re-enter");
            scanf("%d", id);
            
        }
  
}


void creds(int  n, int arr[]){
    
    for (int i = 0; i < n; i++) {
    int creds;  

    do {
        printf("Please give the credits of the student %d\n", i + 1);
        scanf("%d", &creds);

        if (creds > 135 || creds < 0) {
            printf("Credits can't be more than 135 or less than 0. Please re-enter.\n");
        }
    } while (creds > 135 || creds < 0);

    arr[i] = creds;  
}


}


int main() {
    int n, id;
    printf("please tell how many students you are inputing");
    scanf("%d", &n);
    int arr[20];
    int arr2[20];


    for (int i = 0; i < n; i++)
    {
        printf("please give  the id of the students\n");
        scanf("%d",  &id);

        checkid(&id);
        arr[i] = id;
    
    }


    IDclone(n, arr);


    
    

        creds(n, arr2);

    
    
        
    

    


    
        
  
     
    return 0;
}
