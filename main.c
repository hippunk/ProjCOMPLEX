#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "instance.h"
#include "algo_approche.h"
#include "test.h"
#include "exact.h"

int main(int argc, char * argv[]){



    srand(time(NULL));


    //exactTest(11,200);
            int n1 = 0;
            instance_t* t = instanceCreer(10,"test");
            instanceInit(t); 
            instanceRandNC(t);
            
            //instanceAfficher(t);
          	//instance_t* johnlogn = johnsonnlogn(t,0);
	        //instanceAfficher(johnlogn);
          
            instance_t * sol = branch_bound(t,&n1);
          
            //printf("Solution finale :");
            //instanceAfficher(sol);
            
            instanceDetruire(sol);
             instanceDetruire(t);
    
    return EXIT_SUCCESS;
}
