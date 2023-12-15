#include <stdio.h>

int main(){
    FILE* p_file = fopen("test.txt", "w");
    for (int i = 0; i < 10; i++){
        fputs("1 ", p_file);
    }
    fclose(p_file);
}