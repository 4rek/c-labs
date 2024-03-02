#include <stdio.h>

// Znajdź średnią ocen grupy pięciu uczniów z dwóch przedmiotów, matematyki i fizyki.
// Aby to zrobić, użyjemy dwuwymiarowej tablicy o nazwie grades.
// Oceny odpowiadające matematyce będą przechowywane w pierwszym wierszu(grades[0]), natomiast oceny odpowiadające fizyce będą przechowywane w drugim wierszu(grades[1]).

int main()
{
  int grades[][5] = {{4, 4, 3, 5, 5}, {3, 4, 4, 5, 5}};
  float math_avg = 0.0;
  float physics_avg = 0.0;

  for (int i = 0; i < 5; i++)
  {
    math_avg += grades[0][i];
    physics_avg += grades[1][i];
  }

  math_avg /= 5;
  physics_avg /= 5;

  printf("Średnia z matematyki: %.2f\n", math_avg);
  printf("Średnia z fizyki: %.2f\n", physics_avg);

  return 0;
}
