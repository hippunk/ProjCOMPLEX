#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "instance.h"
#include "test.h"

int main(int argc, char * argv[]){
<<<<<<< HEAD
    srand(time(NULL));
    instance_t* inst;
    instance_t* john_inst;
    inst=instanceCreer(10);
    instanceRandNC(inst);
    instanceAfficher(inst);
    john_inst=instanceCreer(inst->nb_elem);
    john_inst=johnson(inst);
    instanceAfficher(john_inst);
    //instanceDetruire(john_inst);
    //instanceDetruire(inst);
=======

    srand(time(NULL));
    
minAB_test();
>>>>>>> ea7dd3603bac24f1f9bcbcbdc070ddd20fb0afd0
    

    
    return EXIT_SUCCESS;
}
