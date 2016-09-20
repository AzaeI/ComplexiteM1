#include "../header/util.h"

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

int* giveTestTab(int size){
    int* test = newArray(size);
    srand(time(0));
    int i;
    for (i=0 ; i<size ; i++)
    {
        test[i]=((unsigned int) rand()%MAX_VALUE);
    }
    return test;
}

float endTimer(clock_t debut){
    clock_t fin = clock();
    float tt = ((fin-debut)*1.0/CLOCKS_PER_SEC);
    return tt;
}

clock_t startTimer(){
    clock_t debut = clock();
    return debut;
}
