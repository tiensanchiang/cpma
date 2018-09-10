#include<stdio.h>
#include<stdlib.h>
#include "queue.h"


struct queue_node{
    Item value;
    struct queue_node * next;
};


struct queue_type{
    struct queue_node * head;
    struct queue_node * tail;
    int length;
};

static void terminate(char * message){
    printf("%s\n",message);
    exit(EXIT_FAILURE);
}

Queue create(int size){
    Queue q;

    q = malloc(sizeof(struct queue_type));
    if(q == NULL)
        terminate("In create queue: out of memory.");
    q->head = NULL;
    q->tail = NULL;
    q->length = 0;

    return q;
}

void destroy(Queue q){
    make_empty(q);
    free(q);
}

void make_empty(Queue q){
    while(!is_empty(q)){
        dequeue(q);
    }
}

void enqueue(Queue q, Item i){
    struct queue_node * np;

    np = malloc(sizeof(struct queue_node));
    if(np == NULL)
        terminate("In enqueue to queue: out of memory.");
    np->next = NULL;
    np->value = i;

    if(q->tail != NULL){
        q->tail->next = np;
        q->tail = np;
    }else{
        np->next = q->head;
        q->head = np;
        q->tail = np;
    } 
    q->length++;
}

Item dequeue(Queue q){
    Item i;
    struct queue_node * oldhead;

    if(is_empty(q))
        terminate("In dequeue from queue: queue is empty.");

    oldhead = q->head;

    i = oldhead->value;

    if(oldhead -> next == NULL){  //head and tail pointers to same node
        q->head = q->tail = NULL;
    }else{ 
        q->head = oldhead->next;
    }

    free(oldhead);
  
    return i;
}

Item peek(Queue q){
    if(q->tail == NULL)
        terminate("In peek queue: queue is empty.");

    return q->head->value;
}

bool is_empty(Queue q){
    return q->head == NULL;
}

bool is_full(Queue q){
    return false;
}
