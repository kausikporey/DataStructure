#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>


struct node{
    int data;
    struct node *left,*right;
};

struct node *root,*rootpt;


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


struct node *createNode(int nodedata){
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = nodedata;
        newnode->left = 0;
        newnode->right = 0;
        return newnode;
}


void insert(struct node *rootptr,int value){
    if(root == 0){
        root = createNode(value);
    }
    else{
        if(value > rootptr->data){
            if(rootptr->right == 0){
                rootptr->right = createNode(value);
            }else{
                insert(rootptr->right,value);
            }
        }
        else if(value < rootptr->data){
            if(rootptr->left == 0){
                rootptr->left = createNode(value);
            }else{
                insert(rootptr->left,value);
            }
        }
    }
 }


void delete(int value){
    struct node *temp,*temp2;
    printf("rootpt : %d\n",rootpt->data);
    if(value == root->data){
        printf("Deleted data from the root : %d\n",root->data);
         temp2 = rootpt;
            temp = rootpt->left;
            while(temp->right != 0){
                temp = temp->right;
            }
            printf("temp : %d\n",temp->data);
            int x = temp->data;
            delete(x);
            temp2->data = x;
        }
    else if(value == rootpt->right->data){
        if(rootpt->right->left == 0  &&  rootpt->right->right == 0){
            printf("Deleted data from right : %d\n",rootpt->right->data);
            free(rootpt->right);
            rootpt->right = 0;
        }else if(rootpt->right->left == 0){
            printf("Deleted data right left : %d\n",rootpt->right->data);
            temp = rootpt->right;
            rootpt->right = rootpt->right->right;
            free(temp);
        }else if(rootpt->right->right == 0){
            printf("Deleted data from left right : %d\n",rootpt->right->data);
            temp = rootpt->right;
            rootpt->right = rootpt->right->left;
            free(temp);
        }
        else if(rootpt->right->right != 0 && rootpt->right->left != 0){
            temp = rootpt->right;
            temp2 = rootpt->right;
            while(temp->right != 0){
                temp = temp->right;
            }
            printf("tamp : %d\n",temp->data);
            printf("Deleted data : %d\n",rootpt->right->data);
            int x = temp->data;
            delete(x);
            temp2->data = x;
          }
    }
     else if(value == rootpt->left->data){
        if(rootpt->left->left == 0  &&  rootpt->left->right == 0){
            printf("Deleted data from left : %d\n",rootpt->left->data);
            free(rootpt->left);
            rootpt->left = 0;
        }else if(rootpt->left->left == 0){
            printf("Deleted data left left : %d\n",rootpt->right->data);
            temp = rootpt->left;
            rootpt->left = rootpt->left->right;
            free(temp);
        }else if(rootpt->left->right == 0){
            printf("Deleted data from left right : %d\n",rootpt->right->data);
            temp = rootpt->left;
            rootpt->left = rootpt->left->left;
            free(temp);
        }
        else if(rootpt->left->right != 0 && rootpt->left->left != 0){
            temp2 = rootpt->left;
            temp = rootpt->left;
            while(temp->right != 0){
                temp = temp->right;
            }
            printf("temp : %d\n",temp->data);
            printf("Deleted data : %d\n",rootpt->left->data);
            int x = temp->data;
            delete(x);
            temp2->data = x;
        }
  }
    else if(value > rootpt->data){
                    rootpt = rootpt->right;
                    delete(value);
                }
    else if(value < rootpt->data){
                    rootpt = rootpt->left;
                    delete(value);
                }
    else{
        printf("Else part.\n");
    }            
}



void main(){
    //struct node *root;
    root = 0;
    //int choice;
    // while(choice){
    //     int x;
    //     printf("Enter data you want to insert : \n");
    //     scanf("%d",&x);
    //     insert(root,x);
    //     printf("If you want to exit press 0.\n");
    //     scanf("%d",&choice);
    // }
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
    insert(root,7);
    inOrder(root);
    rootpt = root;
    delete(8);
    rootpt = root;
    delete(17);
    rootpt = root;
    delete(22);
    printf("After deleting the value : \n");
    inOrder(root);
}