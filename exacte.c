#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include "exacte.h"
#include "instance.h"
#include "algo_approche.h"
#define EMPTY -1
#define INF INT_MAX

int nbEmpty(int * tab, int taille){
     int cpt = 0;
	for(int i = 0;i<taille;i++){
	     if(tab[i]!=EMPTY){
	          cpt++;
	     }
	}
	return cpt;
}

int max3(int a, int b, int c){
	if(a>=b){
		if(a>=c){ return a;
		}else{ return c;}
	}else{
		if(b>=c){ return b;
		}else{ return c;}
	}
}
		

int inf_b1(instance_t *inst,int tA, int tB, int tC){
	int sum_dA=0,sum_dB=0,sum_dC=0,min_dBC=INF,min_dC=INF,bA=0,bB=0,bC=0;
	for(int i=0;i<inst->nb_elem;i++){
		if(inst->ordre[i]!=-1){  //la tache n'a pas encore été choisie
		//bA
			sum_dA+=inst->A[i];
			if(min_dBC<inst->B[i]+inst->C[i]){
				min_dBC=inst->B[i]+inst->C[i];
			}
		//bB
			sum_dB+=inst->B[i];
			if(min_dC<inst->C[i]){
				min_dC=inst->C[i];
			}
		//bC
			sum_dC+=inst->C[i];
		}		
	}
	bA=tA+sum_dA+min_dBC;
	bB=tB+sum_dB+min_dC;
	bC=tC+sum_dC;
	return max3(bA,bB,bC);
}

	
int inf_b2(instance_t *inst, int tA){
	int sum_dK=0, sum_dA=0,sum_dC=0,max=0;
	for(int i=0;i<inst->nb_elem;i++){
		for(int j=0;j<inst->nb_elem;j++){
			if(inst->A[j]<=inst->C[j]){
				sum_dA+=inst->A[j];
			}else{
				sum_dC+=inst->C[j];
			}
		}
		sum_dK=inst->A[i]+inst->B[i]+inst->C[i];		
		if(sum_dK+sum_dA+sum_dC>max){
			max=sum_dK+sum_dA+sum_dC;
		}
		sum_dK=0;
		sum_dA=0;
		sum_dC=0;
	}
	return tA+max; //on n'a pas besoin de tA ici mais c'es un question de cohérence avec b1
}
	
int inf_b3(instance_t *inst, int tB){
	int sum_dK=0, sum_dB=0,sum_dC=0,max=0;
	for(int i=0;i<inst->nb_elem;i++){
		for(int j=0;j<inst->nb_elem;j++){
			if(inst->B[j]<=inst->C[j]){
				sum_dB+=inst->B[j];
			}else{
				sum_dC+=inst->C[j];
			}
		}
		sum_dK=inst->B[i]+inst->C[i];		
		if(sum_dK+sum_dB+sum_dC>max){
			max=sum_dK+sum_dB+sum_dC;
		}
		sum_dK=0;
		sum_dB=0;
		sum_dC=0;
	}
	return tB+max; //on n'a pas besoin de tB ici mais c'es un question de cohérence avec b1
}
int inf_bMax(instance_t *inst,int tA, int tB, int tC){
	int b1=0,b2=0,b3=0;
	int b1=inf_b1(inst,tA,tB,tC);
	b2=inf_b2(inst,tA);
	b3=inf_b3(inst,tB);
	return max3(b1,b2,b3);
}

int * branch_bound_rec(int * tab,int * curSol,int taille,int curseur){

    //Debug affichage données noeud courant 
        /*printf("Solution partielle courante :");
        for(int i = 0;i<curseur;i++){
             if(curSol[i]!=EMPTY){
                  printf("%i ",curSol[i]);
             }
        }
        printf("\n");*/

     /*Traitement quand dans une feuille*/
     if(nbEmpty(tab,taille) == 0){
          //Debug affichage noeud feuille
               /*printf("Solution dans feuille : ");
               for(int i = 0;i<curseur;i++){
                    printf("%i ",curSol[i]);
               }
               printf("\n");*/
        
     }

     for(int k = 0;k<taille;k++){
        //printf("Empty ? : %i \n",tab[k]);
          if(tab[k]!=EMPTY){
               //printf("Tab k %i\n",tab[k]);
               //printf("Profondeur : %i, tab[k] : %i\n",curseur,tab[k]);
               int tmp = tab[k];
               tab[k] = EMPTY;  
               curSol[curseur] = tmp;   
                             
                    
               curSol = branch_bound_rec(tab,curSol,taille,curseur+1);
               tab[k] = tmp;                 
          }
     }
     
     return curSol; 
}
/*tab et taille ammenés à être remplacé par instance t avec passage des fonctions de borne */
int * branch_bound(int * tab,int taille){//instance_t * inst,int (*borneInf)(instance_t * inst, int indice)){

     int * curSol = calloc(taille,sizeof(int));
     for(int i = 0;i<4;i++){
            curSol[i] = 0;
     }              
     return branch_bound_rec(tab,curSol,taille,0);         

}
