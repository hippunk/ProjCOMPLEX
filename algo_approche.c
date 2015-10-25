#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"instance.h"

#define INF INT_MAX
 
void fusion(int **tableau,int deb1,int fin1,int fin2)
{
    int deb2=fin1+1;
    int compt1=deb1;
    int compt2=deb2;
    int i;
    
    int ** table1 = malloc(sizeof(int*)*3);
    for(int i = 0;i<3;i++){
        table1[i] = malloc(sizeof(int)*(fin1-deb1+1));
    }        

        //on recopie les éléments du début du tableau
    for(i=deb1;i<=fin1;i++)
    {
        table1[0][i-deb1]=tableau[0][i];
        table1[1][i-deb1]=tableau[1][i];
        table1[2][i-deb1]=tableau[2][i];
    }
                        
    for(i=deb1;i<=fin2;i++)
        {        
        if (compt1==deb2) //c'est que tous les éléments du premier tableau ont été utilisés
        {
            break; //tous les éléments ont donc été classés
        }
        else if (compt2==(fin2+1)) //c'est que tous les éléments du second tableau ont été utilisés
        {
            tableau[0][i]=table1[0][compt1-deb1]; //on ajoute les éléments restants du premier tableau
            tableau[1][i]=table1[1][compt1-deb1];
            tableau[2][i]=table1[2][compt1-deb1];
            compt1++;
        }
        else if (table1[1][compt1-deb1]<tableau[1][compt2])
        {
            tableau[0][i]=table1[0][compt1-deb1]; //on ajoute un élément du premier tableau
            tableau[1][i]=table1[1][compt1-deb1];
            tableau[2][i]=table1[2][compt1-deb1];
            compt1++;
        }
        else
        {
            tableau[0][i]=tableau[0][compt2]; //on ajoute un élément du second tableau
            tableau[1][i]=tableau[1][compt2];
            tableau[2][i]=tableau[2][compt2];
            compt2++;
        }
    }
    
    for(int i = 0;i<3;i++){
        free(table1[i]); 
    }
    free(table1);
}
        

void tri_fusion_bis(int **tableau,int deb,int fin)
{
    if (deb!=fin)
    {
        int milieu=(fin+deb)/2;
        tri_fusion_bis(tableau,deb,milieu);
        tri_fusion_bis(tableau,milieu+1,fin);
        fusion(tableau,deb,milieu,fin);
    }
}

void fusionSortHard3Tuple(int **tableau,int start,int longueur)
{
    if (longueur-start>0)
    {
        tri_fusion_bis(tableau,start,longueur-1);
    }
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

    int ** tab;
    tab = malloc(sizeof(int*)*3);
    for(int i = 0;i<3;i++){
        tab[i] = malloc(sizeof(int)*inst->nb_elem);
    }
    
	for(int k=0;k<inst->nb_elem;k++){
	    tab[0][k] = k;
        if(inst->A[k] <= inst->B[k]){
            tab[1][k] = inst->A[k];
            tab[2][k] = 0;
        }
        else{
            tab[1][k] = inst->B[k];
            tab[2][k] = 1;
        
        }
	}

	
    return tab;
}

void tabTacheDebug(int** tab,int taille){

	printf("Debug Tab\n");
	for(int k=0;k<taille;k++){
	    printf("tache : %i, val : %i, machine : %c.\n",tab[0][k],tab[1][k],'A'+tab[2][k]);

	}
}

void tabTacheDestruct(int** tab){
    for(int i = 0;i<3;i++){
        free(tab[i]); 
    }
    free(tab);
}
         
instance_t* johnsonnlogn(instance_t* inst,int start){
	int g_pos = 0,d_pos = 0;
	instance_t* t;
	instance_t* new;
	int ** tab;
	
	t=instanceCopie(inst);
	new=instanceCopie(inst);

	tab = tabTacheConstruct(t);
	//tabTacheDebug(tab,t->nb_elem);
	
	fusionSortHard3Tuple(tab,start,t->nb_elem);
	
	//tabTacheDebug(tab,t->nb_elem);
	
	g_pos=start;
	d_pos=t->nb_elem-1;
	
	for(int i=start;i<t->nb_elem;i++){
		

		if(tab[2][i]==0){ //durée de tache min est sur la machine A -> on rajoute en début 
		    new->ordre[g_pos]=tab[0][i];
			new->A[g_pos]=t->A[tab[0][i]];
			new->B[g_pos]=t->B[tab[0][i]];
			new->C[g_pos]=t->C[tab[0][i]];
			g_pos++;
		}else{ //durée de la tache min est sur la machine B -> on rajoute en fin
		    new->ordre[d_pos]=tab[0][i];
			new->A[d_pos]=t->A[tab[0][i]];
			new->B[d_pos]=t->B[tab[0][i]];
			new->C[d_pos]=t->C[tab[0][i]];
			d_pos--;
		}
	}
	
	tabTacheDestruct(tab);
	instanceDetruire(t);
	
	return new;
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
			
