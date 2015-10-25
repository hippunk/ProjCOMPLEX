#ifndef EXACTE_H
#define EXACTE_H

#include "instance.h"

int nbEmpty(int * tab, int taille);
void branch_bound_rec(instance_t * inst,int * tab,int * curSol,int curseur,int * tA,int * tB,int* tC,int* borneInf);
int * branch_bound(instance_t * inst);

#endif

