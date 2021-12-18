#include <stdio.h>
#include <omp.h>
using namespace std;

int main()
{
    double start_time, end_time, tick;
    int length = 100;
    int arr1[length][length], arr2[length][length], arr3[length][length], threads;
    int our_max = 0;
    double time1;
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < length; j++)
        {
            arr1[i][j] = 1;
            arr2[i][j] = 1;
            arr3[i][j] = 0;
        }
    }
    for(int number_of_threads = 1; number_of_threads < 11; number_of_threads++)
    {
        for(int i = 0; i < length; i++)
        {
            for(int j = 0; j < length; j++)
            {
                arr3[i][j] = 0;
            }
        }
#pragma omp parallel num_threads(number_of_threads)
        {
            threads = omp_get_num_threads();
            start_time = omp_get_wtime();
            tick = omp_get_wtick();
#pragma omp for
            for (int i = 0; i < length; i++)
            {
                for (int j = 0; j < length; j++)
                {
                    for(int k = 0; k < length; k++)
                    {
                        arr3[i][j] += arr1[i][k] * arr2[k][j];
                    }
                }
            }
            end_time = omp_get_wtime();
        }
        /*for(int i = 0; i < length; i++)
        {
            for(int j = 0; j < length; j++)
            {
                printf("%d", arr3[i][j]);
            }
            printf("\n");
        }*/
        if(number_of_threads == 1)
        {
            time1 = end_time - start_time;
            printf("Time we used %lf\n", time1);
        }
        else
        {
            printf("Time we used %lf\n", end_time - start_time);
            printf("Our efficiency is %lf\n", time1/(end_time - start_time));
        }
        printf("Number of threads %d\n", threads);
        printf("###############################################################\n");
    }
}
