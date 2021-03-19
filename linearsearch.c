#include<stdio.h>
#include<conio.h>


void binarysearch(int *ptr,int a,int len){
    for(int i=0;i<len;i++){
        int x = *(ptr+i);
        if(a == x){
            printf("Number found at position %d\n",i+1);
            return;
        }
    }
    printf("Number not found in the array.\n");
}

void main(){
    int arr[5] = {1,2,4,5,6};
    int *ptr;
    ptr = arr;
    int len = sizeof(arr)/sizeof(arr[0]);
    binarysearch(ptr,6,len);
}