#include <stdio.h>
#include <stdlib.h>

struct Student
{
  char name[255];
  float final_grade;
};

float get_random_grade()
{
  float grades[] = {2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0};
  int rand_n = rand() % 7;
  return grades[rand_n];
}

void sort_students_by_grade(struct Student *students, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - 1; j++)
    {
      if (students[j].final_grade < students[j + 1].final_grade)
      {
        struct Student temp = students[j];
        students[j] = students[j + 1];
        students[j + 1] = temp;
      }
    }
  }
}

void print_students(struct Student *students, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("Student %d: %s, ocena końcowa: %f\n", i + 1, students[i].name, students[i].final_grade);
  }
}

int main()
{
  // define array of 5 students
  // struct Student students[] = {{"Jan Kowalski", 4.5}, {"Anna Nowak", 3.5}, {"Piotr Wiśniewski", 5.0}, {"Maria Kowalczyk", 4.0}, {"Adam Malinowski", 3.0}};

  // define array of 100 different unique students with grades between 2.0 and 5.0
  struct Student students[100];

  for (int i = 0; i < 100; i++)
  {
    sprintf(students[i].name, "Student %d", i + 1);
    students[i].final_grade = get_random_grade();
  }

  int students_len = sizeof(students) / sizeof(students[0]);

  printf("Studenci przed posortowaniem:\n");
  print_students(students, students_len);

  sort_students_by_grade(students, students_len);

  printf("\nPosortowani studenci:\n");
  print_students(students, students_len);

  return 0;
}
