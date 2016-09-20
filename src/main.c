#include "../header/util.h"

Result algo1 (int* t, int size);
Result algo2 (int* t, int size);
Result algo3 (int* t, int size);
Result algo4 (int* t, int size);

Result (*listeFonctions[4])(int*,int) = {algo1,algo2,algo3,algo4};

int main(int argc,char const * argv[])
{

    Result (*fonctionDeSSq)(int*, int); // déclaration du pointeur de fonction

    int k;    // compteur boucle des fonctions de tris
    int j;    // compteur boucle des tailles d'un tableau pour un tris 
    int newJ; // compteur boucle qui permet de finir de remplir les résultat pour un test si celui ci est trop long (5min)
    int size; // taille du tableau courrant a tester
    int* tab; // le tableau qui est utilisé pour les test

    clock_t Timer5min; // valeur du timer de début pour test si elle est inferieur à 5min a chaque test de tableau.
    clock_t debut;     // valeur du début du test pour avoir la valeur en secondes (float) du temps du test

    float tt;          // valeur finale du temps qu'a mis le test pour un tableau a s'effectuer.

    int isBroke = 0;   //boolean, si le timer de 5 min est dépasser, on passe le boulean a faux et on n'entre pas dans la boucle de traitemant.
    Result r;          // Structure Result de retour

    int timesTab[15] = {100,500,5000,10000,50000,100000,200000,300000,400000,500000,600000,700000,800000,900000,1000000};
    char* functionName[4] = {"algo1","algo2","algo3","algo4"};

    for (k = 0; k < 4; ++k)
    {
        fonctionDeSSq = listeFonctions [k];  // On sélectionne la fonction de tris grace au pointeur de fonction
        Timer5min = startTimer();
        for (j = 0; j < 15 && !isBroke; ++j) // Boucle qui parcours toutes les tailles de tableau
        {
            size = timesTab[j];
            printf("Size : %d\n", size );
            char str[NUMBER_SIZE] = "";
            if (endTimer(Timer5min) > 300.0){ // Test si le timer excède 5min (300 secondes)
                printf("Temps Ecoule... Pour l'algo SSq :%s \n",functionName[k]);
                isBroke = 1;
                FILE *f = fopen("data.csv","r+");
                if (f == NULL){
                    printf("Fichier non trouvé.\n");
                    return -1;
                }
                for ( newJ = j; newJ < 15; ++newJ) // Met les valeurs restantes à 300 secondes
                {
                    fseek(f, FIRST_LINE + k*NEXT_LINE + NAME_SIZE + (newJ*NUMBER_SIZE), SEEK_SET); // Place le pointeur de fichier au bon endroit.
                    fputs("300.000000",f);
                }
                fclose(f);
                break;
            }
            tab = giveTestTab(size);
            debut = startTimer(); // temps début
            r = (*fonctionDeSSq)(tab, size); // Lance le test
            tt = endTimer(debut); // temps final du traitement du tris.
            free(tab);
            afficheResultat(r);
            FILE *f = fopen("data.csv","r+");
            if (f == NULL){
                printf("Fichier non trouvé.\n");
                return -1;
            }
            fseek(f, FIRST_LINE + k*NEXT_LINE + NAME_SIZE + (j*NUMBER_SIZE), SEEK_SET); // Place le pointeur de fichier au bon endroit.
            normalizeFloat(str,tt);  // normalise le temps moyen effectué par le tris en string et rajoute des zero devant si besoin.
            fputs(str,f);// écris au bon endroit la moyenne des valeurs du tableau moy (qui contient toutes les valeurs retournées.)
            fclose(f);
            printf(" Fin du %s _ Tableau de taille n° %d\n",functionName[k], size );
        }
    }
}
