#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <list>
#include "junta.h"

using namespace std;

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
