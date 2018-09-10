#include<stdio.h>

int main(){

    int val = 1;
    int * arr;

    if(val == 0){
        arr = (int[]){1,2,3};
    }else{
        arr = (int[]){4,5,6};
    }
    int val2 = 10;

    for(int i=0;i<3;i++){
        printf("%d ",*arr++);
    }
    printf("\n");
}