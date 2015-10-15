#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "tabStack.h"


tabStack_t * tabStackCreate(int s){
    
    
    tabStack_t * stack = malloc(sizeof(tabStack_t)); 
    stack->size = s;
    stack->cursor = -1;
    stack->tab = malloc(sizeof(node_t*)*s);
    
    return stack;
}

node_t * tabStackPop(tabStack_t * stack){
    node_t * node;
    if(stack->cursor == -1){
        printf("tabStackPop : \n\tStack is empty !\n");
        node = NULL;
    }
    else{
        node = stack->tab[stack->cursor--];
    }
    return node;
}

void tabStackPush(tabStack_t * stack,node_t * node){
    if(stack->cursor==stack->size-1){
        printf("tabStackPush : \n\tStack is full !\n");
    }
    else{
        stack->cursor++;
        stack->tab[stack->cursor] = node;
    }
   
}



void tabStackPrint(tabStack_t * stack){
    
    printf("TabStackPrint :\n");
    if(stack->cursor == -1){
        printf("\tStack is empty !\n");
    }
    else{
        for(int i = stack->cursor;i>-1;i--){
            printf("\tNode n°%i\n\t",i);
            nodePrint(stack->tab[i]);
        }
    
    }
}

void tabStackDestroy(tabStack_t * stack){
    free(stack->tab);
    free(stack);
}




