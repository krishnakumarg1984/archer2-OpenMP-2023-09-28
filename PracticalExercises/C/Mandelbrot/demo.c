#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int sum = 0;
    const int n = 5;

#pragma omp parallel for default(none) shared(n) reduction(+ : sum)
    for (int i = 0; i < n; ++i)
    {
        sum += i + 1;
    }

    printf("Sum = %d\n", sum);

    return 0;
}
