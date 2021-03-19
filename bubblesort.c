#include<stdio.h>
#include<conio.h>

void bubblesort(){
    int arr[12] = {1,4,32,5,35,2,30,7,9,16,5,11};
    int len = sizeof(arr)/sizeof(arr[0])-1;
    for(int j = 0;j<len;j++){
        for(int i=0;i<(len-j);i++){
            if(arr[i] > arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
     }
    }
    for(int i = 0;i<=len;i++){
        printf("array element : %d\n",arr[i]);
    }
}

void main(){
    bubblesort();
}