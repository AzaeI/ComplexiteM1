 #include <stdio.h>

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
            for (int i = indiceCourrantD; i < indiceCourrantF + 1; ++i) {
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
			// printf(" max tmp = %d\n", maxTmp);
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
        resultatMilieu.debut = resultat1.debut;
        resultatMilieu.fin = debutSeq2; 
        //si le milieu est améliore par la  sous séquence a droite  
        i = resultat2.debut +1;
        resultMaxTemp = resultatMilieu.max;
        while(i < finSeq2 ){
            resultMaxTemp += tab[i];
            if(resultMaxTemp > resultatMilieu.max){
                resultatMilieu.max = resultMaxTemp;
                resultatMilieu.fin += i;
            }
            ++i;
        }
    }
    //coler a droite 
    else if(resultat2.debut == debutSeq2){
        
        resultatMilieu.max = tab[finSeq1] + resultat2.max;
        resultatMilieu.debut = finSeq1;
        resultatMilieu.fin = resultat2.fin; 
        //si le milieu est améliore par la  sous séquence a gauche 
        i = resultat2.debut -1;
        resultMaxTemp = resultatMilieu.max;
        while(i > resultat1.debut ){
        
            resultMaxTemp += tab[i];
            if(resultMaxTemp > resultatMilieu.max){
                resultatMilieu.max = resultMaxTemp;
                resultatMilieu.debut -= i;
            }
            --i;
        }
    }
    else {
        resultatMilieu.max = tab[finSeq1] + tab[debutSeq2];
        resultatMilieu.debut = finSeq1;
        resultatMilieu.fin = debutSeq2; 
        i = finSeq1;
        while(i > resultat1.debut ){
            resultMaxTemp += tab[i];
            if(resultMaxTemp > resultatMilieu.max){
                resultatMilieu.max = resultMaxTemp;
                resultatMilieu.debut -= i;
            }
            --i;
        }
        while(i < finSeq2 ){
            resultMaxTemp += tab[i];
            if(resultMaxTemp > resultatMilieu.max){
                resultatMilieu.max = resultMaxTemp;
                resultatMilieu.fin += i;
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
    r = diviserPourRegner(t,0,n);
    return r;
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

int main()
{
	int n = 5;
	Result res;
	int tab[5] = {1,5,-6,9,-2};

	afficheTab(tab,n);
	//res = aglo1(tab,5);
	// res = aglo2(tab,0,5);
    res = aglo3(tab,5);
	afficheResultat(res);
}
