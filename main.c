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

        instance_t* t = instanceRead("ExempleInstance.txt");
        instanceAfficher(t);
      	instance_t* johnlogn = johnsonnlogn(t,0);
	    instanceAfficher(johnlogn);
      
        instance_t * sol = branch_bound(t);
      
        printf("Solution finale :");
        instanceAfficher(sol);
        
        instanceDetruire(sol);
        instanceDetruire(t);
        //instanceDetruire(johnlogn);

    return EXIT_SUCCESS;
}
