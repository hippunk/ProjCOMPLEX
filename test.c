#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"instance.h"
#include"test.h"
#include"algo_approche.h"

void johnson_test(){
    instance_t* inst;
    instance_t* john_inst;
    
    inst=instanceCreer(10,"NC");
    instanceRandNC(inst);
    instanceAfficher(inst);
    
    
    john_inst=johnson(inst);
    instanceAfficher(john_inst);
    
    
    instanceDetruire(john_inst);
    instanceDetruire(inst);
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
