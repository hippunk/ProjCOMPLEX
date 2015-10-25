#ifndef INSTANCE_H

#define INSTANCE_H

typedef struct instance_s{
    char * num_instance;
	int nb_elem;
	int *ordre;
	int *A;
	int *B;
	int *C;
}instance_t;

void instanceTachePermuter(instance_t * inst,int i,int j);
int aleatoire(int min,int max);
instance_t * instanceCreer(int nb_elem,char * nom);
void instanceInit(instance_t * inst);
void instanceRandNC(instance_t * inst);
void instanceRandDE(instance_t * inst);
void instanceRandM(instance_t * inst);
void instanceDetruire(instance_t * inst);
instance_t * instanceCopie(instance_t * inst);

instance_t * instanceRead(char * name);
void instanceWrite(instance_t * inst,char * name);

int instanceCout(instance_t * inst);
void instanceAfficher(instance_t * inst);

#endif



