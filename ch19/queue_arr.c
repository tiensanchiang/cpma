#include<stdio.h>
#include<stdlib.h>
#include "queue.h"


struct queue_type{
    Item * content;
    int insert;
    int remove;
    int length;
    int size;
};

static void terminate(char * message){
    printf("%s\n",message);
    exit(EXIT_FAILURE);
}

Queue create(int size){
    Queue q;

    q = malloc(sizeof(struct queue_type));
    if( q == NULL)
        terminate("In create queue: out of memory.");

    q->content = malloc(sizeof(Item) * size);
    if(q->content == NULL){
        free(q);
        terminate("In create queue: out of memory.");
    }

    q->length = 0;
    q->insert = 0;
    q->remove = 0;
    q->size = size;

    return q;
}

void destroy(Queue q){
    free(q);
}

void enqueue(Queue q, Item i){
    if(is_full(q)){
        terminate("In insert to queue: queue is full.");
    }

    q->content[q->insert++] = i;
    if(q->insert == q->size){
        q->insert = 0;
    }

    q->length++;
}

Item dequeue(Queue q){
    if(is_empty(q)){
        terminate("In remove queue: queue is empty.");
    }
    Item i = q->content[q->remove++];
    
    if(q->remove == q->size){
        q->remove = 0;
    }
    q->length--;

    return i;
}

Item peek(Queue q){
    return q->content[q->remove];
}
bool is_empty(Queue q){
    return q->length == 0;
}

bool is_full(Queue q){
    return q->size == q->length;
}
