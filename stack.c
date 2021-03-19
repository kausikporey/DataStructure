#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>


#define N 5
#define true 1
#define false 0
int stack[N];

int top = -1;

void push(int x){
    if(top == -1){
        top = 0;
        stack[top] = x;
    }else if(top<N-1){
        top++;
        stack[top] = x;
    }
}

void pop(){
    if(top == -1) {
        printf("stack is empty.\n");
    }
    else if(top == 0){
        printf("Poped item is %d\n",stack[top]);
        top = -1;
    }
    else{
        printf("Poped item is %d\n",stack[top]);
        top--;
    }
}

void peek(){
    if(top == -1){
        printf("Stack is empty.\n");
    }else{
    printf("Top element of the stack is %d\n",stack[top]);
   }
}

void display(){
    int i=0;
    for(i=top;i>=0;i--){
        printf("Item of the stack is %d\n",stack[i]);
    }
}

int isEmpty(){
    if(top == -1){
        return true;
    }else{
        return false;
    }
}
int isFull(){
    if(top == N-1){
        return true;
    }else{
        return false;
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
    printf("%d\n",isEmpty());
    printf("%d\n",isFull());
}