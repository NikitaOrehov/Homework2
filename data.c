#include <stdio.h>
#include <string.h>
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

void printPersonInfo(struct person** p, int number){
    printf("Name: %s;\nsurname: %s\ngender: %d\nphonenumber: %s;\ndate: %d.%d.%d;", p[number - 1]->name, p[number - 1]->surname, p[number - 1]->gender, p[number - 1]->phonenumber, p[number - 1]->borndate.day, p[number - 1]->borndate.month, p[number - 1]->borndate.year);
}


int main(){
    struct person** library = malloc(sizeof(struct person*) * 20);
    int flag = 0, number = 0, count = 0;
    while (flag == 0){
        printf("Delete = 1;\nEnter = 2;\nLook = 3;\nEnd = 4\n");
        scanf("%d", &number);
        if (number == 1){
            printf("Who ");
            scanf("%d", &number);
            library[number -1] = NULL;
            continue;
        }
        if (number == 2){
            struct person* human = malloc(sizeof(struct person));
            printf("enter name:\n");
            scanf("%s", human->name);
            printf("enter surname:\n");
            scanf("%s", human->surname);
            printf("enter gender:\n");
            scanf("%d", &human->gender);
            printf("enter phonenumber:\n");
            scanf("%s", human->phonenumber);
            printf("enter date: ");
            scanf("%d %d %d\n", &human->borndate.day, &human->borndate.month, &human->borndate.year);
            library[count] = human;
            count++;
            continue;
        }
        if (number == 3){
            printf("Who ");
            scanf("%d", &number);
            printPersonInfo(library, number);
        }
        if (number == 4){
            break;
        }
    }
}