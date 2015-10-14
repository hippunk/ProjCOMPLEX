#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"instance.h"
#include"test.h"
#include"algo_approche.h"

void instance_test(){
	instance_t* t;
	t=instanceCreer(3,"cout test");
	instanceRandNC(t);
	instanceAfficher(t);
}

void johnson_test(int taille){
    printf("Début test johnson, instance de taille %i\n",taille);
    instance_t* inst;
    instance_t* john_inst;
    printf("Création de l'instance\n");
    inst=instanceCreer(taille,"NC");
    printf("Initialisation de l'instance\n");
    instanceRandNC(inst);
    //instanceAfficher(inst);
    
    printf("Approximation johnson\n");
    john_inst=johnson(inst);
    //instanceAfficher(john_inst);
    
    printf("Destruction instances\n");
    instanceDetruire(john_inst);
    instanceDetruire(inst);
    printf("Fin test\n");
}

void minAB_test(){
    printf("\nTest de la fonction minAB\n");
    printf("Le résultat correspond à la tache la plus courte sur les machines A et B\n");
    instance_t * inst = instanceCreer(10,"Pouet");
    
    instanceRandNC(inst);
    instanceAfficher(inst);
    int i,j;
    int m=minAB(inst,&i,&j);
    printf("\nValeur = %d, Tache n° = %d, Machine = %c\n\n",m,i,'A'+j);

    
    instanceDetruire(inst);
}

void minAB_test_distribNC(int loop,void (*pInstRand)(instance_t * inst)){
    printf("\nTest de la distribution de proba du résultat minAB\n");
    printf("Le résultat correspond à la distribution de proba du résultat de minAB\n");
    instance_t * inst = instanceCreer(10,"Test distrib");
    float cpt1 = 0;
    float cpt2 = 0;
    int i = 0,j = 0;
    for(int cpt = 0;cpt<loop;cpt++){
        pInstRand(inst);
        
        minAB(inst,&i,&j);
        if(j == 0)
            cpt1++;
        else
            cpt2++;
        //printf("Tour %i\n",cpt);
    }

    printf("\nMinimum machine A = %.3f, Minimum machine B = %.3f\n\n",cpt1/loop,cpt2/loop);
    instanceDetruire(inst);
}
