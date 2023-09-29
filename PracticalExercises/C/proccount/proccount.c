/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   %%%%
   %%%% This program file is part of the book and course
   %%%% "Parallel Computing"
   %%%% by Victor Eijkhout, copyright 2013-2022
   %%%%
   %%%% proccount.c : counting procs and threads
   %%%%
   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include <stdio.h>
#include <stdlib.h>

#include "omp.h"

// codesnippet ompproccount
static void nested_report(void)
{
#pragma omp parallel
#pragma omp master
    printf("Nested    : %2d cores and %2d threads out of max %2d\n", omp_get_num_procs(), omp_get_num_threads(),
           omp_get_max_threads());
}
// codesnippet end

int main(void)
{

    printf("Sequential: %2d cores and %2d threads out of max %2d\n", omp_get_num_procs(), omp_get_num_threads(),
           omp_get_max_threads());

    int env_num_threads; // NOLINT

#pragma omp parallel
#pragma omp master
    {
        env_num_threads = omp_get_num_threads(); // NOLINT
        printf("Parallel  : %2d cores and %2d threads out of max %2d\n", omp_get_num_procs(), omp_get_num_threads(),
               omp_get_max_threads());
    }

#pragma omp parallel num_threads(2 * env_num_threads)
#pragma omp master
    {
        printf("Double    : %2d cores and %2d threads out of max %2d\n", omp_get_num_procs(), omp_get_num_threads(),
               omp_get_max_threads());
    }

#pragma omp parallel
#pragma omp master
    nested_report();

    return 0;
}
