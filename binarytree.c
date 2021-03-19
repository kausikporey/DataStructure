#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>


struct node{
    int data;
    struct node *left,*right;
};

struct node *createTree(){
    struct node *newnode;
    int x;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to insert : (enter -1 to exit)\n");
    scanf("%d",&x);
    if(x == -1){
        return 0;
    }else{
        newnode->data = x;
        printf("Enter the left child of %d : \n",x);
        newnode->left = createTree();
        printf("Enter the right child of %d : \n",x);
        newnode->right = createTree();
        return newnode;
    } 
}

void preOrder(struct node *root){
    if(root == 0){
        return;
    }
    printf("Data : %d\n",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct node *root){
    if(root == 0){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("Data : %d\n",root->data);
}


void inOrder(struct node *root){
    if(root == 0){
        return;
    }
    inOrder(root->left);
    printf("Data : %d\n",root->data);
    inOrder(root->right);
}


void main(){
    struct node *root;
    root = 0;
    root = createTree();
    printf("This is the the Preorder traversal data : \n");
    preOrder(root);
    printf("This is the Inorder traversal data : \n");
    inOrder(root);
    printf("This is the Postorder traversal data : \n");
    postOrder(root);
}
