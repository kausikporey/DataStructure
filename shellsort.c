#include<stdio.h>
#include<conio.h>

        
int arr[9] = {23,29,15,19,31,7,9,5,2};
int len = (sizeof(arr)/sizeof(arr[0]));

void shellsort(){
    int gap,temp,i,j;
    for(gap=len/2;gap>= 1;gap=gap/2){
       for(j=gap;j<len;j++){
           for(i=(j-gap);i>=0;i=(i-gap)){
               if(arr[i+gap] > arr[i]){
                   break;
               }else{
                   temp = arr[i+gap];
                   arr[i+gap] = arr[i];
                   arr[i] = temp;
               }
               for(int k = 0;k<len;k++){
                    printf("%d\t",arr[k]);
                }
                printf("\n");
           }
       }
       printf("\n\n");
   }
}

void main(){
    shellsort();
    printf(".............Final Array..........\n");
    for(int j = 0;j<len;j++){
        printf("array element at position %d : %d\n",j,arr[j]);
    }
}