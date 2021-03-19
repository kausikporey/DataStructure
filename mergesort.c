#include<stdio.h>
#include<conio.h>

int arr2[8];

void merge(int arr[],int lb,int mid,int ub){
    int i=lb;
    int j=mid+1;
    int k = lb;
    while(i<=mid && j<=ub){
        if(arr[i] <= arr[j]){
            arr2[k] = arr[i];
            i++;
        }else{
            arr2[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
        arr2[k] = arr[j];
        j++;
        k++;
        }
    }else{
        while(i<=mid){
        arr2[k] = arr[i];
        i++;
        k++;
        }
    }
    for(k=lb;k<=ub;k++){
        arr[k] = arr2[k];
    }
}


void mergesort(int arr[],int lb,int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

void main(){
    int arr[8] = {7,6,31,45,2,5,1,35};
    int len = sizeof(arr)/sizeof(arr[0])-1;
    int lb = 0,ub = len;
    mergesort(arr,lb,ub);
    for(int i = 0;i<=len;i++){
        printf("array element : %d\n",arr[i]);
    }
}