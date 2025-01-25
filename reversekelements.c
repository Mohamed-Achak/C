#include <stdio.h>


void enqueue(char* queue,int* rear, int* front, int N, char element){
    if (*rear == N-1)
    {
        printf("queue is full");
    }else{
        (*rear)++;
        queue[*rear] = element;
    }
    
}
char dequeue(char* queue,int* rear, int* front){
    char ch;
    if (*rear == -1)
    {
        printf("Queue is empty");
        return '\0';    
    }else{
        ch = queue[*front];
        (*front)++;
        return ch;
    }
    
}

void push(char* stack, int* top, char element, int N){
    if (*top == N-1)
    {
        printf("stack is full");
    }else{
        (*top)++;
        stack[*top] = element;
    }
    
}

char pop(char* stack, int* top){
    char ch;
    if (*top == -1)
    {
        printf("stack is empty");
        return '\0';
    
    }else{
        
        ch = stack[*top];
        (*top)--;
        return ch;
    }
    
}





void reversetilk(char* arr,int k, char* stack, char* queue, int* rear, int* front, int* top, int N){
    char ch;
    int j=0;
    for (int i = 0; i < k; i++)
    {

        ch = dequeue( queue, rear, front);
        if (ch != '\0') push(stack, top, ch, N);
    }
    for (int i = 0; i < k; i++)
    {
        ch = pop( stack, top);
        if (ch != '\0') arr[j++] = ch;
    }

    while (*front <= *rear) {
        ch = dequeue(queue, rear, front);
        if (ch != '\0') arr[j++] = ch;
    }
    
       
        
    

}

int main(){
    int top = -1, front = 0, rear = -1, size =5;
    int k;
    char ch;
    char queue[size];
    char stack[size];
    char arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("please enter characters to add to the stack:");
        scanf(" %c", &ch);
        enqueue(queue, &rear, &front, size, ch);
        
    }
    
    printf("please specify the number of elements in the queue you want to reverse: ");
    scanf("%d", &k);
    
    
    reversetilk(arr, k,  stack,  queue,  &rear,  &front,  &top, size);

    
    
    for (int i = 0; i < size; i++)
    {
        
        printf("the reversed list is: %c\n", arr[i]);
    }
    
    




    return 0;
}