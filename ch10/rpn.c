#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top=0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int c);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void){
    char ch;
    bool exit = false;

    while(!exit){
        make_empty();
        printf("Enter a RPN expression:");
        while(true){
            scanf(" %c",&ch);
            if(ch == '\n'){
                if(is_empty()){
                    printf("line----\n");
                    break;
                }else
                    printf("Value of expression: %d\n",pop());
            }else if( isdigit(ch) ){
                push(ch - '0');
            }else if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
                int num2 = pop();
                int num1 = pop();
                switch(ch){
                    case '+': push(num1 + num2);break;
                    case '-': push(num1 - num2);break;
                    case '*': push(num1 * num2);break;
                    case '/': push(num1 / num2);break;
                }
            }else{
                if(ch == '=')
                    printf("Value of expression1: %d\n",pop());
                else if(ch == '\n') 
                    continue;
                else
                    exit = true;
                break;
            }
        }        
    }

    return 0;
}

void make_empty(void){
    for(int i=0;i<STACK_SIZE;i++)
        contents[i] = 0;
}
bool is_empty(void){
    return top == 0;
}

bool is_full(void){
    return top == STACK_SIZE;
}

void push(int c){
    if(is_full())
        stack_overflow();
    else
        contents[top++] = c;
}

int pop(void){
    if(is_empty())
        stack_underflow();
    else
        return contents[--top];
    
    return EXIT_FAILURE;
}

void stack_overflow(void){
    printf("Stack overflow!\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void){
    printf("Stack underflow!\n");
    exit(EXIT_FAILURE);
}
