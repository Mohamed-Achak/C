#include <stdio.h>
#include <stdlib.h>




typedef struct node
{
    int x;
    struct node* next;
}node;



node* front = NULL;
node* rear = NULL;

void enqueue(int x){
     node* newnode = (node*)malloc(sizeof(node));
     newnode->x = x;
     newnode->next = NULL;
     if (front == NULL && rear == NULL)
     {
        front = rear = newnode;
     }else{
        rear->next = newnode;
        rear = newnode;
     }
}

void display(){
   if (front == NULL && rear == NULL)
   {
      printf("queues is empty");
   }else{
      node* walker = front;

      while (walker != NULL)
      {
         printf("%d \n", walker->x);
         walker = walker->next;
      }
      
   }
   
}


void dequeue(){
    node* temp = front;
    temp= front;
    if (front == NULL && rear == NULL)
    {
      printf("queues is empty");

    }else
    {
      front = front->next;
      free(temp);
    }
    
    
}


 