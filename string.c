#include <string.h>
#include <stdio.h>
#include <stdlib.h>


struct date{
    int day;
    int month;
    int year;
};

struct person{
    char* name;
    char* surname;
    int gender;
    char* phonenumber;
    struct date borndate;
};

int main(){
    char a[10];
    char b[10];
    scanf("%s", a);
    struct person* Nikita = malloc(sizeof(struct person));
    Nikita->name = malloc(20);
    strcpy(Nikita->name, a);
    printf("%s\n", Nikita->name);
    Nikita->surname = malloc(20);
    scanf("%s", a);
    strcpy(Nikita->surname, a);
    printf("%s %s", Nikita->name, Nikita->surname);
    if (strcmp(Nikita->surname, a) == 0) printf("\n111");
}