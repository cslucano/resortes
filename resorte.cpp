#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <list>
#include "vector.h"

using namespace std;

class Resorte;

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

Junta::Junta(Vector* vector, bool isMovil)
{
  this->vector = vector;
  this->isMovil = isMovil;
  this->lstResortes = new list<Resorte*>();
}

JuntaFija::JuntaFija(Vector* vector) : Junta(vector, false)
{
}

JuntaMovil::JuntaMovil(Vector* vector, double masa) : Junta(vector, true)
{
  this->masa = masa;
  this->velocidad = new Vector(0,0);
  this->aceleracion = new Vector(0,0);
}

class Resorte
{
   private:
     Junta * juntaA;
     Junta * juntaB;
     double k;
   public:
     Resorte(Junta* juntaA, Junta* juntaB, double k);
     Vector* getFuerzaEn(Junta* junta);
};

Resorte::Resorte(Junta* juntaA, Junta* juntaB, double k)
{
  this->juntaA = juntaA;
  this->juntaB = juntaB;
  this->k = k;

  juntaA->addResorte(this);
  juntaB->addResorte(this);

}

Vector* Resorte::getFuerzaEn(Junta* junta)
{
  Vector* vector;
  Vector* vector0;

  if(junta == this->juntaA)
  {
     vector = this->juntaB->getVector();
     vector0 = this->juntaA->getVector();
  } else {
     vector = this->juntaA->getVector();
     vector0 = this->juntaB->getVector();
  }

  double dx = vector->getX() - vector0->getX();
  double dy = vector->getY() - vector0->getY();
  double d = sqrt(pow(dx,2) + pow(dy,2));
  
  return new Vector(this->k * dx / d, this->k * dy / d);
}

Vector* Junta::getFuerza() {
   Vector* fuerza = new Vector(0, 0);
   for(list<Resorte*>::iterator it = this->lstResortes->begin(); it != this->lstResortes->end(); it++)
   { 
     Resorte* resorte = *it;
     
     fuerza = Vector::suma(fuerza, resorte->getFuerzaEn(this));
   }

   return fuerza;
}

void Junta::printFuerza() {
   Vector* fuerza = this->getFuerza(); 
   printf("(%.4g, %.4g)\n", fuerza->getX(), fuerza->getY());
}


void JuntaFija::simular(double delta)
{
}

void JuntaMovil::simular(double delta)
{
  Vector * fuerza = this->getFuerza();

  this->aceleracion = new Vector(fuerza->getX()/this->masa, fuerza->getY()/this->masa);
  Vector* d_velocidad = new Vector(this->aceleracion->getX() * delta, this->aceleracion->getY() * delta);
  this->velocidad = Vector::suma(this->velocidad, d_velocidad);

  Vector* d_vector = new Vector(this->velocidad->getX() * delta, this->velocidad->getY() * delta);
  this->vector = Vector::suma(this->vector, d_vector);  
}



int main()
{
  Junta* junta1;
  Junta* junta2;
  Junta* junta3;
  Resorte* resorte1;
  Resorte* resorte2;

  junta1 = new JuntaFija(new Vector(0,0));
  junta2 = new JuntaFija(new Vector(5,0));
  junta3 = new JuntaMovil(new Vector(1.5,2.5),200);

  resorte1 = new Resorte(junta1, junta3, 10);
  resorte2 = new Resorte(junta3, junta2, 10);
  
  //junta1->printFuerza();
  //junta2->printFuerza();
  //junta3->printFuerza();
  //printf("\n\nmoviendo junta3");

  junta3->printVector();
  for (int i = 0; i < 1000; i++) {
    junta3->simular(0.4);
    junta3->printVector();
  }

  return 0;
}
