#include <stdio.h>

int main(){
    int a, b, c, d;
    printf("Enter a, b, c, d\n");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a == b){
        if (b == c) printf("4");
        else printf("3");
    }
    else if (a == c) printf("2");
    else printf("1");
    return 0;
}