
#include "../header/util.h"
#include <sys/types.h>
#include <sys/wait.h>

#define NBALGO 4
#define NBTAILLE 15
#define TEMPMAX 300
#define SIZE_MAX_BUFF_READ 1000
#define SIZEDOUBLE 11

Result algo1 (int* t, int size);
Result algo2 (int* t, int size);
Result algo3 (int* t, int size);
Result algo4 (int* t, int size);

int tailleTab[NBTAILLE] = {100,500,5000,10000,50000,100000,200000,300000,400000,500000,600000,700000,800000,900000,1000000};
char* nomFontion[NBALGO] = {"algo1","algo2","algo3","algo4"};

Result (*listeFonctions[NBALGO])(int*,int) = {algo1,algo2,algo3,algo4};

int k;    // compteur boucle des fonctions de tris
int j;    // compteur boucle des tailles d'un tableau pour un tris 


int indiceSize( int size ) {
    int i;
    for(i=0; i<NBTAILLE; ++i)
       if(tailleTab[i] == size)
            return i;
    return 0;
}

void initFic() {
    int i, j;
    FILE* file = NULL;

    file = fopen("result.csv", "w+");

    if (file != NULL) {
        fprintf(file, "Nom\\Taille,");
        for(j=0; j<NBTAILLE; ++j)
                fprintf(file,"%d,", tailleTab[j]);
        fprintf(file, "\n");
        for(i=0; i<NBALGO; ++i) {
            fprintf(file,"%s,", nomFontion[i]);
            for(j=0; j<NBTAILLE; ++j)
                fprintf(file,"%011.06f,",0.0);
            fprintf(file,"\n");
        }
        fclose(file);
    }
}

void writeFic(int size, int nbTri, double result) {
    int i, j;
    double score;
    char carac = 'a';
    char string[SIZE_MAX_BUFF_READ];
    FILE* file = NULL;
    file = fopen("result.csv", "r+");

    for(i=0; i<nbTri+1; ++i)
        fgets(string, SIZE_MAX_BUFF_READ, file);
    while (carac != ','){
        carac = (char)fgetc(file);
    }
    j = indiceSize(size);
    j = (SIZEDOUBLE+1)*j;
    fseek(file, j , SEEK_CUR);
    fprintf(file, "%011.06f", result);
    fclose(file);
}




void endAlarm(){
    printf("fin timer.\n");
    exit(EXIT_SUCCESS);
}

int main(int argc,char const * argv[])
{
    Result (*fonctionDeSSq)(int*, int); // déclaration du pointeur de fonction

    int fils;
    int taille; // taille du tableau courrant a tester
    int* tab; // le tableau qui est utilisé pour les test
    int status;

    clock_t Timer5min; // valeur du timer de début pour test si elle est inferieur à 5min a chaque test de tableau.
    clock_t debut;     // valeur du début du test pour avoir la valeur en secondes (float) du temps du test

    double tt;          // valeur finale du temps qu'a mis le test pour un tableau a s'effectuer.

    Result r;          // Structure Result de retour


    // int NombreCoeur = get_nprocs_conf();
    // int NombreCoeurUtilise = 0;
    //printf("%d\n",thread_free );
    
    initFic();
    signal(SIGALRM, endAlarm);
    for (j = 0; j < NBTAILLE; ++j){
        
        taille = tailleTab[j];
        tab = giveTestTab(taille);

        for (k = 0; k < NBALGO; ++k)
        {
           // if(++NombreCoeurUtilise >= NombreCoeur) {
           //          wait(NULL);
           //          NombreCoeurUtilise--;
           //  }
            fils = fork();
            if(fils == 0){
                printf("Debut du %s _ Tableau de taille n=%d \n",nomFontion[k], taille);
                fonctionDeSSq = listeFonctions [k];  // On sélectionne la fonction de tris grace au pointeur de fonction
                alarm(TEMPMAX);
                debut = startTimer(); // temps début 
                r = (*fonctionDeSSq)(tab, taille); // Lance le test
                tt = endTimer(debut); // temps final du traitement du tris.
                afficheResultat(r);
                writeFic(taille,k,tt);
                printf("Fin du %s _ Tableau de taille n=%d en %f sec\n",nomFontion[k], taille, tt );
                exit(EXIT_SUCCESS);
            }
            wait(&status);
        }
        //while(wait(&status) != -1);
        // NombreCoeurUtilise = 0;
        free(tab);
    }
}
