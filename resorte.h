#ifndef RESORTE_H
#define RESORTE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <list>
#include "vector.h"
#include "junta.h"

using namespace std;

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
#endif // RESORTE_H
