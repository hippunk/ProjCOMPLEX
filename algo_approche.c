#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"instance.h"

#define INF INT_MAX
 
int min(){
    int min = 0;
    return min;
    
}
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

int ** tabTacheConstruct(instance_t* inst){

    int ** tab = malloc(sizeof(int*)*3);
    for(int i = 0;i<3;i++){
        tab[i] = malloc(sizeof(int*)*3);
    }
    
	for(int k=0;k<t->nb_elem;k++){
	    tab[0][k] = k;
        if(A[k] <= B[k]){
            tab[1][k] = A[k]
            tab[2][k] = 
        }


	}
    return tab;
}
                               
instance_t* johnson(instance_t* inst){
	int i = 0,j = 0,g_pos = 0,d_pos = 0;
	instance_t* t;
	instance_t* new;
	
	t=instanceCopie(inst);
	new=instanceCreer(t->nb_elem,"Johnson");
	
	instanceInit(new);
	
	g_pos=0;
	d_pos=t->nb_elem-1;
	
	for(int k=0;k<t->nb_elem;k++){
		minAB(t, &i, &j);

		if(j==0){ //durée de tache min est sur la machine A -> on rajoute en début 
		    new->ordre[g_pos]=t->ordre[i];
			new->A[g_pos]=t->A[i];
			new->B[g_pos]=t->B[i];
			new->C[g_pos]=t->C[i];
			g_pos++;
		}else{ //durée de la tache min est sur la machine B -> on rajoute en fin
		    new->ordre[d_pos]=t->ordre[i];
			new->A[d_pos]=t->A[i];
			new->B[d_pos]=t->B[i];
			new->C[d_pos]=t->C[i];
			d_pos--;
		}
		t->A[i]=INF;
		t->B[i]=INF;
	}
	
	instanceDetruire(t);
	
	return new;
}
			
