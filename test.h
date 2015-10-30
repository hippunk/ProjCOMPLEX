#ifndef TEST_H

#define TEST_H

double chrono();
void johnsonTest(int instMax);
void exactTest(int instMax,int loop);
void nodeMemTest();
void bench_john_nlogn_vs_n2(int taille);
void instance_test();
void stackTest();
void johnson_test();
void minAB_test();
void minAB_test_distribNC(int loop,void (*pInstRand)(instance_t * inst));

#endif

