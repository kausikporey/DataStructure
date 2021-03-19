#include<stdio.h>
#include<conio.h>

void insertionsort(){
    int arr[4] = {7,6,5,35};
    int len = sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<len;i++){
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    for(int i = 0;i<len;i++){
        printf("array element : %d\n",arr[i]);
    }
}

void main(){
    insertionsort();
}