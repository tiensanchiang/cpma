#include<stdio.h>

int main(void){
    int ch,len=0;

    printf("Enter a message:");

    do{
        ch = getchar();
        len++;
    }while(ch != '\n');

    printf("Your message is %d character(s) long.",len-1);

    return 0;
}