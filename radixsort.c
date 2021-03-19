#include<stdio.h>
#include<conio.h>

        
int arr[10] = {15,1,321,10,802,2,123,90,109,11};
int len = sizeof(arr)/sizeof(arr[0]);


int getmax(){
    int max = 0;
    for(int i=0;i<len;i++){
        if(arr[max]<arr[i]){
            max = i;
        }
    }
    printf("The max number from the array is : %d\n",arr[max]);
    return arr[max];
}


void countsort(int pos){
    int i,k = 10;
    int count[]={0,0,0,0,0,0,0,0,0,0},arr2[len];
    for(int i=0;i<len;i++){
        int digit = (arr[i]/pos)%10;
        count[digit] = count[digit]+1;
    }
    for(int i=1;i<k;i++){
        count[i] = count[i]+count[i-1];
    }
    for(int i = (len-1);i>=0;i--){
        int value = ((arr[i]/pos)%10);
        count[value] = count[value]-1;
        arr2[count[value]] = arr[i];
    }
    for(int i=0;i<len;i++){
        arr[i]=arr2[i];
    }
}


void radixsort(){
    int max = getmax();
    for(int pos=1;max/pos>0;pos=pos*10){
        printf("....................position : %d...................\n\n",pos);
        countsort(pos);
        for(int j = 0;j<len;j++){
        printf("%d\t",arr[j]);
        }
        printf("\n\n");
    }
}


void main(){
    radixsort();
    printf(".............Final Array..........\n");
    for(int j = 0;j<len;j++){
        printf("array element at position %d : %d\n",j,arr[j]);
    }
}