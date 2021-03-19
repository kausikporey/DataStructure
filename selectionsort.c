#include<stdio.h>
#include<conio.h>

void selectionsort(){
    int arr[8] = {7,6,31,45,2,6,5,35};
    int len = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<len-1;i++){
        int min = i,j;
        for(j=i+1;j<len;j++){
            if(arr[j]<arr[min]){min = j;}
        }
        if(min != i){
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
    for(int i = 0;i<len;i++){
        printf("array element : %d\n",arr[i]);
    }
}

void main(){
    selectionsort();
}