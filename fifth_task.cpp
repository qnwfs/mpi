#include <stdio.h>
#include <omp.h>
using namespace std;

int main()
{
    double start_time, end_time, tick;
    int length = 100000;
    int arr1[length], arr2[length], threads;
    for(int i = 0; i < length; i++)
    {
        arr1[i] = i;
        arr2[i] = i;
    }
    for(int number_of_threads = 1; number_of_threads < 11; number_of_threads++)
    {
        int sum = 0;
#pragma omp parallel num_threads(number_of_threads)
        {
            threads = omp_get_num_threads();
            start_time = omp_get_wtime();
            tick = omp_get_wtick();
#pragma omp for
            for (int i = 0; i < length; i++) {
#pragma omp atomic
                sum += arr1[i] * arr2[i];
            }
            end_time = omp_get_wtime();
        }
        printf("Number of threads %d\n", threads);
        printf("Time we used %lf\n", end_time - start_time);
        printf("Our total sum %d \n", sum);
        printf("###############################################################\n");
    }
}
