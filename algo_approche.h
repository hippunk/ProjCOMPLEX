#ifndef ALGO_APPROCHE_H

#define ALGO_APPROCHE_H

//FusionSort pour johnson nlogn
void fusion(int **tableau,int deb1,int fin1,int fin2);
void tri_fusion_bis(int **tableau,int deb,int fin);
void fusionSortHard3Tuple(int **tableau,int longueur);

int minAB(instance_t *t, int* i, int* j);
instance_t* johnson(instance_t* t);
int ** tabTacheConstruct(instance_t* inst);
void tabTacheDebug(int** tab,int taille);
instance_t* johnsonnlogn(instance_t* inst);
void tabTacheDestruct(int** tab);
#endif

