#include "../header/util.h"
// #include "../header/algo3.h"
// #include "../header/touteSousSequence.h"
#include "../header/algo4.h"

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
    //res = aglo1(tab,tailleTab);
    // res = aglo2(tab,0,tailleTab);
    // res = aglo2(tab,0,tailleTab);
    res = algo4(tab,tailleTab);  
    //res = aglo4(tab,tailleTab);
    //afficheTabIndice(res.debut,res.fin,tab);
    //afficheResultat(res);
    printf("%d %d",res.debut,res.fin);
    free(tab);
}
