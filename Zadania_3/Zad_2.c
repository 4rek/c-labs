#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows;
    int cols;

    printf("Podaj ilosc wierszy tablicy: \n");
    scanf("%d", &rows);
    printf("Podaj ilosc kolumn tablicy: \n");
    scanf("%d", &cols);

    int ** matrix = malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value = i * j;
            matrix[i][j] = value;
            printf("%d ", value);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
