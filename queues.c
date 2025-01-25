#include <stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;





void enqueue(int x){
    if (rear == N-1)
    {
        printf("Overflow");
        return;
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] =x;
    }else{
        rear++;
        queue[rear]= x;
    }
    
}


void dequeue(){
    if (front == -1 && rear == -1)
    {
        printf("Underflow");
    }else if (front == rear)
    {
        front = rear = -1;
    }else{
        front++;
    }
    
}



void display(){

    if (front == -1 && rear == -1)
    {
        printf("empty queue");
    }else{
        for (int i = front; i < rear+1; i++)
        {
            printf("%d ", queue[i]);
        }
        
    }
    
}





int main(){
    enqueue(2);
    enqueue(3);
    display();
    dequeue();
    display(); 






    return 0;
}






