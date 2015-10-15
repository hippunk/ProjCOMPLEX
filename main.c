#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "instance.h"
#include "algo_approche.h"
#include "test.h"
#include "node.h"
#include "tabStack.h"



int main(int argc, char * argv[]){



    srand(time(NULL));
    
    stackTest();
    bench_john_nlogn_vs_n2(100000);
    
    
    return EXIT_SUCCESS;
}
