#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "instance.h"
#include "test.h"

int main(int argc, char * argv[]){
    srand(time(NULL));
    
    minAB_test();
    minAB_test_distribNC(10000,instanceRandM);
    
    return EXIT_SUCCESS;
}
