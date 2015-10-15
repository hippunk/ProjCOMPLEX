#ifndef TABSTACK_H
#define TABSTACK_H


typedef struct tabStack_s{
    int cursor;
    int size;
    node_t ** tab;

}tabStack_t;

tabStack_t * tabStackCreate(int s);
void tabStackInit(tabStack_t * stack);
void tabStackPrint(tabStack_t * stack);
void tabStackDestroy(tabStack_t * stack);
node_t * tabStackPop(tabStack_t * stack);
void tabStackPush(tabStack_t * stack,node_t * node);



#endif



