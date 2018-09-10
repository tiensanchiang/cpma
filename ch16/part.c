#include<stdio.h>
#include<string.h>
#include "part.h"

int part_len = 0;
struct part inventory[MAX_PARTS];

void s_gets(char * str,int len){
    int count = 0,ch;

    while( (ch = getchar()) != '\n'){
        if(count < len)
            str[count++] = ch;
    }

    str[count] = '\0';
}

struct part * find_part(int part_num){
    for(int i=0;i<part_len;i++){
        if(inventory[i].num == part_num){
            return &inventory[i];
        }
    }

    return 0;
}

void read_part(struct part * p){

    char name[MAX_NAME_LEN + 1];

    printf("Enter part name:");
    s_gets(name,MAX_NAME_LEN);
    strncpy(p->name,name,MAX_NAME_LEN);

    printf("Enter part number:");
    scanf("%d",&p->num);

    printf("Enter part quantity:");
    scanf("%lf",&p->quantity);

}

int read_part_num(void){
    int part_num;
    printf("Enter part number:");
    scanf("%d",&part_num);
    return part_num;
}

double read_part_quantity(void){
    double part_quantity;
    printf("Enter part quantity:");
    scanf("%lf",&part_quantity);
    return part_quantity;
}

void add_part(struct part p){
    if(part_len==MAX_PARTS){
        printf("The inventories already full.\n");
        return;
    }

    if(find_part(p.num)){
        printf("The part #%d already exists in inventory.\n",p.num);
        return;
    }

    inventory[part_len++] = p;
}

void update_quantity(int part_num, double quantity){

    struct part * p  = find_part(part_num);
    if(p){
        p->quantity = quantity;
    }else{
        printf("The part #%d does not exist.\n",part_num);
    }
}

void print_parts(){
    for(int i=0;i<part_len;i++){
        printf("Part #%d: name:%s, quantity:%lf\n",inventory[i].num,inventory[i].name,inventory[i].quantity);
    }
}