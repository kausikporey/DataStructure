#include<stdio.h>
#include<conio.h>

        
int arr[17] = {2,1,1,0,2,5,4,0,2,8,7,7,9,2,0,1,9};
int len = sizeof(arr)/sizeof(arr[0]);

void countsort(){
    int k = 10;
    int count[]={0,0,0,0,0,0,0,0,0,0},arr2[len];
    for(int i=0;i<len;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<k;i++){
        count[i] = count[i]+count[i-1];
    }
    for(int i=len-1;i>=0;i--){
        int value = arr[i];
        count[value] = count[value]-1;
        int position = count[value];
        arr2[position] = value;
    }
    for(int i=0;i<len;i++){
        arr[i]=arr2[i];
    }
}

void main(){
    countsort();
    printf(".............Final Array..........\n");
    for(int j = 0;j<len;j++){
        printf("array element at position %d : %d\n",j,arr[j]);
    }
}