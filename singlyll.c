#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;

void display(){
    struct node *temp;
    temp = head;
    if(head == 0){
        printf("No node present in the linked list.\n");
    }
    else{
        while(temp != 0){
            printf("Data at position %d : %d\n",temp,temp->data);
            temp = temp->next;
        }
    }
}

void createLL(){
    struct node *newnode;
    int choice,count=0;
    struct node *temp;
    head = 0;
    while(choice){
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data to insert : \n");
    scanf("%d",&newnode->data);
    newnode->next = 0;
    if(head == 0){
        head = newnode;
        temp = newnode;
    }
    else{
        temp->next = newnode;
        temp = newnode;
        newnode=0;
    }
    count++;
    printf("Do you want to continue? Press 1 to continue and 0 to left.\n");
    scanf("%d",&choice);
   }
}

void insertatbeg(){
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data to insert : \n");
        scanf("%d",&newnode->data);
        newnode->next = head;
        head = newnode;
}


void insertatend(){
        if(head==0){
            insertatbeg();
        }
        else{
        struct node *newnode,*temp;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data to insert : \n");
        scanf("%d",&newnode->data);
        newnode->next = 0;
        temp=head;
        while(temp->next != 0){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}


void insertatpos(){
    int pos,i;
    if(head == 0 || pos==1){insertatbeg();}
    else{
        printf("Enter the position : \n");
        scanf("%d",&pos);
        if(pos<0){printf("Invalid Position.\n");}
        else{
        struct node *newnode,*temp;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data to insert : \n");
        scanf("%d",&newnode->data);
        temp = head;
        for(i=1;i<pos-1;i++){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
  }
}

void deletefrombeg(){
    struct node *temp;
    temp = head;
    head = head->next;
    printf("The Value %d has been deleted\n",temp->data);
    free(temp);
}


void deletefromend(){
    struct node *temp;
    temp = head;
    while(temp->next->next != 0){
        temp = temp->next;
    }
    printf("The Value %d has been deleted\n",temp->next->data);
    free(temp->next);
    temp->next = 0;
}


void deletefrompos(){
    int pos,i=1;
    struct node *temp,*currentnode;
    printf("Enter Position from where you want to delete.\n");
    scanf("%d",&pos);
    temp = head;
    while(i<pos-1){
        temp=temp->next;
    }
    currentnode = temp->next;
    temp->next = currentnode->next;
    printf("Deleted value from the linked list is %d.\n",currentnode->data);
    free(currentnode);
}

void length(){
    struct node *temp;
    int len=0;
    temp = head;
    while(temp != 0){
        temp = temp->next;
        len++;
    }
    printf("The length of the linked list is %d\n",len);
}

void reverse(){
    struct node *current,*nextnode,*prev;
    current = nextnode = head;
    prev = 0;
    while(nextnode != 0){
    nextnode = current->next;
    current->next = prev;
    prev = current;
    current = nextnode;
    }
    head = prev;
}

void main(){
    createLL();
    display();
    length();
    reverse();
    display();
}