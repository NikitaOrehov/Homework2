#include <stdio.h>

int main(){
    double x, y, z;
    printf("Enter x, y, z\n");
    scanf("%lf %lf %lf", &x, &y, &z);
    if (x < y){
        if (y < z) printf("%.2lf %.2lf %.2lf", x, y, z);
        else if (x < z) printf("%.2lf %.2lf %.2lf", x, z, y);
        else printf("%.2lf %.2lf %.2lf", z, x, y);
    }
    else if (y > z) printf("%.2lf %.2lf %.2lf", z, y, x);
        else if (x > z) printf("%.2lf %.2lf %.2lf", y, z, x);
        else printf("%.2lf %.2lf %.2lf", y, x, z);
    return 0;
}