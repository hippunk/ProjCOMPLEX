#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "node.h"

node_t * nodeCreate(){
    node_t * node = malloc(sizeof(node_t)); 
    return node;
}


void nodeInit(node_t * node,int i){
    node->val = i;
}

void nodeGen(node_t * node){
    node->val = 0;
}

void nodePrint(node_t * node){
    printf("Node : %i\n",node->val);
}

void nodeDestroy(node_t * node){
    free(node);
}
