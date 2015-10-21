#ifndef EXACTE_H
#define EXACTE_H

int nbEmpty(int * tab, int taille);
int * branch_bound_rec(int * tab,int * curSol,int taille,int curseur);
int * branch_bound(int * tab,int taille);

#endif

