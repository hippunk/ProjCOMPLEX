#include <stdio.h>
#include <stdlib.h>
#include "instance.h"
#include "exacte.h"
#include "algo_approche.h"
#include "bornes.h"

#define EMPTY -1


int nbEmpty(int * tab, int taille){
     int cpt = 0;
	for(int i = 0;i<taille;i++){
	     if(tab[i]!=EMPTY){
	          cpt++;
	     }
	}
	return cpt;
}

void branch_bound_rec(instance_t * inst,int * curSol,int curseur,int * tA,int * tB,int* tC,int* borneInf){

    //Debug affichage données noeud courant 
        printf("Solution partielle courante : ");
        for(int i = 0;i<curseur;i++){
             if(curSol[i]!=EMPTY){
                  printf("%i ",curSol[i]);
             }
        }
        printf("\n");
     *borneInf = inf_b1(inst,*tA,*tB,*tC);
     printf("\tContenu du noeud : tA = %i,tB = %i,tC = %i,borneInf = %i\n\n",*tA,*tB,*tC,*borneInf);

    /*Traitement quand dans une feuille*/
    if(nbEmpty(inst->ordre,inst->nb_elem) == 0){
          //Debug affichage noeud feuille
               /*printf("Solution dans feuille : ");
               for(int i = 0;i<curseur;i++){
                    printf("%i ",curSol[i]);
               }
               printf("\n");*/
     }

     for(int k = 0;k<inst->nb_elem;k++){
         //printf("Empty ? : %i \n",tab[k]);
         if(inst->ordre[k]!=EMPTY){
             //printf("Tab k %i\n",tab[k]);
             //printf("\tProfondeur : %i, tab[k] : %i\n",curseur,tab[k]);
               int tmp = inst->ordre[k];
               //Copie des tX cause de flem réajustement propre pour noeuds frères
                   int tmptA = *tA;
                   int tmptB = *tB;
                   int tmptC = *tC;
               
               inst->ordre[k] = EMPTY;  
               curSol[curseur] = tmp;   

               //Ajustement cout solution partielle
               	    *tA += inst->A[k];
	                if(*tB < *tA){
			            *tB = *tA+inst->B[k];
		            }else{
			            *tB+=inst->B[k];
		            }
	                if(*tC < *tB){
			            *tC = *tB+inst->C[k];
		            }else{
			            *tC+=inst->C[k];
		            }
                    
               branch_bound_rec(inst,curSol,curseur+1,tA,tB,tC,borneInf);
               *tA = tmptA;
               *tB = tmptB;
               *tC = tmptC;
               inst->ordre[k] = tmp;                 
          }
     }
     
     //return curSol; 
}
/*tab et taille ammenés à être remplacé par instance t avec passage des fonctions de borne */
int * branch_bound(instance_t * inst){

     int * curSol = calloc(inst->nb_elem,sizeof(int));
     int * tA = calloc(1,sizeof(int));
     int * tB = calloc(1,sizeof(int));
     int * tC = calloc(1,sizeof(int));
     int * borneInf = calloc(1,sizeof(int));
     
     instance_t * t=instanceCopie(inst);
         

     printf("Démarage : tA = %i,tB = %i,tC = %i,borneInf = %i\n",*tA,*tB,*tC,*borneInf);
     for(int i = 0;i<inst->nb_elem;i++){
            curSol[i] = 0;
     }              
     branch_bound_rec(t,curSol,0,tA,tB,tC,borneInf);     
     
     free(tA);
     free(tB);
     free(tC);

     free(borneInf); 
     return curSol;

}
