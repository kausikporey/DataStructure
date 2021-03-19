#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node *root;


struct node *createNode(int nodedata){
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = nodedata;
        newnode->left = 0;
        newnode->right = 0;
        return newnode;
}

void main(){
    struct node *ptr;
    root = 0;
    ptr = createNode(8);
    printf("%d",ptr->data);
}