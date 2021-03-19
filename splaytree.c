#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node *root;


void inOrder(struct node *rootptr){
    if(rootptr == 0){
        return;
    }
    inOrder(rootptr->left);
    printf("Data : %d\n",rootptr->data);
    inOrder(rootptr->right);
}


struct node *createNode(int nodedata){
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = nodedata;
        newnode->left = 0;
        newnode->right = 0;
        return newnode;
}

void insert(struct node *rootptr,int value){
    struct node *newnode,*temp;
    newnode = createNode(value);
    temp = rootptr;
    struct node *parent;
    parent = 0;
    while(temp != 0){
        parent = temp;
        if(temp->data > value){
            temp = temp->left;   
        }else{
            temp = temp->right;
        }  
    }
    if(parent == 0){root = newnode;}
    else if(parent->data > value){parent->left = newnode;}
    else{parent->right = newnode;}
}

void main(){
    root = 0;
    insert(root,11);
    insert(root,6);
    insert(root,25);
    insert(root,17);
    insert(root,43);
    insert(root,13);
    insert(root,7);
    insert(root,14);
    insert(root,22);
    insert(root,21);
    insert(root,23);
    insert(root,60);
    insert(root,4);
    insert(root,8);
    insert(root,3);
    insert(root,5);
    printf("..................Inorder traversal ..............\n");
    inOrder(root);
}