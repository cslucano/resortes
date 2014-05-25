#include "vector.h"

using namespace std;

Vector::Vector(double x, double y)
{
  this->x = x;
  this->y = y;
}

Vector* Vector::suma(Vector* vector1, Vector* vector2) {
  double x = vector1->x + vector2->x;
  double y = vector1->y + vector2->y;

  return new Vector(x, y);
}
