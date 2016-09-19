 #include <stdio.h>
 #include <stdlib.h>

typedef struct Result Result;
struct Result 
{
    int debut;
    int fin;
    int max;
};

Result aglo1(int t[], int n){
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

void afficheTabIndice(int debut, int fin, int tab[]){
    printf("[");
    for (int i = debut; i < fin; ++i)
    {
        printf("%d.",tab[i]);
    }
    printf("%d]\n",tab[fin]);
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
        resultatMilieu.max = tab[debutSeq2]+ resultat1.max;
        // printf("---%d\n---",resultat1.debut);
        resultatMilieu.debut = resultat1.debut;
        resultatMilieu.fin = debutSeq2; 
        //si le milieu est améliore par la  sous séquence a droite  
        i = debutSeq2 +1;;
        resultMaxTemp = resultatMilieu.max;
        while(i <= finSeq2 ){
            resultMaxTemp += tab[i];
            if(resultMaxTemp > resultatMilieu.max){
                resultatMilieu.max = resultMaxTemp;
                resultatMilieu.fin = i;
            }
            ++i;
        }
    }
    //coler a droite 
    else if(resultat2.debut == debutSeq2){
        resultatMilieu.max = tab[finSeq1] + resultat2.max;
        resultatMilieu.debut = finSeq1 -1;
        resultatMilieu.fin = resultat2.fin; 
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
        while(i <= finSeq2 ){
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

Result aglo3(int t[],int n){  
    Result r;
    r = diviserPourRegner(t,0,n-1);
    return r;
}


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


void afficheResultat(Result res){
    printf("Tronçon [%d-%d] max = %d \n",res.debut ,res.fin, res.max );

}

void afficheTab(int t[], int n){
	printf("[");
	for (int i = 0; i < n-1; ++i){
		printf("%d.", t[i]);
	}
	printf("%d]\n", t[n-1]);
}

void calSomme(int t[], int debut,int fin){
    int somme = 0;
    for (int i = debut; i < fin+1; ++i)
    {
        somme += t[i];
    }
    printf("vérif :%d\n",somme);
}

#define N 101
int main(int argc,char const * argv[])
{
	Result res;
    if(argc < 1){
        fprintf(stderr, "nombre d'argument incorect" );
        return -1;
    }
    int tailleTab = argc -1; 
	int *tab = (int*)malloc(tailleTab * sizeof(int));
    for (int i = 0; i < tailleTab; ++i) {
        tab[i] = atoi(argv[i+1]);
    }
    //afficheTab(tab,tailleTab);
	res = aglo1(tab,tailleTab);
    // res = aglo2(tab,0,tailleTab);
	// res = aglo2(tab,0,tailleTab);
    res = aglo3(tab,tailleTab);  
    //res = aglo4(tab,tailleTab);
    //afficheTabIndice(res.debut,res.fin,tab);
    //afficheResultat(res);
    printf("%d %d",res.debut,res.fin);
    free(tab);
}
