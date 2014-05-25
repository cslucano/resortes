#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <list>
#include "vector.h"
#include "junta.h"
#include "resorte.h"

using namespace std;

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
