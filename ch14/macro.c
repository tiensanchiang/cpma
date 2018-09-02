#include<stdio.h>

int main(void){

    printf("Line Number: %d\n",__LINE__);
    printf("Function:%s",__func__);
    return 0;
}