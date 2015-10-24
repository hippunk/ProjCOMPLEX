#include <stdio.h>
#include <stdlib.h>
#include "exacte.h"
#include "instance.h"
#include "algo_approche.h"
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
