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
    }else if(rear<N-1){
        rear++;
        queue[rear] = x;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue is empty.\n");
    }else if(rear == front){
        rear = front = -1;
    }else{
        front++;;
    }
}

void display(){
    for(int i=front;i<=rear;i++){
        printf("The elements of the queue is %d.\n",queue[i]);
    }
}

void peek(){
    printf("The Front element of the queue is %d\n",queue[front]);
}

void main(){
    enqueue(5);
    enqueue(2);
    enqueue(1);
    display();
    dequeue();
    display();
    peek();
}