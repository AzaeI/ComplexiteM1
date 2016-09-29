#include "../header/util.h"
#include "../header/algo2.h"

Result aglo2Bis(int* t, int debut, int fin){
    int max = t[0],
    indiceD = debut,
    indiceF = debut,
    indiceCourrantD = debut,
    indiceCourrantF = debut;

    while (indiceCourrantD < fin ){
        int tmp = 0;
        while (indiceCourrantF < fin){
           int maxTmp = tmp + t[indiceCourrantF];
           if (maxTmp > max){
              max = maxTmp;
              indiceD = indiceCourrantD;
              indiceF = indiceCourrantF;
          }
          tmp = maxTmp;
          indiceCourrantF++;
      }

      indiceCourrantF = indiceCourrantD +1;
      indiceCourrantD++;
  }
  Result resultat; 
  resultat.debut = indiceD;
  resultat.fin = indiceF;
  resultat.max = max;
  return resultat;
}

Result algo2 (int* t, int size){
  Result r;
  r = aglo2Bis(t,0,size);
  return r;
}
