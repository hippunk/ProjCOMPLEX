#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "instance.h"
#include "algo_approche.h"
#include "test.h"

double chrono(){

	static struct timeval old;
	struct timeval tmp;
	gettimeofday(&tmp,NULL);
	
	double time = ((double)tmp.tv_sec+(double)tmp.tv_usec/1000000)-((double)old.tv_sec+(double)old.tv_usec/1000000);

	old = tmp;

	return time;
}

int main(int argc, char * argv[]){

    chrono();

    srand(time(NULL));
    //instance_test();

    johnson_test(100000);
    printf("Temps d'execution : %.6f secondes.\n",chrono());
    return EXIT_SUCCESS;
}
