#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "instance.h"
#include "algo_approche.h"
#include "test.h"
#include "exacte.h"



int main(int argc, char * argv[]){



    srand(time(NULL));
    
    //stackTest();
    //bench_john_nlogn_vs_n2(100000);
    //Test for BB recursive core

        instance_t* t = instanceRead("instanceTest");
        instanceAfficher(t);
        int * sol = branch_bound(t);
      
        printf("Solution finale :");
        for(int i = 0;i<t->nb_elem;i++){
            printf(" %i",sol[i]);
        }           
        printf("\n");
        
        free(sol);
        instanceDetruire(t);

    return EXIT_SUCCESS;
}
