#include<stdio.h>
#include<conio.h>

int partition(int arr[],int lb,int ub){
    int pivot = arr[lb];
    int start=lb,end=ub;
    while(start<end){
        while(arr[start] <= pivot){
            start++;
        }
        while(arr[end] > pivot){
            end--;
        }
        if(start < end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    int temp = arr[end];
    arr[end] = arr[lb];
    arr[lb] = temp;
    return end;
}
void quicksort(int arr[],int lb,int ub){
    if(lb<ub){
        int loc = partition(arr,lb,ub);
        quicksort(arr,lb,(loc-1));
        quicksort(arr,(loc+1),ub);
    }
}


void main(){
    int arr[] = {7,6,31,45,2,5,12,74,35};
    int len = (sizeof(arr)/sizeof(arr[0])-1);
    int ub=len,lb=0;
    quicksort(arr,lb,ub);
    for(int i = 0;i<=len;i++){
        printf("array element : %d\n",arr[i]);
    }
} 