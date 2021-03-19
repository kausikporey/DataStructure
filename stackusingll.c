#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
    int data;
    struct node *next,*prev;
};

struct node *head;

void push(int x){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = 0;
    if(head == 0){
        head = newnode;
    }else{
        newnode->next = head;
        head = newnode;
    }
}

void pop(){
    if(head == 0){
        printf("Stack is empty.\n");
    }else{
        struct node *temp;
        temp = head;
        head = head->next;
        printf("Poped item is %d\n",temp->data);
        free(temp);
    }
}

void peek(){
    if(head == 0){
        printf("Stack is empty.\n");
    }else{
    printf("Top element of the stack is %d\n",head->next);
   }
}

void display(){
    struct node *temp;
    temp = head;
    while(temp != 0){
        printf("The element of the stack is %d\n",temp->data);
        temp = temp->next;
    }
}


void main(){
    push(4);
    push(7);
    push(1);
    push(7);
    push(10);
    display();
    pop();
    pop();
    display();
}