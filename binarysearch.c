#include<stdio.h>
#include<conio.h>

void binarysearch(int data){
    int arr[4] = {5,7,9,15};
    int len = (sizeof(arr)/sizeof(arr[0]))-1;
    printf("array length : %d\n",len);
    int l=0,r,mid;
    r = len;
    while(l != r){
        mid = (l+r)/2;
        if(arr[l] == data){
            printf("Data found at position %d\n",l+1);
            l=r;
        }else if(arr[r] == data){
            printf("Data found at position %d\n",r+1);
            l=r;
        }
        else if(arr[mid] == data){
            printf("The number found at the position : %d\n",mid+1);
            l=r;
        }else if(arr[mid] > data){
            r = mid-1;
        }else if(arr[mid] < data){
            l = mid+1;
        }
    }
}


void main(){
    binarysearch(15);
}