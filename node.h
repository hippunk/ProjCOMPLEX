#ifndef NODE_H
#define NODE_H


typedef struct node_s{
    int val;

}node_t;

node_t * nodeCreate();
void nodeInit(node_t * node,int i);
void nodeGen(node_t * node);
void nodePrint(node_t * node);
void nodeDestroy(node_t * node);

#endif



