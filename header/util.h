#ifndef __UTIL_H__
#define __UTIL_H__

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h> //clock()
#include <string.h>
#include <signal.h> // alarms
#include <sys/sysinfo.h> //signal


typedef struct Result Result;
struct Result 
{
    int debut;
    int fin;
    int max;
};

#define MAX_VALUE 100

#define FIRST_LINE 113 
#define NEXT_LINE 182
#define NUMBER_SIZE 11
#define NAME_SIZE 16


/**
 * \fn void afficheResultat( Result res) 
 * \author Yohan Roux 
 * \brief affiche le troncon max ainsi que la somme max 
 * \param[in] res la struct contenant le résultat 
 */
void afficheResultat(Result res);

/**
 * \fn void afficheTab(int t[], int n) 
 * \author Yohan Roux 
 * \brief affiche le tableau
 * \param[in] t le tableau a afficher 
 * \param[in] n taille du tableau 
 */
void afficheTab(int t[], int n);

/**
 * \fn void calSomme(int t[], int debut,int fin) 
 * \author Yohan Roux 
 * \brief calcule la somme d'une séquence 
 * \param[in] t le tableau  
 * \param[in] debut l'indice de départ de la séquence a calculer 
 * \param[in] fin l'indice de fin de la séquence a calculer  
 */
void calSomme(int t[], int debut,int fin);

/**
 * \fn void afficheTabIndice(int debut, int fin, int tab[] )
 * \author Yohan Roux 
 * \brief affiche le contenu du tableau entre 2 indices 
 * \param[in] debut indice du début de la séquence 
 * \param[in] fin indice de fin de la séquence 
 * \param[in] tab le tableau ou se trouve la séquence  
 */
void afficheTabIndice(int debut, int fin, int tab[]);

/**
 * \fn int* newArray(int SIZE )
 * \author Yohan Roux 
 * \brief Créé un nouveau tableau et alloue sa zone mémoire.
 * \param[in] SIZE Taille du tableau 
 */
int* newArray(int SIZE);

/**
 * \fn int * giveTestTab( int size )
 * \author Yohan Roux 
 * \brief renvoi un tableau de nombre aléatoire d'une taille de size
 * \param[in] size taille du tableau a remplir 
 */
int* giveTestTab(int size);

/**
 * \fn float endTimer( clock_t debut )
 * \author Yohan Roux 
 * \brief calcul le temps d'exécution entre l'argument et le moment présent 
 * \param[in] debut valeur du déclanchement du chrono 
 */
double endTimer(clock_t debut);

/**
 * \fn clock_t startTimer()
 * \author Yohan Roux 
 * \brief renvoi le moment présent en clock_t 
 */
clock_t startTimer();

#endif 