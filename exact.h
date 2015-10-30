#ifndef EXACTE_H
#define EXACTE_H


/* Permet d'assurer le test de toute les permutations
*/
int nbEmpty(int * tab, int taille);


/* Branch_bound calcule le cout optimal d'une instance, le paramètre nodeCount permet de récupérer le nombre de noeuds explorés
*/
instance_t * branch_bound(instance_t * inst,int * nodeCount);

/* Fonction récursive pour le branch and bound, ne pas appeler, utiliser branch_bound à la place.
*/
void branch_bound_rec(instance_t * inst,int * curSol,int curseur,int * tA,int * tB,int* tC,int* bestBorneInf,int* bestBorneSup,instance_t ** solution,int * nodeCount);

#endif

