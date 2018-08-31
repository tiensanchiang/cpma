#include<stdio.h>

#define DIGIT_LEN 10

int main(void){
    int digit;
    long num;

    int digit_seen[DIGIT_LEN] = {0};

    printf("Enter a number:");
    scanf("%d",&num);

    printf("Repeated digital(s)");
    while(num>0){
        digit = num % 10;
        digit_seen[digit]++;
        if(digit_seen[digit] == 2)
            printf(" %d",digit);
        num /= 10;
    }

    // printf("Repeated digital(s):");
    // for(int i=0;i<DIGIT_LEN;i++){
        // if(digit_seen[i]>1)
            // printf(" %d",i);
    // }
    
    
    return 0;
}