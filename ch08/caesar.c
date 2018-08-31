#include<stdio.h>
#include<ctype.h>

#define LINE 10

int main(void){
    char message[LINE] = {0};
    int shift_num;
    int count;
    char c;

    printf("Enter message to encrypted:");
    while((c=getchar()) != '\n'){
        message[count] = c;
        count++;
        if(count == LINE){
            while(getchar() != '\n')
                ;
            break;
        }
    }

    printf("Enter shift amount (1-25):");
    scanf("%d",&shift_num);
    
    printf("Encrypted message:");
    for(int i=0; i<count; i++){
        c = message[i];
        if(isalpha(c)){
           if(islower(c)){
               putchar( (c-'a' + shift_num)%26 +'a' );
           }else{
               putchar( (c-'A' + shift_num)%26 +'A' );
           }
        }else{
            putchar(c);
        }
    }
    printf("\n");
    return 0;
}