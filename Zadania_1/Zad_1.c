#include <stdio.h> // Dołączamy bibliotek stdio pozwalająca na użycie funkcji printf

// Przygotuj program w którym zamiast wypisywania do konsoli “Hello, World”.
// Użytkownik będzie mógł wpisać swoje imię.
// Możesz do tegu użyć funkcji scanf, będzie trzeba tam przekazać wskaźnik do zmiennej.

int main()
{
  char name[255];
  printf("Podaj swoje imię: \n");
  scanf("%s", name);
  printf("Cześć, %s", name);
  return 0;
}
