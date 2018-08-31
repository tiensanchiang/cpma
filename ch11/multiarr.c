#include<stdio.h>

int main(void){
    int a[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    printf("a=%p, sizeof(a)=%ld, a+1=%p\n",a,sizeof(a),a+1);
    printf("a[0]=%p, sizeof(a[0])=%ld, a[0]+1=%p\n",a[0],sizeof(a[0]),a[0] + 1);
    printf("&a[0]=%p, sizeof(&a[0])=%ld, &a[0]+1=%p\n",&a[0],sizeof(&a[0]), &a[0] +1);

    return 0;
}