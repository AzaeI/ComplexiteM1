#include "../header/util.h"
#include "../header/algo4.h"

int main(int argc, char const *argv[])
{
    if(argc < 2){
        fprintf(stderr, "Usage ./algo4 X X X X\n");
        return 0;
    }
    int tailleTab = argc -1; 
    int *tab = (int*)malloc(tailleTab * sizeof(int));
    for (int i = 0; i < tailleTab; ++i) {
       tab[i] = atoi(argv[i+1]);
    }
    Result res;
    res = algo4(tab,tailleTab);
    printf("Resultat: %d %d max: %d\n",res.debut,res.fin,res.max);
    
    tab =giveTestTab(tailleTab);

    free(tab);
    return 0;
}