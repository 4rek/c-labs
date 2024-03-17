#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
  if (n == 0) {
    return 1;
  }
  return n * factorial(n - 1);
}

int calculate(int row, int col) {
  return factorial(row) / (factorial(col) * factorial(row - col));
}

int main()
{
  printf("Podaj rozmiar trojkąta: \n");
  int input;
  scanf("%d", &input);

  int ** triangle = malloc(input * sizeof(int *));

  for (int i = 0; i < input; i++) {
    triangle[i] = malloc((i + 1) * sizeof(int));
  }

  for (int i = 0; i < input; i++) {
    for (int j = 0; j <= i; j++) {
      triangle[i][j] = calculate(i, j);
    }
  }

  printf("##############\n");

  for (int i = 0; i < input; i++) {
    for (int j = 0; j <= i; j++) {
      printf("%d ", triangle[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < input; i++) {
      free(triangle[i]);
  }
  free(triangle);

  return 0;
}
