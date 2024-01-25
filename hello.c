#include <stdio.h>

#ifndef USE_MPI 
#define USE_MPI 0
#else
#define USE_MPI 1
#endif

#ifdef _OPENMP
#include <omp.h>
#endif

#if USE_MPI
#include <mpi.h>
#endif

int main(int argc, char **argv) {


    int rank, nprocs;

#if USE_MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
#else
    rank = 0;
    nprocs = 1;
#endif

#ifdef _OPENMP
#pragma omp parallel
#endif
{
    int tid, nthreads;

#ifdef _OPENMP
    tid = omp_get_thread_num();
    nthreads = omp_get_num_threads();
#else
    tid = 0;
    nthreads = 1;
#endif

    printf("Rank %3d, Hello world from thread %3d of %3d\n", rank, tid, nthreads);
}

#if USE_MPI
    MPI_Finalize();
#endif

    return 0;
}
