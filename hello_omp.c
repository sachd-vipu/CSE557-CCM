#include <stdio.h>
#include <omp.h>

int main() {

#pragma omp parallel
{
    int tid, nthreads;

    tid = omp_get_thread_num();
    nthreads = omp_get_num_threads();

    printf("Hello world from thread %3d of %3d\n", tid, nthreads);
}

    return 0;
}
