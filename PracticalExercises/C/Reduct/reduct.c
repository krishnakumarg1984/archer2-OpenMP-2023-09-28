#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int tsum = 0;

#pragma omp parallel
    {
        tsum += 1;
    }
    printf("Sum is %d\n", tsum);

    return 0;
}
