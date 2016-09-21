#include "../header/util.h"
#include <sys/types.h>
#include <sys/wait.h>

#define NBALGO 4
#define NBTAILLE 15
#define TEMPMAX 10 //300

Result algo1 (int* t, int size);
Result algo2 (int* t, int size);
Result algo3 (int* t, int size);
Result algo4 (int* t, int size);

Result (*listeFonctions[NBALGO])(int*,int) = {algo1,algo2,algo3,algo4};

int k;    // compteur boucle des fonctions de tris
int j;    // compteur boucle des tailles d'un tableau pour un tris 

void endAlarm(){
    printf("fin timer.\n");
    exit(EXIT_SUCCESS);
   /* FILE *f = fopen("data.csv","r+");
    if (f == NULL){
        printf("Fichier non trouvé.\n");
        return -1;
    }
    for (int newJ = j; newJ < NBTAILLE; ++newJ) // Met les valeurs restantes à 300 secondes
    {
        fseek(f, FIRST_LINE + k*NEXT_LINE + NAME_SIZE + (newJ*NUMBER_SIZE), SEEK_SET); // Place le pointeur de fichier au bon endroit.
        fputs("300.000000",f);
    }
    fclose(f);*/
}

int main(int argc,char const * argv[])
{
    Result (*fonctionDeSSq)(int*, int); // déclaration du pointeur de fonction

    int fils;
    int taille; // taille du tableau courrant a tester
    int* tab; // le tableau qui est utilisé pour les test

    clock_t Timer5min; // valeur du timer de début pour test si elle est inferieur à 5min a chaque test de tableau.
    clock_t debut;     // valeur du début du test pour avoir la valeur en secondes (float) du temps du test

    float tt;          // valeur finale du temps qu'a mis le test pour un tableau a s'effectuer.

    Result r;          // Structure Result de retour

    int status;
    int tailleTab[NBTAILLE] = {100,500,5000,10000,50000,100000,200000,300000,400000,500000,600000,700000,800000,900000,1000000};
    char* functionName[NBALGO] = {"algo1","algo2","algo3","algo4"};

    // int NombreCoeur = get_nprocs_conf();
    // int NombreCoeurUtilise = 0;
    //printf("%d\n",thread_free );
    
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
                printf(" Debut du %s _ Tableau de taille n=%d \n",functionName[k], taille);
                fonctionDeSSq = listeFonctions [k];  // On sélectionne la fonction de tris grace au pointeur de fonction
                alarm(TEMPMAX);
                debut = startTimer(); // temps début 
                r = (*fonctionDeSSq)(tab, taille); // Lance le test
                tt = endTimer(debut); // temps final du traitement du tris.
                afficheResultat(r);
                printf("Fin du %s _ Tableau de taille n=%d en %f sec\n",functionName[k], taille, tt );
                exit(EXIT_SUCCESS);
            }
            wait(&status);
        }
        //while(wait(&status) != -1);
        // NombreCoeurUtilise = 0;
        free(tab);
    }


         // Boucle qui parcours toutes les tailles de tableau
        //{
            
            //char str[NUMBER_SIZE] = "";
         
            
            
                // FILE *f = fopen("data.csv","r+");
                // if (f == NULL){
                //     printf("Fichier non trouvé.\n");
                //     return -1;
                // }
                // fseek(f, FIRST_LINE + k*NEXT_LINE + NAME_SIZE + (j*NUMBER_SIZE), SEEK_SET); // Place le pointeur de fichier au bon endroit.
                // normalizeFloat(str,tt);  // normalise le temps moyen effectué par le tris en string et rajoute des zero devant si besoin.
                // fputs(str,f);// écris au bon endroit la moyenne des valeurs du tableau moy (qui contient toutes les valeurs retournées.)
                // fclose(f);
        //}
        //}
}
