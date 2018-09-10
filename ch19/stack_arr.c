#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "stack.h"


struct stack_type{
    Item * content;
    int size;
    int top;
};

static void terminate(char * message){
    printf("%s\n",message);
    exit(EXIT_FAILURE);
}

Stack create(int size){
    Stack s;
    s = malloc(sizeof(struct stack_type));
    if(s == NULL)
        terminate("In create stack: out of memory.");

    s->content = malloc(size * sizeof(Item));
    if(s->content == NULL){
        free(s);
        terminate("In create stack: out of memory.");
    }

    s->top = 0;
    s->size = size;
    return s;
}

void destroy(Stack s){
    free(s->content);
    free(s);
}

void push(Stack s, Item i){
    if(is_full(s)){
        s->size *= 2;
        s->content = realloc(s->content,sizeof(Item) * s->size);
        if( s->content == NULL)
            terminate("In push to stack: out of memory.");
    }
    s->content[(s->top)++] = i;
}

int pop(Stack s){
    if(is_empty(s))
        terminate("In pop from stack: stack is empty.");
    return s->content[--(s->top)];
}

bool is_empty(Stack s){
    return s->top == 0;
}

bool is_full(Stack s){
    return s->top == s->size;
}

void make_empty(Stack s){
    s->top = 0;
}