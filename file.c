#include <stdio.h>
#include <stdlib.h>

// void create_array(double* array, int size){
//     for (int i = 0; i < size; i++){
//         array[i] = (double)rand() / 1000;
//     }
// }

// void file(FILE* p_f, double* array, int size){
//     fprintf(p_f, "%d\n", size);
//     for (int i = 0; i < size; i++){
//         fprintf(p_f, "%lf\n", array[i]);
//     }
// }

// int file2(FILE* p_f, double* array, int size){
//     fscanf(p_f, "%d\n", &size);
//     array = malloc(sizeof(double) * size);
//     for (int i = 0; i < size; i++){
//         fscanf(p_f, "%lf\n", &array[i]);
//     }
//     fclose(p_f);
//     return size;
// }

// int main(){
//     FILE* p_f = fopen("file.txt", "w");
//     int size;
//     scanf("%d", &size);
//     double* p_array = malloc(sizeof(double) * size);
//     create_array(p_array, size);
//     file(p_f, p_array, size);
//     free(p_array);
//     free(p_f);
//     p_f = fopen("file.txt", "r");
//     double* p_new_array;
//     size = file2(p_f, p_new_array, size);
//     printf("%d\n", size);
//     for (int i = 0; i < size; i++){
//         printf("%lf ", p_new_array[i]);
//     }
// }
