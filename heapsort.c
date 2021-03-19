#include<stdio.h>
#include<conio.h>

        
int arr[10];
int len = 0;
int fixed_length=0;
void swap(int x,int y){
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}
void heapsortinsert(int length,int data){
    fixed_length++;
    len = length+1;
    arr[len] = data;
    int i = len;
    while(i >1){
        int parent = i/2;
        if(arr[parent] < arr[i]){
        int temp = arr[i];
        arr[i] = arr[parent];
        arr[parent] = temp;
        i=parent;
        }else{return;}
    }
}

void delete(int parent){
    int child1 = 2*parent;
    int child2 = (2*parent)+1;
    if(child1 > len || child2 > len){
        return;
    }
    else if(arr[child1] > arr[child2]){
        if(arr[parent] < arr[child1]){
            swap(parent,child1);
            parent = child1;
            delete(parent);
        }
    }
    else if(arr[child1] < arr[child2]){
        if(arr[parent] < arr[child2]){
            swap(parent,child2);
            parent = child2;
            delete(parent);
        }
    }    
}

void getheap(){
    for(int i = len+1;i<=fixed_length;i++){
        printf("Heap value at position %d is %d\n",i,arr[i]);
    }
}

void heapsortdelete(){
    swap(1,len);
    int heap = len;
    len = len-1;
    int parent = 1;
    delete(parent);
}

void main(){
    heapsortinsert(len,12);
    heapsortinsert(len,70);
    heapsortinsert(len,45);
    heapsortinsert(len,55);
    heapsortinsert(len,40);
    heapsortinsert(len,80);
    printf("fixed length : %d\n",fixed_length);
    printf("........Before Delete......\n");
    for(int j = 1;j<=len;j++){
        printf("%d\t",arr[j]);
    }
    printf("\n\n");
    heapsortdelete();
    heapsortdelete();
    heapsortdelete();
    printf("..........After Delete............\n");
    for(int j = 1;j<=len;j++){
        printf("%d\t",arr[j]);
    }
    printf("\n");
    printf("fixed length : %d\n",fixed_length);
    getheap(fixed_length);
}