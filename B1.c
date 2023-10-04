#include <stdio.h>

int main(){
    int a, b, c;
    printf("Enter a, b, c\n");
    scanf("%d %d %d", &a, &b, &c);
    if (a + b + c == 15) printf("Otlichnik");
    else if (a == 2 || b == 2 || c == 2) printf("Dvoechnik");
    else if (a == 3 || b == 3 || c == 3) printf("Troechnik");
    else printf("Horoshist");
    return 0;
}