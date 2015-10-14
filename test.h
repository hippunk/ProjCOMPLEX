#ifndef TEST_H

#define TEST_H
#include <stdio.h>
#include <stdlib.h>
#include "instance.h"
void instance_test();
void johnson_test();
void minAB_test();
void minAB_test_distribNC(int loop,void (*pInstRand)(instance_t * inst));

#endif

