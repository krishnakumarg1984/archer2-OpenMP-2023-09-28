#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define NPOINTS 2000
#define MAXITER 2000

struct complex
{
    double real;
    double imag;
};

int main(void)
{
    /*
     *  Outer loops run over npoints (for different values of c),
     *  Initialise z=c
     *  Inner loop has the iteration z=z*z+c, and threshold test
     */

    int num_outside = 0;
    struct complex z, c;

    double start = omp_get_wtime();

    for (int i = 0; i < NPOINTS; ++i)
    {
        for (int j = 0; j < NPOINTS; ++j)
        {
            c.real = -2.0 + 2.5 * (double)(i) / (double)(NPOINTS) + 1.0e-7;
            c.imag = 1.125 * (double)(j) / (double)(NPOINTS) + 1.0e-7;

            z = c; // initialise
            for (int iter = 0; iter < MAXITER; ++iter)
            {
                double ztemp = (z.real * z.real) - (z.imag * z.imag) + c.real;
                z.imag = z.real * z.imag * 2.0 + c.imag;
                z.real = ztemp;
                if ((z.real * z.real + z.imag * z.imag) > 4.0e0)
                {
                    ++num_outside;
                    break;
                }
            }
        }
    }

    double finish = omp_get_wtime();

    /*
     *  Calculate area and error and output the results
     */

    double area = 2.0 * 2.5 * 1.125 * (double)(NPOINTS * NPOINTS - num_outside) / (double)(NPOINTS * NPOINTS);
    double error = area / (double)NPOINTS;

    // printf("Area of Mandlebrot set = %12.8f +/- %12.8f\n", area, error);
    printf("Area of Mandlebrot set = %12.8f +/- %e\n", area, error);
    printf("Time = %12.8f seconds\n", finish - start);

    return 0;
}
