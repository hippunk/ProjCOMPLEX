#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#define INF INT_MAX
 
 
int minAB(instance_t *t, int* i, int* j){
	int k;
        int min=INF;
        for(k=0;k<t->nb_elem;k++){
                if(min > t->A[k] && t->A[k] < t->B[k]){
                        min=t->A[k];
                        *i=k;
                        *j=0;
                }else if( min > t->B[k] ){
                        min=t->B[k];
                        *i=k;
                        *j=1;                  
                }
        }
        return min;
}
                               
 
/*instance_t* johnson(instance_t* t){
        gen=instanceCreer(t->nb_elem);
        instanceInit(gen);
        int *X;
        X=malloc(sizeof(int)*t->nb_elem));
        for(i=0;i<t->nb_elem;i++){
                for(j=0;j<t
       
 
int main(){
        int j,i,r;
        instance_t* inst1=malloc(sizeof(instance_t));
	inst1->A=malloc(sizeof(int)*4);
	inst1->B=malloc(sizeof(int)*4);
	inst1->nb_elem=4;
	inst1->A[0]=45;
	inst1->A[1]=9;
	inst1->A[2]=14;
	inst1->A[3]=18;
	inst1->B[0]=98;
	inst1->B[1]=12;
	inst1->B[2]=5;
	inst1->B[3]=18;
        int m=minAB(inst1,&i,&j);
        printf("val = %d, i = %d, j = %d\n",m,i,j);
        return 0;
}*/
