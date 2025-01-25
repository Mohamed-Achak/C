#include <stdio.h>
#include <stdlib.h>



typedef struct Node {
    int data;
    struct Node* next;
}node;

node* createanode(int x){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void enqueue(node* front, node* rear, node* toenqueue){
    if (front == NULL && rear == NULL)
    {
        front = rear = toenqueue;
        rear->next = front;
    }else{
        rear->next = toenqueue;
        rear = toenqueue;
        rear->next = front;
    }
    



}
void enqueue(node* front, node* rear){
    if (front == NULL && rear == NULL)
    {
        printf("List is empty");

    }else{
        node* temp = front;
        front = front->next;
        rear->next = front;
        free(temp);

    }
    





}


int main(){
    node* front = NULL;
    node* rear = NULL;




    return 0;
}