#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "instance.h"
#include "algo_approche.h"
#include "test.h"
#include "node.h"
#include "tabStack.h"
#include "exacte.h"



int main(int argc, char * argv[]){



    srand(time(NULL));
    
    //stackTest();
    //bench_john_nlogn_vs_n2(100000);
    //Test for BB recursive core
        int tailleTest = 3;
        
        int * tab = calloc(tailleTest,sizeof(int)); 
        for(int i = 0;i<tailleTest;i++){
            tab[i] = i+1;
        }         
         

        printf("\n");
        int * sol = branch_bound(tab,tailleTest);
      
        printf("Solution finale :");
        for(int i = 0;i<tailleTest;i++){
            printf(" %i",sol[i]);
        }           
        printf("\n");
        
        free(sol);
        free(tab);

    //Test chargement enregistrement fichiers        
	    /*instance_t* t = instanceRead("ExempleInstance.txt");
	    
	    instanceAfficher(t);
	    instanceWrite(t,"EnregistrementInstanceTest.txt");
	    instanceDetruire(t);*/
    
    return EXIT_SUCCESS;
}
