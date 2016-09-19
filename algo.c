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
