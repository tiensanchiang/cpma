#include<stdio.h>

union float_union{
    float f;
    struct{
        unsigned int sign: 1;
        unsigned int exp: 8;
        unsigned int frac: 23;
    } s;
};

union int_date{
    unsigned short i;
    struct{
        unsigned int day: 5;
        unsigned int month: 4;
        unsigned int year: 7;
    } d;
};

int main(void){
    union float_union fu;

    fu.s.sign = 0;
    fu.s.exp = 0;
    fu.s.frac = 0xc0;

    float fl = -2.0;
    unsigned char * ptr = (unsigned char*)&fl;
    for(int i=0;i<4;i++,ptr++)
        printf("%.2x ",*ptr);
    printf("\n");

    ptr = (unsigned char*)&fu;
    for(int i=0;i<4;i++,ptr++)
        printf("%.2x ",*ptr);
    printf("\n");


    printf("%ld\n",sizeof(float));
    printf("%f\n",fu.f);

    union int_date id;
    id.d.day = 31;
    id.d.month = 15;
    id.d.year = 127;

    printf("%d",id.i);
    return 0;
}