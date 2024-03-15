#include <stdio.h> // Dołączamy bibliotek stdio pozwalająca na użycie funkcji printf

int main()
{
  int z = 0;
  int *p_z = &z;
  printf("Wartość zmiennej z: %d\n", z);
  printf("Wartość zmiennej z przez wskaźnik: %d\n", *p_z);
  *p_z += 1;
  printf("Wartość zmienniej z po inkrementacji: %d\n", z);
  printf("Wartość zmienniej z po inkrementacji przez wskaźnik: %d\n", *p_z);
  return 0;
}
