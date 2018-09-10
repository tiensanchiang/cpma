#include<ctype.h>
#include<stdio.h>

typedef unsigned char BYTE;

int main(void){
    
    unsigned long addr = 0;
    int i,n;
    BYTE *ptr;

    printf("Address of main function: %.8lX\n",(unsigned long) main);
    printf("Address of addre variable: %.8lX\n",(unsigned long) &addr);

    printf("\nEnter a (hex) address:");
    scanf("%lX",&addr);

    printf("Enter number of bytes to view:");
    scanf("%d",&n);

    printf("\n");
    printf("Address                 Bytes            Charaters\n");
    printf("---------- ----------------------------- ----------\n");

    ptr = (BYTE*) addr;
    for(;n>0;n-=10){
        printf("%.10lX ",(unsigned long)ptr);
        for(i=0;i<10 && i<n;i++){
            printf("%.2X ",*(ptr + i));
        }
        for(;i<10;i++)
            printf("   ");
        // printf(" ");

        for(i=0;i<10&&i<n;i++){
            BYTE ch = *(ptr+i);
            if(isprint(ch)){
                putchar(ch);
            }else{
                putchar('.');
            }
        }

        ptr+=10;
        printf("\n");
    }

}