#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
    int data;
    struct node *next;
};

struct node *front=0,*rear=0;
void enqueue(int x){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = 0;
    if(front == 0 && rear == 0){
        front = rear = newnode;
    }else{
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue(){
    if(front == 0 && rear == 0){
        printf("Queue is empty.\n");
    }else if(rear == front){
        printf("%d is dequeued from the queue.\n",rear->data);
        free(rear);
        rear = front = 0;
    }else{
        struct node *temp;
        temp = front;
        front = front->next;
        printf("%d is dequeued from the queue.\n",temp->data);
        free(temp);
    }
}

void display(){
    struct node *temp;
    temp = front;
    while(temp != 0){
        printf("The element of the queue is %d\n",temp->data);
        temp = temp->next;
    }
}

void peek(){
    printf("The Front element of the queue is %d\n",front->data);
}

void main(){
    enqueue(5);
    enqueue(2);
    enqueue(1);
    enqueue(125);
    display();
    dequeue();
    display();
    peek();
}