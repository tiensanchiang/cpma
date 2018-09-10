#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

int main(void){

    Queue q;
    int i,*n;

    q = create(10);

    printf("Insert values to queue:");
    for(i = 0;i<10;i++){
        printf("%d ",i*i);
        n = malloc(sizeof(int));
        *n = i*i;
        enqueue(q,n);
    }
    printf("\nQueue is empty: %s\n",is_empty(q)?"yes":"no");

    printf("\nPeeking first value: %d\n",*(int *)peek(q));

    n = (int*)dequeue(q);
    printf("\nRemoving first value: %d\n", *n);

    printf("\nInsert it back: %d\n",*n);
    enqueue(q,n);

    printf("\nValues in queue:\n");
    while(!is_empty(q)){
        n = (int*) dequeue(q);
        printf("%d ",*n);
        free(n);
    }
    printf("\n");

    printf("Queue is empty: %s\n",is_empty(q)?"yes":"no");

    printf("\nCreating a string queue.");
    Queue q2;

    q2 = create(10);
    char * word;
    printf("Insert words to queue:\n");
    for(i = 0;i<10;i++){
        word = malloc(sizeof(char) * 7);
        sprintf(word,"%s%1d","word",i);
        printf("%s ",word);
        enqueue(q2,word);
    }
    printf("\n");

    printf("Values in string queue:\n");
    while(!is_empty(q2)){
        word = dequeue(q2);
        printf("%s ",word);
        free(word);
    }
    printf("\n");
}