#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

#define N 5
int deque[N];
int f=-1,r=-1;

void enquefront(int x){
    int i = f-1;
    if(f == -1 && r == -1){
        f = r = 0;
        deque[f] = x;
    }else if(f == 0 && f != N-1){
        f = N-1;
        deque[f] = x;
    }else if(r != i){
        f--;
        deque[f] = x;
    }else{
        printf("Deque is full\n");
    }
}

void enquerear(int x){
    int i = r+1;
    if(f == -1 && r == -1){
        f = r = 0;
        deque[r] = x;
    }else if(r == N-1 && f != 0){
        r=0;
        deque[r] = x;
    }
    else if(f != i){
        r++;
        deque[r] = x;
    }else{
        printf("Deque is full.\n");
    } 
}

void dequefront(){
    if(f == N-1){
        f = 0;
        printf("The dequed element from the front is %d\n",deque[N-1]);
    }else if(f == r){
        printf("The dequed element from the front is %d\n",deque[f]);
        f = r = -1;
    }
    else{
        printf("The dequed element from the front is %d\n",deque[f]);
        f++;
    }
}

void dequerear(){
     if(r == 0){
        r = N-1;
        printf("The dequed element from the rear is %d\n",deque[0]);
     }else if(f == r){
        printf("The dequed element from the rear is %d\n",deque[r]);
        f = r = -1;
     }
     else{
        printf("The dequed element from the rear is %d\n",deque[r]);
        r--;
     }
}

void display(){
    int i = f;
    while(i != r){
        printf("The elements of the deque at %d th position is %d\n",i,deque[i]);
        i = (i+1)%N;
    }
    printf("The elements of the deque is at %d position %d\n",r,deque[r]);
}

void getfront(){
    printf("The front element of the deque is %d\n",deque[f]);
}

void getrear(){
    printf("The rear element of the deque is %d\n",deque[r]);
}

void main(){
    enquerear(7);
    enquerear(4);
    display();
    printf("\n");
    enquefront(1);
    enquefront(2);
    display();
    printf("\n");
    dequefront();
    dequerear();
    display();
}