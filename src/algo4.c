#include "../header/algo4.h"
#include "../header/util.h"

Result sommeMaxFin(int indice,int t[]){
    Result sommeMax;
    sommeMax.max = t[indice];
    sommeMax.debut = indice;
    sommeMax.fin = indice;
    int maxTmp = t[indice];
    for (int i = indice -1; i > 0; --i)
    {
        maxTmp += t[i];  
        if(sommeMax.max < maxTmp){
            sommeMax.max = maxTmp;
            sommeMax.debut = i;
        }
    }
    return sommeMax;
}

Result aglo4(int t[],int n){
    int i = 1;
    Result result;
    result.max = t[0];
    result.debut = 0;
    result.fin = 0;
    Result resultatMaxTmp;
    while(i < n){
        resultatMaxTmp = sommeMaxFin(i,t);
         if(resultatMaxTmp.max > result.max){
            result.max = resultatMaxTmp.max;
            result.debut = resultatMaxTmp.debut;
            result.fin = resultatMaxTmp.fin;
        }
        ++i;
    }
    return result;
}