#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

#define N 5

int s1[N],s2[N];
int top1=-1,top2=-1,count = 0;;

void push1(int x){
    if(top1 == -1){
        top1=0;
        s1[top1] = x;
    }else if(top1<N-1){
        top1++;
        s1[top1] = x;
    }
}


void push2(int x){
    if(top2 == -1){
        top2=0;
        s2[top2] = x;
    }else if(top2<N-1){
        top2++;
        s2[top2] = x;
    }
}

int pop1(){
    if(top1 == 0){
        int a = s1[top1];
        top1=-1;
        return a;
    }else{
        int a = s1[top1]; 
        top1--;
        return a;
    }
}


int pop2(){
    if(top2 == 0){
        int b = s2[top2];
        top2=-1;
        return b;
    }else{
        int b = s2[top2];
        top2--;
        return b;
    }
}

void enqueue(int x){
    push1(x);
    count++;
}

void dequeue(){
    if(top1 == -1 && top2 == -1){
        printf("Queue is empty.\n");
    }else{
        int i;
        i = count;
        while(i != 0){
        int b = pop1();
        push2(b);
        i--;
      }
    int a = pop2();
    printf("The dequeued item of the queue is %d\n",a);
    count--; 
    int j = count;
    while(j != 0){
        push1(pop2());
        j--;
    }
    }
}

void display(){
    for(int i=0;i<count;i++){
      printf("The elements of the queue is %d\n",s1[i]);
    }
}
void main(){
    enqueue(8);
    enqueue(7);
    enqueue(0);
    display();
    dequeue();
    dequeue();
    display();
}