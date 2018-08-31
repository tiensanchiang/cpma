#include<stdio.h>

int main(void){

    int first_num,second_num,first_deno,second_deno;
    int result_num,result_deno;

    printf("Enter two factions seperated by a plus sign:");
    scanf("%d/%d+%d/%d",&first_num,&first_deno,&second_num,&second_deno);

    result_num = first_num*second_deno + second_num*first_deno;
    result_deno = first_deno * second_deno;

    printf("The sum is %d/%d",result_num,result_deno);

    return 0;
}