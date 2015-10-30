#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "instance.h"
#include "algo_approche.h"
#include "test.h"
#include "exacte.h"

int main(int argc, char * argv[]){



    srand(time(NULL));
    chrono();    
    float c1 = 0.0;
    float c2 = 0.0;
    float c3 = 0.0;
    float c4 = 0.0;
    float c5 = 0.0;
    float c6 = 0.0;

    for(int i = 0;i<1000000;i+=100){
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
    //stackTest();
    //bench_john_nlogn_vs_n2(100000);
    //Test for BB recursive core

       /* instance_t* t = instanceRead("ExempleInstance.txt");
        instanceAfficher(t);
      	//instance_t* johnlogn = johnsonnlogn(t,0);
	    //instanceAfficher(johnlogn);
      
        instance_t * sol = branch_bound(t);
      
        printf("Solution finale :");
        instanceAfficher(sol);
        
        instanceDetruire(sol);
        instanceDetruire(t);
        //instanceDetruire(johnlogn);
    printf("Temps d'execution B&B : %.6f secondes.\n",chrono());*/
    
    return EXIT_SUCCESS;
}
