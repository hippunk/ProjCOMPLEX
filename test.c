#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<sys/time.h>
#include"instance.h"
#include"test.h"
#include "exact.h"
#include"algo_approche.h"

double chrono(){

	static struct timeval old;
	struct timeval tmp;
	gettimeofday(&tmp,NULL);
	
	double time = ((double)tmp.tv_sec+(double)tmp.tv_usec/1000000)-((double)old.tv_sec+(double)old.tv_usec/1000000);

	old = tmp;

	return time;
}

void exactTest(int instMax,int loop){
    float c1 = 0.0;
    float c2 = 0.0;
    float c3 = 0.0;
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    
    chrono();
    for(int i = 0;i<instMax;i++){
        for(int j = 0;j<loop;j++){
            instance_t* t = instanceCreer(i,"test");
            instanceInit(t); 
            instanceRandNC(t);
            
            //instanceAfficher(t);
          	//instance_t* johnlogn = johnsonnlogn(t,0);
	        //instanceAfficher(johnlogn);
          
            instance_t * sol = branch_bound(t,&n1);
          
            //printf("Solution finale :");
            //instanceAfficher(sol);
            
            instanceDetruire(sol);
            

            c1 += chrono();
            
            instanceRandDE(t);                      
            sol = branch_bound(t,&n2);                      
            instanceDetruire(sol);
            c2 += chrono();
            
            instanceRandM(t);                      
            sol = branch_bound(t,&n3);                      
            instanceDetruire(sol);
            c3 += chrono();
            
            
            instanceDetruire(t);
            
        }
        printf("%i %.5f %.5f %.5f %i %i %i\n",i,c1/loop,c2/loop,c3/loop,n1/loop,n2/loop,n3/loop);
    }

}

void johnsonTest(int instMax){
  
    float c1 = 0.0;
    float c2 = 0.0;
    float c3 = 0.0;
    float c4 = 0.0;
    float c5 = 0.0;
    float c6 = 0.0;
    for(int i = 0;i<instMax;i+=100){
        instance_t* t = instanceCreer(i,"test");
        instanceInit(t);
 
        instanceRandNC(t);
        
        chrono();  
        instanceDetruire(johnsonnlogn(t,0));
        c1 = chrono();  
        instanceDetruire(johnson(t));
        c2 = chrono();  
        
        instanceRandDE(t);
        chrono();  
        instanceDetruire(johnsonnlogn(t,0));
        c3 = chrono();  
        instanceDetruire(johnson(t));
        c4 = chrono();  
        
        instanceRandM(t);
        
        chrono();  
        instanceDetruire(johnsonnlogn(t,0));
        c5 = chrono();  
        instanceDetruire(johnson(t));
        c6 = chrono();  
        printf("%i %.4f %.4f %.4f %.4f %.4f %.4f\n",i,c2,c1,c4,c3,c6,c5);
        instanceDetruire(t);
    }
}

/*void stackTest(){
    printf("\nTest utilisation et fonctionnement de la pile\n");
    
    //Création de la pile
    printf("\nCréation de la pile\n");
    tabStack_t  * stack;
    stack = tabStackCreate(2);
    tabStackPrint(stack);
        
    //Création de 3 noeuds de test
    printf("\nCréation de 3 noeuds de test\n");
    node_t * node1 = nodeCreate();
    node_t * node2 = nodeCreate();
    node_t * node3 = nodeCreate();
    nodeInit(node1,10);
    nodeInit(node2,20);
    nodeInit(node3,30);
    
    //Déclaration d'un noeud test pour essais sur pop
    printf("\nDéclaration d'un noeud test pour essais sur pop\n");
    node_t * test;
    

    //Affichage des noeuds de test
    printf("\nAffichage des noeuds de test\n");
    nodePrint(node1);
    nodePrint(node2);
    nodePrint(node3);
    
    //Tentative de pop avec pile vide
    printf("\nTentative de pop avec pile vide\n");
    test = tabStackPop(stack);
    
    //Push de 3 nodes
    printf("\nPush de 3 nodes\n");
    tabStackPush(stack,node1);
    tabStackPush(stack,node2);
    tabStackPush(stack,node3); //Le 3eme node ne rentre pas
    
    //Affichage de la pile
    printf("\nAffichage de la pile\n");
    tabStackPrint(stack);
    
    //récupération de la tête
    printf("\nrécupération de la tête\n");
    test = tabStackPop(stack);
    
    //Affichage liste et noeud récupéré
    printf("\nAffichage liste et noeud récupéré\n");
    tabStackPrint(stack);
    nodePrint(test);
    
    //Récupération de la mémoire utilisé
    printf("\nRécupération de la mémoire utilisé\n");
    nodeDestroy(node1);
    nodeDestroy(node2);
    nodeDestroy(node3);
    tabStackDestroy(stack);
}

void nodeMemTest(){
    node_t * node;
    node = nodeCreate();
    nodeInit(node,10);
    nodePrint(node);
    nodeDestroy(node);
}*/

void bench_john_nlogn_vs_n2(int taille){
    
    
    printf("Bench johnson nlogn vs n^2 taille instance : %i\n",taille);
    chrono();
	instance_t* t;
	t=instanceCreer(taille,"Bench");
	instanceRandNC(t);
	//instanceAfficher(t);

	instance_t* johnlogn = johnsonnlogn(t,1);
	//instanceAfficher(johnlogn);
	printf("Temps d'execution nlogn : %.6f secondes.\n",chrono());
	
	instance_t* john = johnson(t);
	//instanceAfficher(john);	
	printf("Temps d'execution n^2 : %.6f secondes.\n",chrono());
	

	instanceDetruire(johnlogn);
	instanceDetruire(john);
	instanceDetruire(t);

}

void instance_test(){
	instance_t* t;
	t=instanceCreer(3,"cout test");
	instanceRandNC(t);
	instanceAfficher(t);
	instanceDetruire(t);
}

void johnson_test(int taille){
    printf("Début test johnson, instance de taille %i\n",taille);
    instance_t* inst;
    instance_t* john_inst;
    printf("Création de l'instance\n");
    inst=instanceCreer(taille,"NC");
    printf("Initialisation de l'instance\n");
    instanceRandNC(inst);
    //instanceAfficher(inst);
    
    printf("Approximation johnson\n");
    john_inst=johnson(inst);
    //instanceAfficher(john_inst);
    
    printf("Destruction instances\n");
    instanceDetruire(john_inst);
    instanceDetruire(inst);
    printf("Fin test\n");
}

void minAB_test(){
    printf("\nTest de la fonction minAB\n");
    printf("Le résultat correspond à la tache la plus courte sur les machines A et B\n");
    instance_t * inst = instanceCreer(10,"Pouet");
    
    instanceRandNC(inst);
    instanceAfficher(inst);
    int i,j;
    int m=minAB(inst,&i,&j);
    printf("\nValeur = %d, Tache n° = %d, Machine = %c\n\n",m,i,'A'+j);

    
    instanceDetruire(inst);
}

void minAB_test_distribNC(int loop,void (*pInstRand)(instance_t * inst)){
    printf("\nTest de la distribution de proba du résultat minAB\n");
    printf("Le résultat correspond à la distribution de proba du résultat de minAB\n");
    instance_t * inst = instanceCreer(10,"Test distrib");
    float cpt1 = 0;
    float cpt2 = 0;
    int i = 0,j = 0;
    for(int cpt = 0;cpt<loop;cpt++){
        pInstRand(inst);
        
        minAB(inst,&i,&j);
        if(j == 0)
            cpt1++;
        else
            cpt2++;
        //printf("Tour %i\n",cpt);
    }

    printf("\nMinimum machine A = %.3f, Minimum machine B = %.3f\n\n",cpt1/loop,cpt2/loop);
    instanceDetruire(inst);
}
