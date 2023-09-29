#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // int sum = 0;
    const int n = 12;

#pragma omp parallel default(none) shared(n) // reduction(+ : sum)
    {
        int id = omp_get_thread_num();

        int start_idx = id * n / omp_get_num_threads();
        int end_idx = ((id + 1) * n / omp_get_num_threads()) - 1;

        printf("Thread %d tackles index range [%d, %d]\n", id, start_idx, end_idx);

        // for (int i = start_idx; i < end_idx; ++i)
        // {
        //     sum += i + 1;
        // }
    }

    // printf("Sum = %d\n", sum);

    return 0;
}
