#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

struct stack_node{
    Item data;
    struct stack_node * next;
};

struct stack_type{
    struct stack_node * top;
};

static void terminate(char * message){
    printf("%s\n",message);
    exit(EXIT_FAILURE);
}

Stack create(int size){
    Stack s;
    s = malloc(sizeof(struct stack_node));
    if(s == NULL){
        terminate("In create stack: out of memory.");
    }
    s->top= NULL;

    return s;
}

void destroy(Stack s){
    make_empty(s);
    free(s);
}

void make_empty(Stack s){
    while(!is_empty(s)){
        pop(s);
    }
}

void push(Stack s,Item item){
    struct stack_node * np ;
    np = malloc(sizeof(struct stack_node));
    
    if(np == NULL)
        terminate("In push to stack: out of memory.");
    
    np->data = item;
    
    np->next = s->top;
    s->top = np;
}

Item pop(Stack s){
    if(is_empty(s))
        terminate("In pop from stack: stack is empty.");
    
    struct stack_node * oldtop = s->top;
    Item data = oldtop -> data;
    s->top = oldtop->next;
    free(oldtop);

    return data;
}

bool is_empty(Stack s){
    return s->top == NULL;
}

bool is_full(Stack s){
    return false;
}

