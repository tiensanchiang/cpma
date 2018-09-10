#include<stdio.h>
#include "part.h"
#include "menu.h"

int main(void){

    print_menu();

    int choice;
    while( (choice = get_choice()) != 'q'){
        struct part p;
        int num;
        double quantity;
        switch(choice){
            case 'i':
                read_part(&p);
                add_part(p);
                break;
            case 'u':
                num = read_part_num();
                quantity = read_part_quantity();
                update_quantity(num,quantity);
                break;
            case 's':
                break;
            case 'p':
                print_parts();
                break;
        }
        print_menu();
    }
}