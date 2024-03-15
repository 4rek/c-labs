#include <stdio.h>

void increase(float *p_z)
{
  *p_z *= 2;
}

int main()
{
  float z = 15;
  printf("Wartość zmiennej z: %f\n", z);
  increase(&z);
  printf("Wartość zmiennej z po inkrementacji: %f\n", z);
  return 0;
}
