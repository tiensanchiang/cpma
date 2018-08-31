#include<stdio.h>

void output(void);
void input(void);

int main(void){
    output();
    input();
}

void output(){
    printf("%12.5e\n",30.253);
}

void input(void){
    float x;
    int i,y;

    scanf("%d%f%d",&i,&x,&y);
    printf("x=%f, i=%d, y=%d",x,i,y);

}


