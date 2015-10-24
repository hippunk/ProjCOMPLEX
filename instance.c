#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "instance.h"

int aleatoire(int min,int max){
    return (rand()%(max-min+1))+min;
}

instance_t * instanceCreer(int nb_elem,char * nom){
    
	instance_t * inst = malloc(sizeof(instance_t)); 
	inst->num_instance = malloc(sizeof(char)*256);
	strcpy(inst->num_instance,nom);
	inst->nb_elem = nb_elem;
	inst->ordre = malloc(sizeof(int)*nb_elem);
	inst->A = malloc(sizeof(int)*nb_elem);
	inst->B = malloc(sizeof(int)*nb_elem);
	inst->C = malloc(sizeof(int)*nb_elem);

	return inst;
}

void instanceInit(instance_t * inst){
	for(int i = 0;i<inst->nb_elem;i++){
	    inst->ordre[i] = i;
	    inst->A[i] = 0;
	    inst->B[i] = 0;
	    inst->C[i] = 0;
	}
}

void instanceRandNC(instance_t * inst){
    instanceInit(inst);
	for(int i = 0;i<inst->nb_elem;i++){
	    inst->ordre[i] = i;
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
	    inst->ordre[i] = i;
	    inst->A[i] = aleatoire(aik,bik);
	    inst->B[i] = aleatoire(aik,bik);
	    inst->C[i] = aleatoire(aik,bik);
	}
}

void instanceRandM(instance_t * inst){

	for(int i = 0;i<inst->nb_elem;i++){
	    inst->ordre[i] = i;
	    inst->A[i] = aleatoire(1,100);
	    inst->B[i] = aleatoire(16,115);
	    inst->C[i] = aleatoire(31,130);
	}
}

instance_t * instanceCopie(instance_t * inst){

    instance_t * copie = instanceCreer(inst->nb_elem,inst->num_instance);
    
	for(int i = 0;i<inst->nb_elem;i++){
	    copie->ordre[i] = i;
	    copie->A[i] = inst->A[i];
	    copie->B[i] = inst->B[i];
	    copie->C[i] = inst->C[i];
	}
	
	
	return copie;
}

int instanceCout(instance_t *inst){
	int tA=0,tB=0,tC=0 ;
	for(int i=0;i<inst->nb_elem;i++){
	    tA += inst->A[i];
	    if(tB < tA){
			tB = tA+inst->B[i];
		}else{
			tB+=inst->B[i];
		}
	    if(tC < tB){
			tC = tB+inst->C[i];
		}else{
			tC+=inst->C[i];
		}
	}

	return tC;	

}

void instanceAfficher(instance_t * inst){
    printf("Instance : %s\n",inst->num_instance);
    printf("#####################################################\n");
    printf("# Tache # Ordre # Machine A # Machine B # Machine C #\n");
    printf("#####################################################\n");
    
    
	for(int i = 0;i<inst->nb_elem;i++){
	    printf("# %5i # %5i # %9i # %9i # %9i #\n",i,inst->ordre[i],inst->A[i],inst->B[i],inst->C[i]);

	}
	printf("######################################################\n");
	printf("Cout : %i\n",instanceCout(inst));
}

instance_t * instanceRead(char * name){

    FILE *ifp;
    int buff;
    instance_t * inst = NULL;

    ifp = fopen(name, "r");

    if (ifp == NULL) {
      fprintf(stderr, "Can't open input file.\n");
      exit(1);
    }
    
    //Lecture du nombre de taches
    fscanf(ifp, "%i", &(buff));
    
    inst = instanceCreer(buff,name);
    instanceInit(inst);
    
    //Lecture du tableau A
    for(int i = 0;i<inst->nb_elem;i++){
        fscanf(ifp, "%i",&(inst->A[i]));
    }
    //Lecture du tableau B
    for(int i = 0;i<inst->nb_elem;i++){
        fscanf(ifp, "%i",&(inst->B[i]));
    }
    //Lecture du tableau C
    for(int i = 0;i<inst->nb_elem;i++){
        fscanf(ifp, "%i",&(inst->C[i]));
    }
    
    fclose(ifp);
    return inst;
}

void instanceWrite(instance_t * inst,char * name){
    FILE *ofp;


    ofp = fopen(name, "w");

    if (ofp == NULL) {
      fprintf(stderr, "Can't open output file.\n");
      exit(1);
    }
    
    //Ecriture du nombre de taches
    fprintf(ofp, "%i\n", inst->nb_elem);
    
    //Lecture du tableau A
    fprintf(ofp, "%i", inst->A[0]);
    for(int i = 1;i<inst->nb_elem;i++){
        fprintf(ofp, " %i", inst->A[i]);
    }
    fprintf(ofp, "\n");
    
    //Lecture du tableau B
    fprintf(ofp, "%i", inst->B[0]);
    for(int i = 1;i<inst->nb_elem;i++){
        fprintf(ofp, " %i", inst->B[i]);
    }
    fprintf(ofp, "\n");
    
    //Lecture du tableau C
    fprintf(ofp, "%i", inst->C[0]);
    for(int i = 1;i<inst->nb_elem;i++){
        fprintf(ofp, " %i", inst->C[i]);
    }
    
    fclose(ofp);
}

void instanceDetruire(instance_t * inst){
	free(inst->ordre);
	free(inst->num_instance);
	free(inst->A);
	free(inst->B);
	free(inst->C);
	free(inst);
}
