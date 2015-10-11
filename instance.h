#ifndef INSTANCE_H

#define INSTANCE_H

extern int instcp;

typedef struct instance_s{
    	int num_instance;
	int nb_elem;
	int *A;
	int *B;
	int *C;
}instance_t;


int aleatoire(int min,int max);
instance_t * instanceCreer(int nb_elem);
void instanceInit(instance_t * inst);
void instanceRandNC(instance_t * inst);
void instanceRandDE(instance_t * inst);
void instanceRandM(instance_t * inst);
void instanceDetruire(instance_t * inst);
instance_t * instanceCopie(instance_t * inst);

void instanceAfficher(instance_t * inst);

#endif



