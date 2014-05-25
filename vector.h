#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
  private:
    double x;
    double y;
  public:
    Vector(double x, double y);
    double getX() { return this->x; }
    double getY() { return this->y; }
    static Vector* suma(Vector* vector1, Vector* vector2);
};
#endif // VECTOR_H
