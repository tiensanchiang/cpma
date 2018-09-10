#ifndef PART_H
#define PART_H

#define MAX_PARTS 10
#define MAX_NAME_LEN 20

struct part{
    char name[MAX_NAME_LEN];
    int num;
    double quantity;
};

void read_part(struct part * p);

int read_part_num(void);

double read_part_quantity(void);

void add_part(struct part p);

void update_quantity(int part_num, double quantity);

void print_parts();

#endif