#ifndef TEST_H

#define TEST_H
#include <stdio.h>
#include <stdlib.h>
#include "instance.h"

double chrono();
void bench_john_nlogn_vs_n2(int taille);
void instance_test();
void johnson_test();
void minAB_test();
void minAB_test_distribNC(int loop,void (*pInstRand)(instance_t * inst));

#endif

