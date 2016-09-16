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
	int tab[5] = {-1,5,-6,9,-2};

	afficheTab(tab,n);
	res = aglo1(tab,5);
	// res = aglo2(tab,0,5);
	afficheResultat(res);
}
