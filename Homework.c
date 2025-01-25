    #include <stdio.h>
    #include <string.h>

    int t_number = 1;



    typedef struct{
        char name[20];
        int ticket;
    }c_info;

    c_info fillcinfo(){
        c_info client;
        printf("please give the name of the client: ");
        scanf("%s", client.name);
        client.ticket = t_number;
        t_number++;

        return client;
    }

    void addClient(c_info* queue, int* front, int* rear, int N){
        c_info client = fillcinfo();
        if ( *front == -1 && *rear == -1)
        {
            *front =*rear = 0;
            queue[*rear] = client;
        }else if ((*rear + 1)%N == *front)
        {
            printf("the queue is full");
        }else{
            *rear = (*rear +1)%N;
            queue[*rear] = client;
        }
    }

    void serve(c_info* queue, int* front, int* rear, int N){
        if (*front == -1 && *rear == -1)
        {
            printf("the queue is empty");
        }else if (*rear == *front)
        {
            *rear = *front = -1;
        }else{
            *front = (*front+1)%N;
        }
        
        
    }
    void display(c_info* queue, int front, int rear, int N){
        
    if (front == -1 && rear == -1) {
        printf("The queue is empty\n");
    }else {
        printf("Clients in the queue:\n");
        for (int i = front; ; i = (i + 1) % N) {
            printf("Client Name: %s, Ticket Number: %d\n", queue[i].name, queue[i].ticket);
            if (i == rear) break;
        }
    }
}
 


    int main(){
        int front = -1;
        int rear = -1;
        int size = 5;
        c_info queue[size];
        int choice;
        
        do
        {
            printf("please choose an operation: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                addClient(queue, &front, &rear, size);
                break;
            case 2:
                serve(queue, &front, &rear, size);
                break;
            case 3:
                display(queue, front, rear, size);
                break;
            case 4:
                printf("Quitting the queue\n");
                front = rear = -1;
                break;
            case 5:
                printf("Ending the program\n");
                break;
            default:
                printf("incorrect choice");
                break;
            }
            
            
        } while (choice != 5);
        





        return 0;
    }


    