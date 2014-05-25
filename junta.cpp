#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <list>
#include "vector.h"
#include "resorte.h"
#include "junta.h"

using namespace std;

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
