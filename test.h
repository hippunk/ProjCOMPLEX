#ifndef TEST_H
#define TEST_H


/*Chronomètre pour calculer les temps d'exécutions, 
* utilise le timestamp UNIX (non portable sous windows)
* Utilisation : le premier appel initialise le chrono, 
* tout autre appel retourne le temps écoulé depuis le dernier appel.
*/
double chrono();

/* Permet de tester l'algorithme de johnson pour les 3 classes d'instances
* Utilisation : prend en paramètre la taille maximale d'instance que l'on souhaite traiter
* Retourne : Les données sont formatées pour être utilisées directement avec gnuplot
* La première valeur correspond à : la taille de l'instance, 
* Les deux valeurs suivantes sont les temps d'exécutions de johnson n^2 et nlogn pour des données non corrélées,
* Les deux valeurs suivantes sont les temps d'exécutions de johnson n^2 et nlogn pour des données corrélées sur les durées d'exécutions,
* Les deux valeurs suivantes sont les temps d'exécutions de johnson n^2 et nlogn pour des données corrélées sur les machines.
*/
void johnsonTest(int instMax);

/* Permet de tester l'algorithme de branch and bound pour les 3 classes d'instances
* Utilisation : prend en paramètre la taille maximale d'instance que l'on souhaite traiter 
* ainsi que le nombre de tests effectués pour moyenner les résultats
* Retourne : Les données sont formatées pour être utilisées directement avec gnuplot
* La première valeur correspond à : la taille de l'instance, 
* Les 3 valeurs suivantes sont les temps d'exécutions de la méthode exacte pour les 3 classes d'instances.
* Les 3 valeurs suivantes sont les nombres de noeuds explorés par la méthode exacte pour les 3 classes d'instances.
*/
void exactTest(int instMax,int loop);


/*Compare les temps d'exécutions johnson n^2 et nlogn pour une instance de taille taille.
*/
void bench_john_nlogn_vs_n2(int taille);

/* Permet de tester le bon fonctionnement de la structure instance
*/
void instance_test();

/* Permet de vérifier le bon fonctionnement de l'algorithme de johnson
*/
void johnson_test();

/* Permet de tester la fonction minAB
*/
void minAB_test();

/*  Permet d'observer les distributions de probabilités selon la classe d'instance
*/
void minAB_test_distribNC(int loop,void (*pInstRand)(instance_t * inst));

#endif

