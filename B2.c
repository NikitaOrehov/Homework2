#include <stdio.h>
#include <math.h>

int main(){
    int x1, x2, y1, y2, r1, r2;
    double length;
    printf("Enter x1, y1, r1, x2, y2, r2;       r1 > r2\n");
    scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
    length = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    if (length == r1 + r2) printf("Odna tochka");
    else if (length > r1 + r2 || length < r1 - r2) printf("Net obshih tochek");
    else if (r1 - r2 < length < r1 + r2) printf("Dve tochki");
    else printf("Odinakovi");
    return 0;
}