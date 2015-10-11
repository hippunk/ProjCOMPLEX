#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"instance.h"

#define INF INT_MAX
 
 
int minAB(instance_t *t, int* i, int* j){
    int min=INF;
    for(int k=0;k<t->nb_elem;k++){
            if(min > t->A[k] && t->A[k] < t->B[k]){
                    min=t->A[k];
                    *i=k;
                    *j=0;
            }else if( min > t->B[k] ){
                    min=t->B[k];
                    *i=k;
                    *j=1;                  
            }
    }
    return min;
}
                               
instance_t* johnson(instance_t* inst){
	int i,j,min,g_pos,d_pos;
	instance_t* t;
	instance_t* new;
	t=instanceCreer(inst->nb_elem,"");
	t=instanceCopie(inst);
	new=instanceCreer(t->nb_elem,"");
	instanceInit(new);
	g_pos=0;
	d_pos=t->nb_elem-1;
	for(int k=0;k<t->nb_elem;k++){
		min=minAB(t, &i, &j);
		printf("min=%d \n",min);
		if(j==0){ //durée de tache min est sur la machine A -> on rajoute en début 
			new->A[g_pos]=t->A[i];
			new->B[g_pos]=t->B[i];
			new->C[g_pos]=t->C[i];
			t->A[i]=INF;
			t->B[i]=INF;
			g_pos++;
		}else{ //durée de la tache min est sur la machine B -> on rajoute en fin
			new->A[d_pos]=t->A[i];
			new->B[d_pos]=t->B[i];
			new->C[d_pos]=t->C[i];
			t->A[i]=INF;
			t->B[i]=INF;
			d_pos--;
		}
	}
	instanceDetruire(t);
	return new;
}
			
