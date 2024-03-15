#include <stdio.h>

struct Point
{
  float x;
  float y;
};

struct Rectangle
{
  struct Point a;
  struct Point b;
  struct Point c;
  struct Point d;
};

void modify_point(struct Point *p, float x, float y)
{
  p->x = x;
  p->y = y;
}

void calculate_from_rectangle(struct Rectangle *r)
{
  float width = r->b.x - r->a.x;
  float height = r->d.y - r->b.y;
  float area = width * height;
  float perimeter = 2 * (width + height);

  printf("Szerokość: %f\n", width);
  printf("Wysokość: %f\n", height);
  printf("Pole: %f\n", area);
  printf("Obwód: %f\n", perimeter);
}

int main()
{

  struct Point p = {1, 2};

  printf("Wartość zmiennej p: (%f, %f)\n", p.x, p.y);
  modify_point(&p, 3, 4);
  printf("Wartość zmiennej p po modyfikacji: (%f, %f)\n", p.x, p.y);

  struct Rectangle r = {{0, 0}, {2, 0}, {2, 2}, {0, 2}};
  calculate_from_rectangle(&r);

  return 0;
}
