#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Number of threads in serial region: %d\n", omp_get_num_threads());
    printf("This is thread number: %d\n", omp_get_thread_num());

#pragma omp parallel
    {
#pragma omp critical
        {
            printf("hello from thread %d\n", omp_get_thread_num());
            printf("Number of threads in parallel region: %d\n", omp_get_num_threads());
        }
    }

    printf("Number of threads in serial region: %d\n", omp_get_num_threads());
    printf("This is thread number: %d\n", omp_get_thread_num());

    return 0;
}
