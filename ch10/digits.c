#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>

#define MAX_DIGITS 10

int segments[10][7] = {
    {1,1,1,1,1,1,0},
    {0,1,1,0,0,0,0},
    {1,1,0,1,1,0,1},
    {1,1,1,1,0,0,1},
    {0,1,1,0,0,1,1},
    {1,0,1,1,0,1,1},
    {1,0,1,1,1,1,1},
    {1,1,1,0,0,0,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}
};
char digits[3][MAX_DIGITS * 4];

void clear_digits_array(void);
void process_digit(int digit,int position);
void print_digits_array(void);


int main(void){
    int inputs[MAX_DIGITS];
    int count=0;
    char c;

    clear_digits_array();

    printf("Enter a number:");
    while(true){
        scanf("%c",&c);
        if(isdigit(c)){
            inputs[count] = (c - '0');
            count++;
            if(count==MAX_DIGITS)
                break;
        }else if( c == '\n'){
            break;
        }
    }


    for(int i=0;i<count;i++)
        process_digit(inputs[i],i);
    print_digits_array();
    return 0;
}

void clear_digits_array(void){
    for(int i=0;i<3;i++){
        for(int j=0;j<MAX_DIGITS*4;j++){
            digits[i][j] = ' ';
        }
    }
}

void process_digit(int digit,int position){

    for(int i=0;i<7;i++){
        if(!segments[digit][i])
            continue;
        switch(i+1){
            case 1: 
                digits[0] [position * 4 + 1] = '_';
                break;
            case 2:
                digits[1] [position *4  + 2] = '|';
                break;
            case 3:
                digits[2] [position * 4 + 2] = '|';
                break;
            case 4:
                digits[2] [position*4+1] = '_';
                break;
            case 5:
                digits[2] [position*4] = '|';
                break;
            case 6:
                digits[1][position*4] = '|';
                break;
            case 7:
                digits[1][position*4+1] = '_';
                break;
            default:
                break;
        }
    }
}

void print_digits_array(void){
    for(int i=0; i<3; i++){
        for(int j=0; j<MAX_DIGITS*4; j++)
            printf("%c",digits[i][j]);
        printf("\n");
    }
}

