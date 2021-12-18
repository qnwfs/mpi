#include <stdio.h>
#include <omp.h>
#include "math.h"
using namespace std;

int main()
{
    double start_time, end_time, tick;
    int threads;
    int N;
    printf("Enter the necessary number of characters \n");
    scanf("%d", &N);
    double NN = N;
    for(int number_of_threads = 1; number_of_threads < 11; number_of_threads++)
    {
        double pi = 0;
#pragma omp parallel num_threads(number_of_threads)
        {
            threads = omp_get_num_threads();
            start_time = omp_get_wtime();
            tick = omp_get_wtick();
#pragma omp for
            for (int i = 0; i < N-1; i++)
            {
#pragma omp atomic
                pi += 4/(1 + pow(((i+0.5)/NN), 2));
            }
            pi = pi / NN;
            end_time = omp_get_wtime();
        }
        printf("Our Pi-number %f\n", pi);
        printf("Number of threads %d\n", threads);
        printf("Time we used %lf\n", end_time - start_time);
        printf("###############################################################\n");
    }
}

