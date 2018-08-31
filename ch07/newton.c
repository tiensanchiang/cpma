#include<stdio.h>
#include<math.h>

int main(void){
    int x;
    double y = 1.0,ny;

    printf("Enter a positive number:");
    scanf("%d",&x);

    for(;;){
        ny = (y + x/y)/2;
        if(fabs(ny-y) < 0.00001)
            break;
        y = ny;
    }

    printf("Squery root: %.5f",ny);

    return 0;
}