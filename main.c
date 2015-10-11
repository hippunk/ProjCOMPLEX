#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "instance.h"

int main(int argc, char * argv[]){
    srand(time(NULL));


    instance_t * inst = instanceCreer(10);
    
    instanceRandNC(inst);
    instanceAfficher(inst);
    instance_t * copie = instanceCopie(inst);
    instanceAfficher(copie);
    
    instanceDetruire(inst);
	return EXIT_SUCCESS;
}
