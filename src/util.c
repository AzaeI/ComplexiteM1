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

int* newArray(int SIZE){
    int* a = calloc (SIZE, sizeof(int));
    return a;
}

int* giveTestTab(int size){
    int* test = newArray(size);
    srand(time(0));
    int Min = -100;
    int Max = 100;
    int i;
    for (i=0 ; i<size ; i++)
    {
        test[i] = rand()%(Max-Min)+Min;

    }
    return test;
}

double endTimer(clock_t debut){
    clock_t fin = clock();
    return (double) (fin - debut) / CLOCKS_PER_SEC;;
}

clock_t startTimer(){
    clock_t debut = clock();
    return debut;
}
