#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>

#define MAX_SIZE 80

bool is_palindrome_int(char message[],int len);
bool is_palindrome_ptr(char message[],int len);

int main(void){
    int count = 0;
    char message[MAX_SIZE];
    char ch;

    printf("Enter message:");
    while(true){
        ch = getchar();
        if(ch == '\n')
            break;
        else if( isalpha(ch)){
            message[count] = tolower(ch);
            count++;
            if(count == MAX_SIZE)
                break;
        }
    }

    if(is_palindrome_int(message,count))
        printf("Palindrome.\n");
    else
        printf("Not a palindrome.\n");
   
    if(is_palindrome_ptr(message,count))
        printf("Palindrome.\n");
    else
        printf("Not a palindrome.\n");
    return 0;
}

bool is_palindrome_int(char message[],int len){
    int  start, end;

    for(start = 0 , end = len-1; start<=end; start++,end--){
        if( message[start] != message[end] ){
            break;
        }
    }

    return start>=end;
}

bool is_palindrome_ptr(char message[], int len){
    char *start,*end;

    start = message;
    end = start + (len-1);
    while(start <= end){
        if(*start != *end)
            break;
        start++;
        end--;
    }

    return start>=end;
}