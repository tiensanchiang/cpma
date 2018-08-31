#include<stdio.h>

int main(void){

    int itemNumber;
    float unitPrice;
    int year,month,date;

    printf("Enter item number:");
    scanf("%d",&itemNumber);

    printf("Enter unit price:");
    scanf("%f",&unitPrice);

    printf("Enter purchase date (mm/dd/yyyy):");
    scanf("%d/%d/%d",&month,&date,&year);

    printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tdate\n");

    printf("%-4d\t\t$%7.2f\t\t%-.2d%.2d%.4d",itemNumber,unitPrice,month,date,year);
    return 0;
}