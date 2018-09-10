#ifndef QUEUE_H
#define QUEUE_H
#include<stdbool.h>

typedef void* Item;
typedef struct queue_type * Queue;

Queue create(int size);
void destroy(Queue q);
void make_empty(Queue q);
void enqueue(Queue q, Item i);
Item dequeue(Queue q);
Item peek(Queue q);
bool is_empty(Queue q);
bool is_full(Queue q);

#endif