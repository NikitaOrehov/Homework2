#include <stdio.h>

int main(){
    FILE* p_file = fopen("test.txt", "w");
    fputs("ghgfjfjgfjfj", p_file);
    fclose(p_file);
}