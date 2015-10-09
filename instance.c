#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "instance.h"

int aleatoire(int min,int max){
    return (rand()%(max-min+1))+min;
}

instance_t * instanceCreer(int nb_elem){
    
	instance_t * inst = malloc(sizeof(instance_t)); 
	inst->num_instance = numInstance++;
	inst->nb_elem = nb_elem;
	inst->A = malloc(sizeof(int)*nb_elem);
	inst->B = malloc(sizeof(int)*nb_elem);
	inst->C = malloc(sizeof(int)*nb_elem);

	return inst;
}

void instanceInit(instance_t * inst){
	for(int i = 0;i<inst->nb_elem;i++){
	    inst->A[i] = 0;
	    inst->B[i] = 0;
	    inst->C[i] = 0;
	}
}

void instanceRandNC(instance_t * inst){
	for(int i = 0;i<inst->nb_elem;i++){
	    inst->A[i] = aleatoire(1,100);
	    inst->B[i] = aleatoire(1,100);
	    inst->C[i] = aleatoire(1,100);
	}
}

void instanceRandDE(instance_t * inst){
    int ir = aleatoire(0,4);
    int aik = 20*ir;
    int bik = 20*ir + 20;

	for(int i = 0;i<inst->nb_elem;i++){
	    inst->A[i] = aleatoire(aik,bik);
	    inst->B[i] = aleatoire(aik,bik);
	    inst->C[i] = aleatoire(aik,bik);
	}
}

void instanceRandM(instance_t * inst){

	for(int i = 0;i<inst->nb_elem;i++){
	    inst->A[i] = aleatoire(1,100);
	    inst->B[i] = aleatoire(16,115);
	    inst->C[i] = aleatoire(31,130);
	}
}

instance_t * instanceCopie(instance_t * inst){

    instance_t * copie = instanceCreer(inst->nb_elem);

	for(int i = 0;i<inst->nb_elem;i++){
	    copie->A[i] = inst->A[i];
	    copie->B[i] = inst->B[i];
	    copie->C[i] = inst->C[i];
	}
	
	
	return copie;
}

void instanceAfficher(instance_t * inst){
    printf("Instance : %i\n",inst->num_instance);
    printf("#############################################\n");
    printf("# Tache # Machine A # Machine B # Machine C #\n");
    printf("#############################################\n");
    
    
	for(int i = 0;i<inst->nb_elem;i++){
	    printf("# %5i # %9i # %9i # %9i #\n",i,inst->A[i],inst->B[i],inst->C[i]);

	}
	printf("#############################################\n");
}



void instanceDetruire(instance_t * inst){
	free(inst->A);
	free(inst->B);
	free(inst->C);
	free(inst);
}
