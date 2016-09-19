#include "../header/touteSousSequence.h"

Result touteSousSequence(int t[], int n){
    int max = t[0],
    indiceD = 0,
    indiceF = 0,
    indiceCourrantD = 0,
    indiceCourrantF = 0;

    while (indiceCourrantD < n ){
        while (indiceCourrantF < n){
            int maxTmp = 0;
            for (int i = indiceCourrantD; i < indiceCourrantF +1; ++i) {
                maxTmp += t[i];
            }
            // printf(" max tmp = %d\n", maxTmp);
            if (maxTmp > max){
                max = maxTmp;
                indiceD = indiceCourrantD;
                indiceF = indiceCourrantF;
            }
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