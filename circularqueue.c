#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

#define N 5

int queue[N];
int rear=-1,front=-1;

void enqueue(int x){
    if(front == -1 && rear == -1){
        front = rear = 0;
        queue[front] = x;
    }else if((rear+1)%N == front){
        printf("Queue is Full.\n");
    }else{
        rear = (rear+1)%N;
        queue[rear] = x;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue is empty.\n");
    }else if(rear == front){
        rear = front = -1;
    }else{
        front = (front+1)%N;
    }
}

void display(){
    int i=front;
    while(i != rear){
        printf("The elements of the queue is %d.\n",queue[i]);
        i = (i+1)%N;
    }
    printf("The elements of the queue is %d\n",queue[rear]);
}

void peek(){
    printf("The Front element of the queue is %d\n",queue[front]);
}

void main(){
    enqueue(5);
    enqueue(2);
    enqueue(1);
    enqueue(14);
    enqueue(2);
    display();
    dequeue();
    dequeue();
    enqueue(9);
    enqueue(7);
    printf("\n");
    display();
    peek();
}