#include<stdio.h>
#include<stdlib.h>
#include "readline.h"

#define NAME_LEN 20

struct part{
    int part_num;
    double quantity;
    char name[NAME_LEN+1];
    struct part * next;
};

void insert_part(struct part ** inventory);
void search_part(struct part * inventory);
void print_inventory(struct part * inventory);
void update_part(struct part * inventory);
void delete_part(struct part ** inventory);

int main(void){
    char code;
    struct part * inventory = NULL;

    for(;;){
        printf("Enter operation code:");
        scanf(" %c", &code);

        switch(code){
            case 'i': insert_part(&inventory);break;
            case 'u': update_part(inventory);break;
            case 's': search_part(inventory);break;
            case 'p': print_inventory(inventory);break;
            case 'd': delete_part(&inventory);break;
            case 'q': return 0;
            default: printf("Illegal code\n");
        }
        printf("\n");
    }
    return 0;
}

struct part * find_part(struct part * inventory, int part_num){
    struct part *p;
    p = inventory;

    for(p = inventory; p!=NULL; p=p->next){
        if(p->part_num == part_num)
            return p;
    }

    return NULL;
}

void insert_part( struct part ** inventory ){
    struct part * p, *cur, *prev;
    p = malloc(sizeof(struct part));
    if(p == NULL){
        printf("Database already full.");
        return;
    }

    printf("Enter part number:");
    scanf("%d", &p->part_num);

    for(cur = *inventory,prev=NULL; 
        cur!=NULL && cur->part_num < p->part_num;
        prev=cur,cur=cur->next)
        ;
    
    if(cur != NULL && cur->part_num == p->part_num){
        printf("Part #%d already exist.",p->part_num);
        return;
    }

    printf("Enter part quantity:");
    scanf("%lf", &p->quantity);

    printf("Enter part name:");
    read_line(p->name,NAME_LEN);

    p->next = cur;
    if(prev != NULL){
        prev->next  = p;
    }else{
        *inventory = p;
    }
}

void search_part( struct part * inventory){
    int part_num;
    const struct part * p;
    printf("Enter part number:");
    scanf("%d",&part_num);

    p = find_part(inventory,part_num);
    if(p == NULL){
        printf("Part #%d not found.\n",part_num);
    }else{
        printf("Part name:%s, Quantity on hand:%lf\n",p->name,p->quantity);
    }
}

void print_inventory(struct part * inventory){
    const struct part * p;

    printf("Part Num    Part Name           Quantity on hand\n");

    for(p = inventory; p != NULL; p = p->next){
        printf("%7d     %-25s%11lf\n",p->part_num,p->name,p->quantity);
    }
}

void update_part(struct part * inventory){
    int part_num;    
    struct part* p;

    printf("Enter part number:");
    scanf("%d",&part_num);

    p = find_part(inventory,part_num);
    if(p == NULL){
        printf("Part #%d does not exist.", part_num);
        return;
    }

    printf("Enter part quantity on hands:");
    scanf("%lf",&p->quantity);
}

void delete_part(struct part ** inventory){
    int part_num;
    struct part * cur, *prev;

    printf("Enter part number:");
    scanf("%d",&part_num);

    for(cur = *inventory,prev=NULL; 
        cur!=NULL && cur->part_num != part_num;
        prev=cur,cur=cur->next)
        ;

    if(cur == NULL){
        printf("Part #%d not found.\n",part_num);
    }else if(prev == NULL){
        *inventory = (*inventory)->next;
    }else{
        prev->next = cur->next;
        free(cur);
    }
}