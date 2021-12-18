#include <stdio.h>
#include <omp.h>
using namespace std;

int main() {
    int count = 0;
#pragma omp parallel reduction (+: count)
    {
        count++;
        //printf("Current value count %d\n", count);
    }
    //printf("Number of threads: %d \n", count);
    int A[10], B[10], C[10], i, n;
    int mymass[10];
    int sum = 0;
    for (i = 0; i < 10; i++) {
        A[i] = i;
        B[i] = 2 * i;
        C[i] = 0;
    }
#pragma omp parallel shared(A, B, C) private (i, n)
    {
        n = omp_get_thread_num();

#pragma omp for
        for (i = 0; i < 10; i++) {
            sum += A[i];
            /*C[i] = A[i] + B[i];
            printf("Thread %d summed elements with numbers %d \n", n, i);*/
        }
        //printf("Our sum %d \n", sum);
    }
    printf("Our sum %d \n", sum);
    sum = 0;
#pragma omp parallel shared(mymass, sum) private (i)
    {
#pragma omp parallel reduction (+:sum)
        {
#pragma omp for
            for (i = 0; i < 10; i++) {
                sum += A[i];
                //printf("Current sum value %d \n", sum);
            }
            //printf("Our total sum %d \n", sum);
        }
        //printf("Our total sum %d \n", sum);
    }
    printf("Our total sum %d \n", sum);
    sum = 0;
#pragma omp parallel
    {
        int local_sum = 0;
#pragma omp for
        for (int i = 0; i < 10; i++)
            local_sum += A[i];
#pragma omp atomic
            sum += local_sum;
    };
    printf("Our total sum using atomic %d \n", sum);
    sum = 0;
#pragma omp parallel
    {
#pragma omp for
        for (int i = 0; i < 10; i++)
#pragma omp critical
            sum += A[i];
    }
    printf("Our total sum using critical %d \n", sum);
}

