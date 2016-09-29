#include "../header/util.h"
#include "../header/algo4.h"

Result algo4(int* t, int n)
{
    Result resultat;
    resultat.max = t[0];
    resultat.debut = 0;
    resultat.fin = 0;
    int somme = 0;
    int debutTmp = 0;
    for (int i = 0; i < n; ++i)
    {
        if (somme < 0){
          somme = 0;
          debutTmp = i;
        }
        somme += t[i];
        if(resultat.max < somme){
            resultat.max = somme;
            resultat.debut = debutTmp;
            resultat.fin = i;
        }
    }
    return resultat;
}

