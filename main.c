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
    int * tab = calloc(3,sizeof(int)); 
    for(int i = 0;i<3;i++){
        tab[i] = i+1;
    }         
     

    printf("\n");
    int * sol = branch_bound(tab,3);
    
    
    free(sol);
    free(tab);
    return EXIT_SUCCESS;
}
