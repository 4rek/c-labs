#include <stdio.h>
#include <stdlib.h>


int factorial(int n) {
  if (n == 0) {
    return 1;
  }
  return n * factorial(n - 1);
}

int main()
{
  printf("Podaj liczbę do wyliczenia silni: \n");
  int input;
  scanf("%d", &input);
  printf("Silnia z %d to %d\n", input, factorial(input));
}
