#include <stdio.h>

// Musisz wypisać liczby od 1 do 200 w nowej linii.
// Ale dla każdej wielokrotności 5 wypisuje "Foo", dla każdej wielokrotności 7 wypisuje "Bar" i dla każdej wielokrotności zarówno 5 jak i 7 wypisuje "FooBar" zamiast liczby.

int main()
{
  printf("Hello, World!\n");

  for (int i = 1; i <= 200; i++)
  {
    if (i % 5 == 0 && i % 7 == 0)
    {
      printf("FooBar\n");
    }
    else if (i % 5 == 0)
    {
      printf("Foo\n");
    }
    else if (i % 7 == 0)
    {
      printf("Bar\n");
    }
    else
    {
      printf("%d\n", i);
    }
  }

  return 0;
}
