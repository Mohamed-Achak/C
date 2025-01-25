#include <stdio.h>
int t_number = 1;

typedef struct
{
    char name[20];
    int ticket;
}c_info;

c_info fillclient(){
    c_info client;
    printf("please give the client a name: ");
    scanf("%s", client.name);
    client.ticket = t_number;
    t_number++;
    return client;
}

void addaclient(c_info* queue,int* front,int* rear, int N){
    c_info client = fillclient();
    if (*front == -1 && *rear == -1)
    {
        *rear = *front = 0;
        queue[*rear] = client;
    }else if ((*rear+1)%N == *front)
    {
        printf("Queue is full");
    }else{
        *rear = (*rear+1)%N;
        queue[*rear] = client;
    }
    
    
}


void serveclient(int* front,int* rear,int N){
    if (*rear == -1 && *front == -1)
    {
        printf("queue is empty");
    }else if (*rear == *front)
    {
        *front = *rear = -1;
    }else{
        *front = (*front+1)%N;
    }
    
}

void print(int front,int rear,c_info* queue,int N){
    int i = front;
    if (rear == -1 && front == -1)
        printf("Queue is empty\n");
    else{
        printf("The clients are: \n");
        while (i != rear)
        {
            printf("%s\n", queue[i].name);
            printf("ticket #%d\n", queue[i].ticket);
            i = (i+1)%N;
        }
        printf("%s\n", queue[i].name);
        printf("ticket #%d\n", queue[i].ticket);
    }

}


void menu(){
    printf("1. Add a New Client\n2. Serve a Client\n3. Print List of Clients in the Queue\n4. Quit the Queue\n5. End the Program\n");
}





int main(){
int front = -1, rear = -1, choice;
int N=5;
c_info queue[5];



do
{
    menu();
    printf("please choose: ");
    scanf("%d", &choice);
    
    switch (choice)
    {
    case 1:
        addaclient(queue, &front, &rear, N);
        break;
    case 2:
        serveclient(&front, &rear, N);
        break;
    case 3:
        print( front, rear, queue, N);
        break;
    case 4:
        printf("Quitting the queue\n");
        front = rear = -1;
        break;
    case 5:
        printf("Goodbye");
        break;    
    default:
        printf("invalid choice");
        break;
    }
} while (choice !=5);



    return 0;
}