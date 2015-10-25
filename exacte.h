#ifndef EXACTE_H
#define EXACTE_H



int nbEmpty(int * tab, int taille);
void branch_bound_rec(instance_t * inst,int * curSol,int curseur,int * tA,int * tB,int* tC,int* borneInf);
int * branch_bound(instance_t * inst);

#endif

