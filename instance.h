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

/* Permet de permuter deux taches de l'instance
*/
void instanceTachePermuter(instance_t * inst,int i,int j);

int aleatoire(int min,int max);

/* Primitives de création, d'initialisation et de copie
* Une instance doit être initialisée après création, a moins d'utiliser un générateur voir test.c pour exemple d'utilisation.
*/
instance_t * instanceCreer(int nb_elem,char * nom);
void instanceInit(instance_t * inst);
instance_t * instanceCopie(instance_t * inst);


/* Générateurs pour les différentes classes d'instances
*
*/
void instanceRandNC(instance_t * inst); //Données non corrélées
void instanceRandDE(instance_t * inst); //Corrélation sur les durées d'exécution
void instanceRandM(instance_t * inst); //Corrélation sur les machines

/* Fonctions de lecture et d'écriture de fichier d'instance, voir ExempleInstance.txt pour format.
*/
instance_t * instanceRead(char * name);
void instanceWrite(instance_t * inst,char * name);


/* Permet d'obtenir le cout d'une instance
*/
int instanceCout(instance_t * inst);

/* Permet d'afficher une instance
*/
void instanceAfficher(instance_t * inst);

/* Libère la mémoire occupée par l'instance
*/
void instanceDetruire(instance_t * inst);

#endif



