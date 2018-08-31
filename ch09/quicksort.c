#include<stdio.h>
#define N 10

int partition(int arr[],int low,int high);
void quicksort(int arr[],int low,int high);

int main(void){
    int arr [N];

    printf("Enter %d numbers: ",N);
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
    quicksort(arr,0,N-1);
    printf("In sorted order:");
    for(int i=0;i<N;i++)
        printf(" %d",arr[i]);
    printf("\n");

    // quicksort(arr,0,6);
    // printf("Array after partition:");
    // for(int i=0;i<7;i++){
        // printf("%d ",arr[i]);
    // }
    // printf("\n");
    // return 0;
}

void quicksort(int arr[],int low,int high){
    int middle;
    if(low >= high)
        return;
    middle = partition(arr,low,high);
    quicksort(arr,low,middle-1);
    quicksort(arr,middle+1,high);
}

int partition(int arr[],int low,int high){
    int ele = arr[low];
    int direction = -1;

    while(low != high){
        if(direction < 0){
            if(arr[high]<ele){
                direction = 1;
                arr[low] = arr[high];
                arr[high] = ele;
            }else{
                high--;
            }
        }else{
            if(arr[low]>ele){
                direction = -1;
                arr[high] = arr[low];
                arr[low] = ele;
            }else{
                low++;
            }
        }
    }
    return low;
}