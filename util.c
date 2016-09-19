#include "util.h"

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

void afficheTabIndice(int debut, int fin, int tab[]){
    printf("[");
    for (int i = debut; i < fin; ++i)
    {
        printf("%d.",tab[i]);
    }
    printf("%d]\n",tab[fin]);
}