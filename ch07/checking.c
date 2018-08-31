#include<stdio.h>

int main(void){
    int cmd;
    float balance=0.0f,credit,debit;;

    printf("*** ACME checkbook balancing program ***\n");
    printf("Commands: 0=clear, 1=credit, 2=debit, ");
    printf("3=balance, 4=exist\n\n");

    for(;;){
        printf("Enter command:");
        if(scanf("%d",&cmd)){
            switch(cmd){
                case 0:
                    balance = .0f;
                    break;
                case 1:
                    printf("Enter amount of credit:");
                    scanf("%f",&credit);
                    balance+=credit;
                    break;
                case 2:
                    printf("Enter amount of debit:");
                    scanf("%f",&debit);
                    balance-=debit;
                    break;
                case 3:
                    printf("Current balance: $%.2f\n",balance);
                    break;
                case 4:
                    return 0;
                default:
                    printf("Commands: 0=clear, 1=credit, 2=debit, ");
                    printf("3=balance, 4=exist\n");
                    char c;
                    do{
                        scanf("%c",&c);
                    }while(c != '\n');
                    break;
            }
        }else{
            char c;
            do{
                scanf("%c",&c);
            }while(c != '\n');
            printf("Commands: 0=clear, 1=credit, 2=debit, ");
            printf("3=balance, 4=exist\n");
        }
    }

    return 0;
}