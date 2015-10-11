#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "instance.h"

int main(int argc, char * argv[]){
    srand(time(NULL));


    instance_t * inst = instanceCreer(10);
    
    instanceRandNC(inst);
    instanceAfficher(inst);
    int i,j;
    int m=minAB(inst,&i,&j);
    printf("\nval = %d, i = %d, j = %d\n",m,i,j);
    //instance_t * copie = instanceCopie(inst);
    //instanceAfficher(copie);
    
    instanceDetruire(inst);
    //instanceDetruire(copie);
	return EXIT_SUCCESS;
}
