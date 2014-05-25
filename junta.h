#ifndef JUNTA_H
#define JUNTA_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <list>
#include "vector.h"
#include "resorte.h"

using namespace std;

class Junta 
{
  protected:
    Vector * vector;
    bool isMovil;
    list<Resorte*>* lstResortes;
  public:
    Junta(Vector* vector, bool isMovil);
    void addResorte(Resorte* resorte)
    {
      this->lstResortes->push_back(resorte);
    }
    void printFuerza();
    void printVector() { printf("(%.4g, %.4g)\n", this->vector->getX(), this->vector->getY()); }
    Vector* getFuerza();
    Vector* getVector() { return this->vector; }
    virtual void simular(double delta) {};
    
};

class JuntaMovil : public Junta
{
  private:
    double masa;
    Vector* velocidad;
    Vector* aceleracion;
  public:
    JuntaMovil(Vector* vector, double masa);
    void simular(double delta);
    
};

class JuntaFija : public Junta
{
  public:
    JuntaFija(Vector* vector);
    void simular(double delta);
};
#endif // JUNTA_H
