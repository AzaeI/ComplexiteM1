#include "../header/algo2.h"
#include "../header/util.h"

Result aglo2(int t[], int debut, int fin){
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

