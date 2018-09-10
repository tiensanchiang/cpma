#include<stdio.h>
#include<ctype.h>
#include "readline.h"

int i = 10;
void read_line(char * str, int len){
    int count = 0,ch;

    while(isspace(ch=getchar()))
        ;

    while( ch != '\n' && ch != EOF){
        if(count < len)
            str[count++] = ch;
        ch = getchar();
    }

    str[count] = '\0';
}

void read_line2(char * str, int len){
    int count = 0,ch;

    ch = getchar();
    while( ch != '\n' && ch != EOF){
        if(count < len)
            str[count++] = ch;
        ch = getchar();
    }

    str[count] = '\0';
}