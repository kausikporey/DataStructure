#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

#define N 10

int tree[N];

void createTree(){ 
    int x,i=0;
    while(x != -1){
    printf("Enter the elements of the tree : (-1 for exit)\n");
    scanf("%d",&x);
    if(x == -1){
        printf("Tree has been build successfully.\n");
        return;
    }else{
        tree[i] = x;
        i++;
    }
  }
}

void display(){
    for(int i=0;i<N;i++){
        if(tree[i] == 0){continue;}
        else{
            printf("The elements at %d position of the tree is : %d\n",i,tree[i]);
        }
    }
}

void main(){
    createTree();
    display();
}