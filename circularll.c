#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>


struct node{
    int data;
    struct node *next;
};

struct node *head,*tail;

void cerateLL(){
    struct node *newnode;
    int choice;
    head = 0;
    while(choice){
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Dara to insert : \n");
    scanf("%d",&newnode->data);
    if(head == 0){
        head = newnode;
        tail = newnode;
        newnode->next = newnode;
    }else{
        tail->next = newnode;
        newnode->next = head;
        tail = newnode;
    }
    printf("If you want to continue press 1\n");
    scanf("%d",&choice);
  }
}

void display(){
    struct node *temp;
    if(head == tail){
        printf("The only element of the list is %d.\n",head->data);
    }else{
         temp = head;
         while(temp->next != head){
            printf("Elements of the circular linked list is %d\n",temp->data);
            temp = temp->next;
        }
     printf("the last element of the list is : %d \n",tail->data);
 }
}

void insertatbeg(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data : \n");
    scanf("%d",&newnode->data);
    if(head == 0){
        head = tail = newnode->next = newnode;
    }else{
        newnode->next = head;
        head = newnode;
        tail->next = newnode;
    }
}


void insertatend(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data : \n");
    scanf("%d",&newnode->data);
    if(head == 0){
        head = tail = newnode->next = newnode;
    }else{
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}


void insertatpos(int pos){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data : \n");
    scanf("%d",&newnode->data);
    if(head == 0){
        head = tail = newnode->next = newnode;
    }else if(pos == 1){
        insertatbeg();
    }
    else{
       struct node *temp;
       temp = head;
       for(int i=1;i<(pos-1);i++){
           temp = temp->next;
       }
       newnode->next = temp->next;
       temp->next = newnode;
    }
}

void deletefrombeg(){
    struct node *temp;
    temp = head;
    head = head->next;
    tail->next = head;
    printf("The elements %d has been deleted from the list.\n");
    free(temp);
}

void deletefromend(){
    struct node *temp;
    temp = head;
    while(temp->next != tail){
        temp = temp->next;
    }
    temp->next = head;
    printf("The element %d from the end has been deleted.\n");
    free(tail);
    tail = temp;
}

void deletefrompos(int pos){
    struct node *temp,*delete;
    temp = head;
    for(int i=1;i<pos-1;i++){
        temp = temp->next;
    }
    delete = temp->next;
    temp->next = temp->next->next;
    printf("The element %d has deleted from the list.\n",delete->data);
    free(delete);
}
 void reverse(){
     struct node *nextnode,*prev,*current;
     current = head;
     prev = tail;
     while(nextnode != head){
         nextnode = current->next;
         current->next = prev;
         prev = current;
         current = nextnode;
     }
     head = prev;
     tail = current;
 }

void main(){
    cerateLL();
    display();
    printf("head : %d",head);
    printf("tail : %d",tail->next);
    // insertatbeg();
    // insertatend();
    // insertatpos(2);
    // deletefrombeg();
    // deletefromend();
    // deletefrompos(2);
    reverse();
    display();
}