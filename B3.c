#include <stdio.h>

int main(){
    int x, y;
    printf("Enter x, y\n");
    scanf("%d %d", &x, &y);
    if (x == 0 && y == 0) printf("Origin coordinates");
    else if (x == 0) printf("ordinate");
    else if (y == 0) printf("abscissa");
    else if (x > 0){
        if (y > 0) printf("1");
        else printf("4");
    }
    else if (y > 0) printf("2");
        else printf("3");
    return 0;
}