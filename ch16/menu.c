#include<stdio.h>
#include<ctype.h>
#include "menu.h"

void print_menu(void){
    printf("\nEnter your choice of operation\n");
    printf("[i]nsert, [u]pdate, [s]earch, [p]rint, [q]uit: ");
}

int get_choice(void){
    
    int ch ;
    while(!isalpha(ch=getchar()))
        ;
    
    while(getchar() != '\n')
        ;
    
    return tolower(ch);
}
