#include<stdio.h>
#define N 10

void selection_sort(int arr[],int len);

int main(void){
    int arr[N];
    int i;
    
    printf("Enter %d numbers:", N);
    
    for(i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }

    selection_sort(arr,N);
    
    printf("Array in sorted:");
    for(i=0;i<N;i++){
        printf(" %d",arr[i]);
    }
    printf("\n");

    return 0;
}

void selection_sort(int arr[], int len){
    int tmp,max,index;
    if(len==0)
        return;

    index = 0;
    max = arr[0];
    for(int i=0;i<len;i++){
        if(arr[i]>max){
            max = arr[i];
            index = i;           
        }
    }

    tmp = arr[len - 1];
    arr[len - 1] = max;
    arr[index] = tmp;

    selection_sort(arr,len - 1);
}