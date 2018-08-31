#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top=0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char c);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void){
    char c;

    printf("Enter parentheses and/or braces: ");
    while( true ){
        scanf("%c",&c);
        if(c == '\n'){
            if(is_empty()){
                printf("Parentheses or braces are nested properly.\n");
            }else{
                printf("Parentheses or braces are not nested properly.\n");
            }
            break;
        }else if( c == '{' || c=='('){
            push(c);
        }else if( c== '}'){
            if(pop() != '{'){
                printf("Parentheses or braces are not nested properly.\n");
                break;
            }
        }else if( c == ')'){
            if(pop() != '('){
                printf("Parentheses or braces are not nested properly.\n");
                break;
            }
        }
    }

    return 0;
}

void make_empty(void){
    for(int i=0;i<STACK_SIZE;i++)
        contents[i] = '\0';
}

bool is_empty(void){
    return top == 0;
}

bool is_full(void){
    return top == STACK_SIZE;
}

void push(char c){
    if(is_full())
        stack_overflow();
    else
        contents[top++] = c;
}

char pop(void){
    if(is_empty())
        stack_underflow();
    else
        return contents[--top];
}

void stack_overflow(void){
    printf("Stack overflow!\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void){
    printf("Stack underflow!\n");
    exit(EXIT_FAILURE);
}
