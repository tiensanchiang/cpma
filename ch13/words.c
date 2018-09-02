#include<stdio.h>
#include<string.h>

#define WORD_LEN 10
#define MAX_WORDS 10

int main(void){

    char words[MAX_WORDS][WORD_LEN];
    int count=0;

    char smallest_word [WORD_LEN] = {0};
    char largest_word [WORD_LEN] = {0};

    do{
        printf("Enter a word:");
        gets(words[count]);

        if( strlen(smallest_word)=0 || strcmp(words[count],smallest_word) < 0 )
            strcpy(smallest_word,words[count]);

        if( strcmp(words[count],largest_word)>0 )
            strcpy(largest_word,words[count]);

        
    }while( strlen(words[count]) != 4 && count++ < MAX_WORDS);

    printf("smallest: %s\n",smallest_word);
    printf("largest: %s\n", largest_word);

    return 0;
}