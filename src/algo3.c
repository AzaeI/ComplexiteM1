#include "../header/util.h"
#include "../header/algo3.h"

Result collerGauche(Result resultat1,Result resultat2,int debutSeq2,int tab[]){
    int i = 0;
    Result resultatMilieu;
    resultatMilieu.max = tab[debutSeq2]+ resultat1.max;
        // printf("---%d\n---",resultat1.debut);
    resultatMilieu.debut = resultat1.debut;
    resultatMilieu.fin = debutSeq2; 
    int resultMaxTemp =  resultatMilieu.max;
        //si le milieu est améliore par la  sous séquence a droite  
    i = debutSeq2 +1;
    resultMaxTemp = resultatMilieu.max;
    while(i <= resultat2.fin ){
        resultMaxTemp += tab[i];
        if(resultMaxTemp > resultatMilieu.max){
            resultatMilieu.max = resultMaxTemp;
            resultatMilieu.fin = i;
        }
        ++i;
    }
    return resultatMilieu;
}


Result collerDroite(Result resultat2,Result resultat1,int finSeq1,int tab[]){
    int i = 0;
    Result resultatMilieu;
    resultatMilieu.max = tab[finSeq1] + resultat2.max;
    resultatMilieu.debut = finSeq1 -1;
    resultatMilieu.fin = resultat2.fin; 
    int resultMaxTemp =  resultatMilieu.max;
    //si le milieu est améliore par la  sous séquence a gauche 
    i = finSeq1 -1;
    resultMaxTemp = resultatMilieu.max;
    while(i >= resultat1.debut ){
        resultMaxTemp += tab[i];
        if(resultMaxTemp > resultatMilieu.max){
            resultatMilieu.max = resultMaxTemp;
            resultatMilieu.debut = i;
        }
        --i;
    }
    return resultatMilieu;

}

Result testSousSequence(Result resultat1, int debutSeq1, int finSeq1,
    Result resultat2, int debutSeq2, int finSeq2,
    int tab[]) {
    Result resultat;
    int i;
    int resultMaxTemp;
    //gauche ou droite 
    if (resultat1.max < resultat2.max){  
        resultat.max = resultat2.max;
        resultat.debut = resultat2.debut;
        resultat.fin = resultat2.fin;
    }
    else  {
        resultat.max = resultat1.max;
        resultat.debut = resultat1.debut;
        resultat.fin = resultat1.fin;
    }
    //Test du milieu
    Result resultatMilieu;
    //coler au 2
    if(resultat1.fin == finSeq1 && resultat2.debut == debutSeq2){
        resultatMilieu.max = resultat1.max + resultat2.max;
        resultatMilieu.debut = resultat1.debut;
        resultatMilieu.fin = resultat2.fin;
    }

    //coler a gauche 
    else if(resultat1.fin == finSeq1){
        resultatMilieu = collerGauche(resultat1,resultat2,debutSeq2,tab);
    }
    //coler a droite 
    else if(resultat2.debut == debutSeq2){
        resultatMilieu = collerDroite(resultat2,resultat1,finSeq1,tab);
    }
    //Pas coller
    else {
        resultatMilieu.max = tab[finSeq1] + tab[debutSeq2];
        resultatMilieu.debut = finSeq1;
        resultatMilieu.fin = debutSeq2; 
        i = finSeq1 -1;

        resultMaxTemp = resultatMilieu.max;
        while(i >= resultat1.debut ){
            resultMaxTemp += tab[i];
            if(resultMaxTemp > resultatMilieu.max){
                resultatMilieu.max = resultMaxTemp;
                resultatMilieu.debut = i;
            }
            --i;
        }

        i = debutSeq2 +1;
        while(i <= resultat2.fin ){
            resultMaxTemp += tab[i];
            if(resultMaxTemp > resultatMilieu.max){
                resultatMilieu.max = resultMaxTemp;
                resultatMilieu.fin = i;
            }
            ++i;
        }
    }
    if(resultatMilieu.max > resultat.max){
     return resultatMilieu;
 }
 return resultat;
}

Result diviserPourRegner(int t[], int debut, int fin ){
    Result r;
    if(debut == fin){
        r.max = t[debut];
        r.debut = debut;
        r.fin = fin;
    }
    else if (debut < fin) {
        Result r1;
        Result r2;
        r1 = diviserPourRegner(t,debut,(debut+fin)/2);
        r2 = diviserPourRegner(t,((debut+fin)/2)+1,fin);
        r = testSousSequence(r1,debut,((debut+fin)/2),r2,(((debut+fin)/2)+1),fin,t);
    }
    return r;
}

Result algo3(int* t,int n){  
    Result r;
    r = diviserPourRegner(t,0,n-1);
    return r;
}