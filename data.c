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
    printf("\nName: %s;\nsurname: %s\ngender: %d\nphonenumber: %s;\ndate: %d.%d.%d;\n\n", p[number]->name, p[number]->surname, p[number]->gender, p[number]->phonenumber, p[number]->borndate.day, p[number]->borndate.month, p[number]->borndate.year);
}

void delete(struct person** library, int number, int count){
    char name[10], surname[10];
    number = -1;
    printf("name: ");
    scanf("%s", name);
    printf("\nsurname: ");
    scanf("%s", surname);
    for (int i = 0; i < count; i++){
        if (strcmp(library[i]->name, name) == 0 && strcmp(library[i]->surname, surname) == 0){
            number = i;
            break;
        }
    }
    if (number == -1){
        printf("No find person\n");
        return;
    }
    free(library[number]->name);
    free(library[number]->surname);
    free(library[number]->phonenumber);
    library[number] = NULL;
    printf("person delete\n");
    return;
}

void addendum(struct person** library, int* count){
    struct person* human = malloc(sizeof(struct person));
    printf("enter name:\n");
    human->name = malloc(100);
    scanf("%s", human->name);
    printf("enter surname:\n");
    human->surname = malloc(100);
    scanf("%s", human->surname);
    printf("enter gender:\n");
    scanf("%d", &human->gender);
    printf("enter phonenumber:\n");
    human->phonenumber = malloc(100);
    scanf("%s", human->phonenumber);
    printf("enter date: ");
    scanf("%d %d %d", &human->borndate.day, &human->borndate.month, &human->borndate.year);
    library[*count] = human;
    *count += 1;
    return;
}

void watch(struct person** library, int number, int count){
    char name[10], surname[10];
    number = -1;
    printf("name: ");
    scanf("%s", name);
    printf("\nsurname: ");
    scanf("%s", surname);
    for (int i = 0; i < count; i++){
        if (library[i] == NULL) continue;
        if (strcmp(library[i]->name, name) == 0 && strcmp(library[i]->surname, surname) == 0){
            number = i;
            break;
        }
    }
    if (number == -1){
        printf("No find person\n");
        return;
    }
    printPersonInfo(library, number);    
}

void swap(struct person** library, int first, int second){
    struct person* p = malloc(sizeof(struct person));//нужен ли free(p)
    p = library[second];
    library[second] = library[first];
    library[first] = p;
}

void sort(struct person** library, int count){
    for (int i = 0; i < count - 1; i++){
        for (int j = count - 1; j > i; j--){
            if (library[j]->borndate.year < library[j - 1]->borndate.year){
                swap(library, j - 1, j);
            }
            else if ((library[j]->borndate.year == library[j - 1]->borndate.year) && (library[j]->borndate.month < library[j - 1]->borndate.month)){
                swap(library, j - 1, j);
            }
            else if ((library[j]->borndate.year == library[j - 1]->borndate.year) && (library[j]->borndate.month == library[j - 1]->borndate.month) && (library[j]->borndate.day < library[j - 1]->borndate.day)){
                swap(library, j - 1, j);
            }
        }
    }
    printf("sort complite\n");
}

void write_file(FILE* p_file, struct person** library, int count){
    for (int i = 0; i < count; i++){
        if (library[i] == NULL) continue;
        fputs("name: ", p_file);
        fprintf(p_file, "%s\n", library[i]->name);
        fputs("surname: ", p_file);
        fprintf(p_file, "%s\n", library[i]->surname);
        fputs("gender: ", p_file);
        fprintf(p_file, "%d\n", library[i]->gender);
        fputs("phonenumber: ", p_file);
        fprintf(p_file, "%s\n", library[i]->phonenumber);
        fputs("birthday: ", p_file);
        fprintf(p_file, "%d.", library[i]->borndate.day);
        fprintf(p_file, "%d.", library[i]->borndate.month);
        fprintf(p_file, "%d", library[i]->borndate.year);
        fputs("\n\n\n", p_file);
    }
}

int main(){
    struct person** library = malloc(sizeof(struct person*) * 20);
    int flag = 0, number = 0, count = 0;
    while (flag == 0){
        printf("\n");
        printf("Delete = 1;\nEnter = 2;\nLook = 3;\nEnd = 4;\nSort = 5;\n");
        scanf("%d", &number);
        if (number == 1){
            delete(library, number, count);
        }
        if (number == 2){
            addendum(library, &count);
        }
        if (number == 3){
            watch(library, number, count);
        }
        if (number == 4){
            printf("\n\nexit program\n");
            break;
        }
        if (number == 5){
            sort(library, count);
        }
        if (number > 5) break;
    }
    FILE* p_file = fopen("data.txt", "w");
    write_file(p_file, library, count);
    fclose(p_file);
    return 0;
}