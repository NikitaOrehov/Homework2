#include <stdio.h>

int main() {
    int matrix[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    int rows = sizeof(matrix) / sizeof(matrix[0]);
    int cols = sizeof(matrix[0]) / sizeof(int);

    int startRow, startCol, endRow, endCol;
    int loopCount = 0;

    int i, j;

    // Находим начальные координаты нити
    for (i = 0; i < rows; i++) {
        if (matrix[i][0] == 1) {
            startRow = i;
            startCol = 0;
            break;
        }
    }

    // Проходим по нити и находим петли
    i = startRow;
    j = startCol;
    while (1) {
        // Проверка на петлю
        printf("row = %d col = %d\n", i, j);
        if (matrix[i][j] != 1) {
            loopCount++;
            endRow = i;
            endCol = j;
            break;
        }

        // Переход к следующей ячейке нити по правилам задачи
        if (j + 1 < cols && matrix[i][j + 1] == 1) {
            j++;
        } else if (i + 1 < rows && matrix[i + 1][j] == 1) {
            i++;
        } else if (j - 1 >= 0 && matrix[i][j - 1] == 1) {
            j--;
        } else {
            break;
        }
    }

    printf("Количество петель: %d\n", loopCount);
    printf("Строка начала нити: %d\n", startRow);
    printf("Столбец начала нити: %d\n", startCol);
    printf("Строка конца нити: %d\n", endRow);
    printf("Столбец конца нити: %d\n", endCol);

    return 0;
}
