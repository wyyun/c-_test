#include <stdio.h>
#include <omp.h>
#define NUMTHREADS 4
void main(){
    int i;
    float sum =0 ;
omp_set_num_threads(NUMTHREADS);
#pragma omp parallel for private(i) schedule(static, 10000000/4) reduction(+:sum)
    for(i=0;i<10000000;i++)
        sum= sum+1;
    printf("sum=%f\n",sum);
}
