#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "readline.h"

#define WORD_LEN 20

typedef int (*func_sort)(const void *, const void *);

int sort_str(const void * p, const void * q);

void * s_malloc(size_t size){
    void * p;
    p = malloc(size);
    if(p == NULL){
        printf("Out of memory!\n");
        exit(EXIT_FAILURE);
    }

    return p;
}

int main(void){
    printf("%d\n",i);
    func_sort sort;
    sort = sort_str;

    int max_size = 10,current_size = 0;
    char ** words;
    char * p;
    char ipt[WORD_LEN+1];

    words = s_malloc(sizeof(char*) * max_size);
    for(;;){
        printf("Enter word:");
        read_line2(ipt,WORD_LEN);
        if(strlen(ipt) == 0)
            break;

        if(current_size > max_size){
            max_size *= 2;
            words = realloc(words,sizeof(char*) * max_size);
            if(words == NULL){
                printf("Out of memory!\n");
                exit(EXIT_FAILURE);
            }
        }

        p = s_malloc(strlen(ipt) + 1);
        strncpy(p,ipt,strlen(ipt));
        p[strlen(ipt) ] = '\0';

        words[current_size] = p;
        current_size++;
    }

    printf("\nOriginal words:\n");
    for(int i=0;i<current_size;i++){
        printf("%s ",words[i]);
    }
    printf("\n");

    qsort(words,current_size,sizeof(char*),sort);
    printf("\nSorted words:\n");
    for(int i=0;i<current_size;i++){
        printf("%s ",words[i]);
    }
    printf("\n");

    return 0;
}

int sort_str(const void * p, const void *q){
    return strcmp(*(const char**)p, *(const char**)q);
}