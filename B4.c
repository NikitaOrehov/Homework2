#include <stdio.h>

int main(){
    double a, b, c;
    printf("Enter a, b, c\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a == b && a == c && b == c) printf("Ravnoctoronniy triangle");
    else 
        if (a == b || a == c || b == c) 
            printf("Ravnobedrennyi");
        else printf("Raznoctoronnyi");
    return 0;
}