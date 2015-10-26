#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include "instance.h"
#include "algo_approche.h"
#include "bornes.h"

#define INF INT_MAX


int sup_b1(instance_t *inst,int curseur,instance_t **result){
     
     *result = johnsonnlogn(inst,curseur);
     //instanceAfficher(*result);
     return instanceCout(*result);

      
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
		//printf("\t\tnb\n");
		//bA
			sum_dA+=inst->A[i];
			if(min_dBC>(inst->B[i]+inst->C[i])){
				min_dBC=(inst->B[i]+inst->C[i]);
			}
		//bB
			sum_dB+=inst->B[i];
			if(min_dC>(inst->C[i])){
				min_dC=(inst->C[i]);
			}
		//bC
			sum_dC+=inst->C[i];
		}		
	}
	
	
	bA=tA+sum_dA+min_dBC;
	bB=tB+sum_dB+min_dC;
	bC=tC+sum_dC;
	//printf("\t\tDebug calcul borne : bA %i,bB %i, bC %i,min_dBC %i,min_dC %i\n",bA,bB,bC,min_dBC,min_dC);
	return max3(bA,bB,bC);
}

	
int inf_b2(instance_t *inst,int tA, int tB, int tC){
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
	
int inf_b3(instance_t *inst,int tA, int tB, int tC){
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
	b1=inf_b1(inst,tA,tB,tC);
	b2=inf_b2(inst,tA,tB,tC);
	b3=inf_b3(inst,tA,tB,tC);
	return max3(b1,b2,b3);
}
