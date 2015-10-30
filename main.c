#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "instance.h"
#include "algo_approche.h"
#include "test.h"
#include "exacte.h"

int main(int argc, char * argv[]){



    srand(time(NULL));


    exactTest(11,200);

    
    return EXIT_SUCCESS;
}
