#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include "instance.h"
#include "exacte.h"
#include "algo_approche.h"
#include "bornes.h"



#define INF INT_MAX
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

void branch_bound_rec(instance_t * inst,int * curSol,int curseur,int * tA,int * tB,int* tC,int* bestBorneInf,int* bestBorneSup,instance_t ** solution, int * nodeCount){

    //Debug affichage données noeud courant 
        /*printf("\n\n\nSolution partielle courante : ");
        for(int i = 0;i<curseur;i++){
             if(curSol[i]!=EMPTY){
                  printf("%i ",curSol[i]);
             }
        }
        printf("\n");*/
        //instanceAfficher(inst);
     *nodeCount += 1;
     //Borne inférieur   
     int bi = inf_bMax(inst,*tA,*tB,*tC);
     //Borne supérieur
     instance_t * insttmp = NULL;
     int bs = sup_b1(inst,curseur,&insttmp);
     
     //printf("\tContenu du noeud : tA = %i,tB = %i,tC = %i,borneInf = %i,borneSup %i,best %i\n\n",*tA,*tB,*tC,bi,bs,*bestBorneSup);   
     
     if(*bestBorneSup>bs){
        *bestBorneSup=bs;

     }
     
    if(bi==*bestBorneSup && bi==bs && instanceCout(*solution) != bs){
        //printf("\t\tSSOLUTION\n\n\n");
        if(*solution!=NULL){
        
            instanceDetruire(*solution);}
            //instanceAfficher(inst);
         *solution = instanceCopie(insttmp);
        //Faute de mieux pour l'instant, reconstruction de l'ordre à l'arache.
        //printf("CurSol : ");
        	for(int i = 0;i<curseur;i++){
                (*solution)->ordre[i] = curSol[i];
                //printf(" %i",curSol[i]);
            }
            //printf("\n");
            for(int i = curseur;i<inst->nb_elem;i++){
                (*solution)->ordre[i] = inst->ordre[i];
            }
     }
          
    else if(*bestBorneSup < bi){
       //printf("\t\tCOUPURE\n\n\n");
    }
     else{  

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
		                
                   instanceTachePermuter(inst,curseur,k);     
                   branch_bound_rec(inst,curSol,curseur+1,tA,tB,tC,bestBorneInf,bestBorneSup,solution,nodeCount);
                   instanceTachePermuter(inst,k,curseur); 
                   inst->ordre[k] = tmp;   
                   *tA = tmptA;
                   *tB = tmptB;
                   *tC = tmptC;
                                 
              }
         }
     }
     instanceDetruire(insttmp);
}
/*tab et taille ammenés à être remplacé par instance t avec passage des fonctions de borne */
instance_t * branch_bound(instance_t * inst,int * nodeCount){

     int * curSol = calloc(inst->nb_elem,sizeof(int));
     int * tA = calloc(1,sizeof(int));
     int * tB = calloc(1,sizeof(int));
     int * tC = calloc(1,sizeof(int));
     int * bestBorneInf = calloc(1,sizeof(int));
     int * bestBorneSup = calloc(1,sizeof(int));
     
     *bestBorneSup = INF;
     *bestBorneInf = INF;
     
     instance_t * t = instanceCopie(inst);
     instance_t * solution = instanceCreer(inst->nb_elem,"Propre");
     instanceInit(solution);    
     //instanceAfficher(solution);

     //printf("Démarage : tA = %i,tB = %i,tC = %i,borneInf = %i\n",*tA,*tB,*tC,*bestBorneInf);
     for(int i = 0;i<inst->nb_elem;i++){
            curSol[i] = 0;
     }              
     
     branch_bound_rec(t,curSol,0,tA,tB,tC,bestBorneInf,bestBorneSup,&solution,nodeCount);     
     
     free(tA);
     free(tB);
     free(tC);
     free(curSol);
     free(bestBorneInf); 
     free(bestBorneSup); 
     instanceDetruire(t);
     //printf("Sortie\n");
     return solution;

}
