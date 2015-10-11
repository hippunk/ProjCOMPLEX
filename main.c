#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "instance.h"
#include "algo_approche.h"
#include "test.h"

int main(int argc, char * argv[]){

    srand(time(NULL));
    
    johnson_test();

    return EXIT_SUCCESS;
}
