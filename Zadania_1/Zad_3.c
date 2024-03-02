#include <stdio.h>

// Oblicz silnie gdzie parametrem wejściowym jest tablica int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}.
// Ma być to funkcja która przyjmuje tablice a następnie liczy silnie dla każdej liczby w tej tablicy.

int factorial(int n)
{
  if (n == 0)
  {
    return 1;
  }
  else
  {
    return n * factorial(n - 1);
  }
}

int main()
{
  int array[] = {1,
                 2,
                 3,
                 4,
                 5,
                 6,
                 7,
                 8,
                 9,
                 10};

  for (int i = 0; i < 10; i++)
  {
    printf("Silnia z %d to %d \n", array[i], factorial(array[i]));
  }

  return 0;
}